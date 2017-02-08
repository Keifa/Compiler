%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include "Node.h"
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  using namespace std;
  Node root;
}

%token <std::string> TEXT
%token <std::string> NEWLINE
%token <std::string> SEMICOLON
%token <std::string> PIPELINE
%token <std::string> WHITESPACE
%token <std::string> DOLLARSIGN
%token <std::string> SINGLEQUOTE
%token <std::string> DOUBLEQUOTE
%token <std::string> EQUAL
%type <Node> optline
%type <Node> line
%type <Node> anything
%type <Node> stream
%type <Node> pipe
%type <Node> concat
%type <Node> command
%type <Node> equal

%token END 0 "end of file"
%%

stream
  : optline {
      $$ = Node("stream", "");
      $$.children.push_back($1);
      root = $$; }
  | stream NEWLINE optline { root.children.push_back($3); }
  ;

optline
  : { $$ = Node("optline", "empty"); }
  | line {
      $$ = Node("optline", "has line");
      $$.children.push_back($1); }
  ;

line
  : pipe { $$ = $1; }
  | line SEMICOLON pipe {
      $$ = Node("line", "");
      $$.children.push_back($1);
      $$.children.push_back($3); }
  ;

pipe
  : equal { $$ = $1; }
  | pipe PIPELINE equal {
      $$ = Node("pipeline", "");
      $$.children.push_back($1);
      $$.children.push_back($3); }
  ;

equal
  : command { $$ = $1; }
  | anything EQUAL concat WHITESPACE equal {
      $$ = Node("equal", "");
      $$.children.push_back($1);
      $$.children.push_back($3);
      $$.children.push_back($5); }
  ;

command
  : concat { $$ = $1; }
  | command WHITESPACE concat {
      $$ = Node("command", "");
      $$.children.push_back($1);
      $$.children.push_back($3); }
  ;

concat
  : anything { $$ = $1; }
  | concat anything {
      if($1.children.size() == 0) {
        $$ = Node("concat", "");
        $$.children.push_back($1);
        $$.children.push_back($2);
      }
      else {
        $1.children.push_back($2);
        $$ = $1;
      }}
  ;

anything
  : TEXT     { $$ = Node("WORD",   $1); }
  | DOLLARSIGN    { $$ = Node("VAREXP", $1); }
  | SINGLEQUOTE   { $$ = Node("SQUOTE", $1); }
  | DOUBLEQUOTE   { $$ = Node("DQUOTE", $1); }
  | EQUAL         { $$ = Node("EQUAL",  $1); }
  ;
