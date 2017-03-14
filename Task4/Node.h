
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
    for(auto i = children.begin(); i != children.end(); i++) {
      ((Seq*)state)->l.push_back(handleStatement((*i)));
    }
  }

  Statement* handleStatement(Node& n) {
    std::cout << "handleStatement\n";
    std::string tempTag = "";
    tempTag = n.tag.substr(n.tag.find(" ") + 1, n.tag.length() - 1);

    if(tempTag.find("stat", 0, 4) != string::npos) {
      if(n.value == "assignment")
        return handleAssignment(n);
      else if(n.value == "if")
        return handleIf(n);
    }
    else if(tempTag == "functioncall")
      return handleStateFunctionCall(n);
  }

  Statement* handleIf(Node& n) {
    std::cout << "handleIf" << n.children.size() << std::endl;
    auto expr = n.children.front();
    auto block1 = n.children.begin();
    block1++;
    if(n.children.size() == 2) {
      return new If(handleExptression(expr), handleBlock((*block1)), new Seq());
    }
    else if(n.children.size() == 3) {
      
    }
    else if(n.children.size() == 4) {

    }
  }

  Statement* handleBlock(Node& n) {
    std::cout << "handleBlock\n";
    Seq* temp = new Seq();
    auto chunk = n.children.front();
    for(auto i = chunk.children.begin(); i != chunk.children.end(); i++) {
      temp->l.push_back(handleStatement((*i)));
    }
    return temp;
  }

  Statement* handleStateFunctionCall(Node& n) {
    std::cout << "handleStateFunctionCall\n";
    auto c = n.children.front();
    auto args = n.children.back();
    if(c.value == "") {
      auto temp = c.children.begin();
      if((*temp).value == "io") {
        temp++;
        if((*temp).value == "write") {
          return new Output(handleArgs(args));
        }
      }
    }
    else if(c.value == "print") {
      if(args.value == "")
        return new Output(handleArgs(args));
      else
        return new Output(new Constant(args.value));
    }
    std::cout << "nullptr\n";
    return nullptr;
  }

  Expression* handleExpFunctionCall(Node& n) {
    std::cout << "handleExpFunctionCall\n";
    auto c = n.children.front();
    auto args = n.children.back();
    if(c.value == "") {
      auto temp = c.children.begin();
      if((*temp).value == "io") {
        temp++;
        if((*temp).value == "read") {
          return new Input(handleArgs(args));
        }
      }
    }
    return nullptr;
  }

  Expression* handleArgs(Node& n) {
    std::cout << "handleArgs\n";
    if(n.children.size() != 0)
      return handleExptression(n.children.front().children.front());
    else
      return new Constant("");
  }

  Expression* handleExptression(Node& n) {
    std::cout << "handleExpression\n";
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
        else if(op == "%") {
          return new Mod(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "==") {
          return new Equality(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "~=") {
          return new NotEqual(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "<") {
          return new Less(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == ">") {
          return new Greater(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == "<=") {
          return new LessOrEqual(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
        else if(op == ">=") {
          return new GreaterOrEqual(
            handleExptression(n.children.front()), handleExptression(n.children.back()));
        }
      }
    }
    else if(tempTag == "var") {
      return new Variable(n.value);
    }
    else if(tempTag == "functioncall") {
      return handleExpFunctionCall(n);
    }
  }

  Seq* handleAssignment(Node& n) {
    std::cout << "handleAssignment\n";
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
