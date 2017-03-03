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
  Statement* test1 = new Seq({
    new Assignment(
      "x",
      new Add(
        new Variable("x"),
        new Constant(1))),
    new If(
      new Equality(
        new Variable("x"),
        new Constant(10)),
      new Assignment(
        "y",
        new Add(
          new Variable("x"),
          new Constant(1))),
      new Assignment(
        "y",
        new Mult(
          new Variable("x"),
          new Constant(2)))),
    new Assignment(
      "x",
      new Add(
        new Variable("x"),
        new Constant(1)))
  });

  /*
  x = x + 1
  y = y + 1
  if x == 0
    if y == 0
      x = 1
    else
     y = 2
  else
    y = 3
   */
  Statement* test2 = new Seq({
    new Assignment(
      "x",
      new Add(
        new Variable("x"),
        new Constant(1))),
    new Assignment(
      "y",
      new Add(
        new Variable("y"),
        new Constant(1))),
    new If(
      new Equality(
        new Variable("x"),
        new Constant(0)),
      new If(
        new Equality(
          new Variable("y"),
          new Constant(0)),
        new Assignment(
          "x",
          new Constant(1)),
        new Assignment(
          "y",
          new Constant(2))),
      new Assignment(
        "y",
        new Constant(3)))
  });

  BBlock* start = new BBlock();
  BBlock* tempStart = start;
  test2->convert(&tempStart);
  dumpCFG(start);

  long x=10,y=0,_t0=17,_t1=17,_t2=17,_t3=17,_t4=17;


  return 0;
}
