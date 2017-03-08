
#include <iostream>
#include <stdio.h>
#include "labTrees.cc"

int main(int argc, char *argv[]) {
  /*
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

  Statement *test3 = new Seq({
    new Assignment("x", new Add(new Variable("x"), new Constant(1))),

    new If((new Equality(new Variable("x"), new Constant(10))),
    new Assignment("y", new Add(new Variable("x"), new Constant(1))),
    new Assignment("y", new Mult(new Variable("x"),new Constant(2)))),

    new Assignment("x", new Add(new Variable("x"), new Constant(1)))
});

  BBlock* start = new BBlock();
  BBlock* tempStart = start;
  test3->convert(&tempStart);
  dumpCFG(start);
  generateDotFile(start);

  return 0;
}
