/* DV1465 / DV1505 / DV1511 Lab-task example code.
   (C) Dr Andrew Moss, Erik Bergenholtz  2016, 2017
   This code is released into the public domain.

   You are free to use this code as a base for your second assignment after
   the lab sessions (it is not required that you do so).
*/
#include <list>
#include <set>
#include <initializer_list>
#include <string>
#include <iostream>

using namespace std;

/************* Three Address Instructions *************/
class ThreeAd {
public:
  string name,lhs,rhs;
  char op;

  ThreeAd(string name, char op, string lhs, string rhs) :
    name(name), op(op), lhs(lhs), rhs(rhs) {}

  void dump() {
    cout << name << " <- ";
    cout << lhs << " " << op << " " << rhs << endl;
  }
};


/* Basic Blocks */
class BBlock {
private:
  static int nCounter;
public:
  list<ThreeAd> instructions;
  BBlock *tExit, *fExit;
  string name;

  BBlock() :
    tExit(NULL), fExit(NULL), name("blk" + to_string(nCounter++)) {}

  void dump() {
    cout << "BBlock @ " << this << endl;
    cout << name << endl;
    for(auto i : instructions)
      i.dump();
    cout << "True:  " << tExit << endl;
    cout << "False: " << fExit << endl << endl;
  }
};
int BBlock::nCounter = 0;


/******************** Expressions ********************/
class Expression {
private:
  static int counter;
public:
  string name;
  Expression() : name("") {}
  Expression(string name) : name(name) {}

  virtual string makeNames() {
    // Lecture 8 / slide 11.
    // Virtual (but not pure) to allow overriding in the leaves.
    name = "_t" + to_string(counter++);
    return name;
  }

  virtual string convert(BBlock*) = 0; // Lecture 8 / slide 12.
};
int Expression::counter = 0;

class Variable : public Expression {
public:
  Variable(string name) : Expression(name) {}

  string makeNames() {
    return name;
  }

  string convert(BBlock* out) {
    // Write three address instructions to output
    //cout << "Variable\n";
    return name;
  }
};

class Constant : public Expression {
public:
  Constant(int nr) :
    Expression(to_string(nr)) {}

  string makeNames() {
    return name;
  }

  string convert(BBlock* out) {
    // Write three address instructions to output
    //cout << "Constant\n";
    return name;
  }
};

class Add : public Expression {
public:
  Expression *lhs, *rhs;

  Add(Expression* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  string convert(BBlock* out) {
    //cout << "Add\n";
    out->instructions.push_back(ThreeAd(makeNames(), '+', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Mult : public Expression {
public:
  Expression *lhs, *rhs;

  Mult(Expression* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  string convert(BBlock* out) {
    //cout << "Mult\n";
    out->instructions.push_back(ThreeAd(makeNames(), '*', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Equality : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  Equality(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    //cout << "Equality\n";
    out->instructions.push_back(ThreeAd(makeNames(), 'e', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};


/******************** Statements ********************/
class Statement {
public:
  string name;
  Statement() {}
  virtual void convert(BBlock **) = 0;
};

class Assignment : public Statement {
public:
  Variable *lhs;
  Expression *rhs;

  Assignment(string lhs, Expression *rhs) :
    lhs(new Variable(lhs)), rhs(rhs) {}

  void convert(BBlock **out) {
    // Write three address instructions to output
    //cout << "Assignment " << lhs->name << endl;
    string temp = rhs->convert(*out);
    (*out)->instructions.push_back(ThreeAd(lhs->convert(*out), '=', temp, temp));
  }
};

class If : public Statement {
public:
  Expression *expr;
  Statement *tState, *fState;

  If(Expression* expr, Statement* tState, Statement* fState) :
    expr(expr), tState(tState), fState(fState) {}

  void convert(BBlock **out) {
    expr->convert(*out);

    BBlock* contBlock = new BBlock();

    // True
    BBlock* trueBlock = new BBlock();
    (*out)->tExit = trueBlock;
    tState->convert(&trueBlock);
    trueBlock->tExit = contBlock;


    // False
    BBlock* falseBlock = new BBlock();
    (*out)->fExit = falseBlock;
    fState->convert(&falseBlock);
    falseBlock->tExit = contBlock;


    (*out) = contBlock;
  }
};

class Seq : public Statement {
public:
  list<Statement*> l;
  Seq(initializer_list<Statement*> args) {
    for(auto i : args)
      l.push_back(i);
  }

  void convert(BBlock **out) {
    // Write three address instructions to output
    for(auto i : l)
      i->convert(out);
  }
};

/*
 * Iterate over each basic block that can be reached from the entry point
 * exactly once, so that we can dump out the entire graph.
 */
void dumpCFG(BBlock *start) {
  set<BBlock *> done, todo;
  todo.insert(start);
  while(todo.size() > 0) {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    next->dump();
    done.insert(next);
    if(next->tExit != NULL && done.find(next->tExit) == done.end())
      todo.insert(next->tExit);
    if(next->fExit != NULL && done.find(next->fExit) == done.end())
      todo.insert(next->fExit);
  }
}
