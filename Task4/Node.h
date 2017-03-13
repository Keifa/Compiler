
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "labTrees.h"

static int id = 0;

class Node {
public:
  std::string tag, value;
  std::list<Node> children;
  Node(std::string t, std::string v) : tag(std::to_string(id++) + " " + t), value(v) {}
  Node(std::string t) : tag(std::to_string(id++) + " " + t), value("") {}
  Node() { tag="uninitialised"; value="uninitialised"; }

  void dump(int depth=0) {
    for(int i=0; i<depth; i++)
      std::cout << " ";
    std::cout << tag << ":" << value << std::endl;
    for(auto i=children.begin(); i!=children.end(); i++)
      (*i).dump(depth+1);
  }

  void dotFilePrep(std::string& str) {
    for(auto i=children.begin(); i!=children.end(); i++) {
      std::string temp =  '"' + tag + ": " + value + '"';
      temp += " -> ";
      temp += '"' + (*i).tag + ": " + (*i).value + '"' + '\n';
      str += temp;
      (*i).dotFilePrep(str);
    }
  }

  void createDotFile() {
    std::ofstream f;
    std::string str = "digraph G {\n";
    dotFilePrep(str);
    str += "}";

    f.open("parse.txt", std::ofstream::trunc);
    if(f.is_open()) {
      f << str;
      f.close();
    }
  }

  void convertToThreeAd(Statement* state) {
    std::string tempTag = "";
    for(auto i = children.begin(); i != children.end(); i++) {
      tempTag = (*i).tag.substr((*i).tag.find(" ") + 1, (*i).tag.length() - 1);
      std::cout << tempTag << " " << (*i).value << std::endl;

      if(tempTag.find("stat", 0, 4) != string::npos) {
        if((*i).value == "assignment") {
          ((Seq*)state)->l.push_back(handleAssignment((*i)));
        }
      }
      else if(tempTag == "functioncall") {
        ((Seq*)state)->l.push_back(handleFunctionCall((*i)));
      }

      (*i).convertToThreeAd(state);
    }
  }

  Statement* handleFunctionCall(Node& n) {
    auto c = n.children.front();
    auto args = n.children.back();
    if(c.value == "") {

    }
    else if(c.value == "print") {
      if(args.value == "")
        return new Output(handleArgs(args));
      else
        return new Output(new Constant(args.value));
    }
  }

  Expression* handleArgs(Node& n) {
    return handleExptression(n.children.front().children.front());
  }

  Expression* handleExptression(Node& n) {
    std::string tempTag = "";
    tempTag = n.tag.substr(n.tag.find(" ") + 1, n.tag.length() - 1);

    if(tempTag == "exp") {
      if(n.value != "")
        return new Constant(n.value);
      else {
        auto binop = n.children.begin();
        binop++;
        std::string op = (*binop).tag.substr(n.tag.find(" ") + 1, n.tag.length() - 1);

        if(op == "+") {
          return new Add(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "-") {
          return new Sub(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "*") {
          return new Mult(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "/") {
          return new Div(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
      }
    }
    else if(tempTag == "var") {
      return new Variable(n.value);
    }
  }

  Seq* handleAssignment(Node& n) {
    Seq* temp = new Seq();
    auto varList = n.children.front();
    auto expList = n.children.back();
    auto vListIt = varList.children.begin();
    auto eListIt = expList.children.begin();

    if(varList.children.size() == 1) {
      temp->l.push_back(new Assignment((*vListIt).value, handleExptression((*eListIt))));
    }
    else {

    }
    return temp;
  }
};

#endif
