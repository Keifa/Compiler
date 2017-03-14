/* DV1465 / DV1505 / DV1511 Lab-task example code.
   (C) Dr Andrew Moss, Erik Bergenholtz  2016, 2017
   This code is released into the public domain.

   You are free to use this code as a base for your second assignment after
   the lab sessions (it is not required that you do so).
*/

#ifndef LABTREES_CC
#define LABTREES_CC

#include <list>
#include <set>
#include <initializer_list>
#include <string>
#include <iostream>
#include <fstream>

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

  string toStr() {
    return (name + " \\<\\- " + lhs + " " + op + " " + rhs);
  }
};

/* Basic Blocks */
static int nCounter = 0;
class BBlock {
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

  void dotFile(string& nodeStr, string& conStr) {
    nodeStr += name + " [label=\"";

    for(auto i : instructions)
      nodeStr += i.toStr() + "\\n";

    nodeStr += "\",shape=\"rect\"];\n";

    if(tExit != NULL) {
      string temp = name + " -> " + tExit->name + " [label=\"true\",color=\"green\"];\n";
      if(conStr.find(temp) == string::npos)
        conStr += temp;
      tExit->dotFile(nodeStr, conStr);
    }

    if(fExit != NULL) {
      string temp = name + " -> " + fExit->name + " [label=\"false\",color=\"red\"];\n";
      if(conStr.find(temp) == string::npos)
        conStr += temp;
      fExit->dotFile(nodeStr, conStr);
    }
  }
};
//int BBlock::nCounter = 0;

/******************** Expressions ********************/
static int eCounter = 0;
class Expression {
public:
  string name;
  Expression() : name("") {}
  Expression(string name) : name(name) {}

  virtual string makeNames() {
    // Lecture 8 / slide 11.
    // Virtual (but not pure) to allow overriding in the leaves.
    name = "_t" + to_string(eCounter++);
    return name;
  }

  virtual string convert(BBlock*) = 0; // Lecture 8 / slide 12.
};
//int Expression::eCounter = 0;

class Variable : public Expression {
public:
  Variable(string name) : Expression(name) {}

  string makeNames() {
    return name;
  }

  string convert(BBlock* out) {
    // Write three address instructions to output
    return name;
  }
};

class Constant : public Expression {
public:
  Constant(int nr) :
    Expression(to_string(nr)) {}
  Constant(string str) :
    Expression(str) {}

  string makeNames() {
    return name;
  }

  string convert(BBlock* out) {
    // Write three address instructions to output
    return name;
  }
};

class Add : public Expression {
public:
  Expression *lhs, *rhs;

  Add(Expression* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '+', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Sub : public Expression {
public:
  Expression *lhs, *rhs;

  Sub(Expression* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '-', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Mult : public Expression {
public:
  Expression *lhs, *rhs;

  Mult(Expression* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '*', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Div : public Expression {
public:
  Expression *lhs, *rhs;

  Div(Expression* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '/', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Mod : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  Mod(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '%', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Equality : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  Equality(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), 'e', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class NotEqual : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  NotEqual(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '!', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Less : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  Less(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '<', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Greater : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  Greater(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), '>', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class LessOrEqual : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  LessOrEqual(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), 'l', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class GreaterOrEqual : public Expression {
public:
  Expression *lhs;
  Expression *rhs;

  GreaterOrEqual(Expression* lhs, Expression* rhs) : lhs(lhs), rhs(rhs){}

  string convert(BBlock* out) {
    out->instructions.push_back(ThreeAd(makeNames(), 'g', lhs->convert(out), rhs->convert(out)));
    return name;
  }
};

class Input : public Expression {
public:
  Expression* args;

  Input(Expression* args) : args(args) {}

  string convert(BBlock* out) {
    string temp = args->convert(out);
    out->instructions.push_back(ThreeAd(makeNames(), 'i', temp, temp));
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
  Assignment(Variable* lhs, Expression* rhs) :
    lhs(lhs), rhs(rhs) {}

  void convert(BBlock **out) {
    // Write three address instructions to output
    string temp = rhs->convert(*out);
    (*out)->instructions.push_back(ThreeAd(lhs->convert(*out), '=', temp, temp));
  }
};

class Output : public Statement {
public:
  Expression* exp;
  Output() {}
  Output(Expression* exp) : exp(exp) {}

  void convert(BBlock **out) {
    string temp = exp->convert(*out);
    (*out)->instructions.push_back(ThreeAd("output", 'o', temp, temp));
  }
};

class Seq : public Statement {
public:
  list<Statement*> l;
  Seq() {}
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

class If : public Statement {
public:
  Expression *expr;
  Statement *tState, *fState;

  If(Expression* expr, Statement* tState, Statement* fState) :
    expr(expr), tState(tState), fState(fState) {}
  If(Expression* expr, Statement* tState) :
    expr(expr), tState(tState), fState(new Seq()) {}

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

class For : public Statement {
public:

  For() {}

  void convert(BBlock ** out) {

  }
};

/*
 * Iterate over each basic block that can be reached from the entry point
 * exactly once, so that we can dump out the entire graph.
 */
/*
void dumpCFG(BBlock* start) {
  set<BBlock*> done, todo;
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

void generateDotFile(BBlock* start) {
  string dotNodeStr = "", dotNodeConStr = "";
  start->dotFile(dotNodeStr, dotNodeConStr);

  dotNodeStr.insert(0, "digraph structs {\n");
  dotNodeConStr += "}";

  cout << dotNodeStr << dotNodeConStr << endl;
  ofstream file("cfg.dot", ios::trunc);
  if(file.is_open()) {
   file << dotNodeStr;
   file << dotNodeConStr;
   file.close();
  }
  else { cout << "Unable to open file\n"; }
}
*/

#endif
