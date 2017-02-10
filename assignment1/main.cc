#include <iostream>
#include <stdio.h>
#include "binary.tab.hh"
#include "Node.h"
extern Node root;
extern FILE *yyin;

void yy::parser::error(std::string const&err) {
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char *argv[]) {

  yyin = fopen(argv[1], "r");
  yy::parser parser;
  if(!parser.parse()) {
    root.dump();
    root.createDotFile();
  }
  return 0;
}
