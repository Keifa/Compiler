#include <iostream>
#include <stdio.h>
#include "binary.tab.hh"
#include "Node.h"

extern Node root;
extern FILE *yyin;

void yy::parser::error(std::string const&err) {
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

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

void generateCFGDotFile(BBlock* start) {
  string dotNodeStr = "", dotNodeConStr = "";
  start->dotFile(dotNodeStr, dotNodeConStr);

  dotNodeStr.insert(0, "digraph structs {\n");
  dotNodeConStr += "}";

  //cout << dotNodeStr << dotNodeConStr << endl;
  ofstream file("cfg.dot", ios::trunc);
  if(file.is_open()) {
   file << dotNodeStr;
   file << dotNodeConStr;
   file.close();
  }
  else { cout << "Unable to open file\n"; }
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  yy::parser parser;
  BBlock* start = new BBlock();
  BBlock* tempStart = start;
  Statement* state = new Seq();

  if(!parser.parse()) {
    std::cout << "ParseTree:\n";
    root.dump();
    root.createDotFile();
    root.convertToThreeAd(state);
    state->convert(&tempStart);
    std::cout << "\nCFG:\n";
    dumpCFG(start);
    generateCFGDotFile(start);
  }
  return 0;
}
