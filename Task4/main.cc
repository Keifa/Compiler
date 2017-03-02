#include <iostream>
#include <stdio.h>
#include "binary.tab.hh"
#include "Node.h"
#include "labTrees.cc"
extern Node root;
extern FILE *yyin;

void yy::parser::error(std::string const&err) {
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char *argv[]) {
  /*
  yyin = fopen(argv[1], "r");
  yy::parser parser;
  if(!parser.parse()) {
    root.dump();
    root.createDotFile();
  }*/


  /* Test cases
  x = x + 1
  if x == 10
    y = x + 1
  else
    y = x * 2
  x = x + 1
  */
  Statement* test = new Seq({
    new Assignment(
      "x",
      new Add(
        new Variable("x"),
        new Constant(1)
      )
    ),
    new If(
      new Equality(
        new Variable("x"),
        new Constant(10)
      ),
      new Assignment(
        "y",
        new Add(
          new Variable("x"),
          new Constant(1)
        )
      ),
      new Assignment(
        "y",
        new Mult(
          new Variable("x"),
          new Constant(2)
        )
      )
    ),
    new Assignment(
      "x",
      new Add(
        new Variable("x"),
        new Constant(1)
      )
    )
  });

  BBlock* start = new BBlock();

  std::cout << "START\n";

  test->convert(&start);
  dumpCFG(start);

  std::cout << "END\n";
  return 0;
}
