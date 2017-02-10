
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>

class Node {
public:
  std::string tag, value;
  std::list<Node> children;
  Node(std::string t, std::string v) : tag(t), value(v) {}
  Node(std::string t) : tag(t), value("") {}
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
      std::string temp = '"' + tag + ' ' + value + '"' + " -> " + '"' + (*i).tag + ' ' + (*i).value + '"' + '\n';
      if(str.find(temp) == -1) {
        str += temp;
      }
      (*i).dotFilePrep(str);
    }
  }

  void createDotFile() {
    std::ofstream f;
    std::string str = "digraph G {\n";

    f.open("parse.txt", std::ofstream::trunc);
    if(f.is_open()) {
      dotFilePrep(str);
      str += "}";
      f << str;
      f.close();
    }
  }
};

#endif
