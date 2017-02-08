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

%token <std::string> NAME
%token <std::string> STR
%token <std::string> NUMBER

%token <std::string> DO
%token <std::string> END
%token <std::string> WHILE
%token <std::string> UNTIL
%token <std::string> IF
%token <std::string> THEN
%token <std::string> ELSEIF
%token <std::string> FOR
%token <std::string> IN
%token <std::string> FUNCTION
%token <std::string> LOCAL
%token <std::string> RETURN
%token <std::string> BREAK
%token <std::string> NIL
%token <std::string> FALSE
%token <std::string> TRUE
%token <std::string> AND
%token <std::string> OR
%token <std::string> NOT
%token <std::string> REPEAT

%token <std::string> START_SQUARE_BRACKET
%token <std::string> END_SQUARE_BRACKET
%token <std::string> START_PARENTHESES
%token <std::string> END_PARENTHESES
%token <std::string> START_BRACKET
%token <std::string> END_BRACKET
%token <std::string> EQUAL
%token <std::string> EQUALEQUAL
%token <std::string> COMMA
%token <std::string> NEWLINE
%token <std::string> SEMICOLON
%token <std::string> COLON
%token <std::string> WHITESPACE
%token <std::string> PLUS
%token <std::string> MINUS
%token <std::string> STAR
%token <std::string> SLASH
%token <std::string> CARET
%token <std::string> PERCENT
%token <std::string> DOT
%token <std::string> DOTDOT
%token <std::string> DOTDOTDOT
%token <std::string> LESS
%token <std::string> LESSEQUAL
%token <std::string> BIGGER
%token <std::string> BIGGEREQUAL
%token <std::string> NOTEQUAL
%token <std::string> HASHTAG

%token END_OF_FILE 0 "end of file"

%type <Node> stream
%type <Node> optline
%type <Node> line
%type <Node> chunk
%type <Node> stat
%type <Node> laststat
%type <Node> funcname
%type <Node> varlist
%type <Node> var
%type <Node> namelist
%type <Node> explist
%type <Node> exp
%type <Node> prefixexp
%type <Node> functioncall
%type <Node> args
%type <Node> function
%type <Node> funcbody
%type <Node> parlist
%type <Node> tableconstructor
%type <Node> fieldlist
%type <Node> field
%type <Node> fieldsep
%type <Node> binop
%type <Node> unop

%type <Node> test

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
  : test { $$ = Node("line", ""); $$.children.push_back($1); }
  | line test { $1.children.push_back($2); $$ = $1; }
  ;

test
: unop { $$ = Node("test", ""); $$.children.push_back($1); }
| test unop { $1.children.push_back($2); $$ = $1; }
| test WHITESPACE unop { $1.children.push_back($3); $$ = $1; }

//| binop { $$ = Node("test", ""); $$.children.push_back($1); }
//| test binop { $1.children.push_back($2); $$ = $1; }
//| test WHITESPACE binop { $1.children.push_back($3); $$ = $1; }

| fieldsep { $$ = Node("test", ""); $$.children.push_back($1); }
| test fieldsep { $1.children.push_back($2); $$ = $1; }
| test WHITESPACE fieldsep { $1.children.push_back($3); $$ = $1; }

| NAME { $$ = Node("test", ""); $$.children.push_back(Node("NAME", $1)); }
| test NAME { $1.children.push_back(Node("NAME", $2)); $$ = $1; }
| test WHITESPACE NAME { $1.children.push_back(Node("NAME", $3)); $$ = $1; }

| STR { $$ = Node("test", ""); $$.children.push_back(Node("STR", $1)); }
| test STR { $1.children.push_back(Node("STR", $2)); $$ = $1; }
| test WHITESPACE STR { $1.children.push_back(Node("STR", $3)); $$ = $1; }

//| NUMBER { $$ = Node("test", ""); $$.children.push_back(Node("NUMBER", $1)); }
//| test NUMBER { $1.children.push_back(Node("NUMBER", $2)); $$ = $1; }
//| test WHITESPACE NUMBER { $1.children.push_back(Node("NUMBER", $3)); $$ = $1; }

| exp { $$ = Node("test", ""); $$.children.push_back($1); }
| test exp { $1.children.push_back($2); $$ = $1; }
| test WHITESPACE exp { $1.children.push_back($3); $$ = $1; }
;

chunk
  : stat SEMICOLON {}
  ;

block
  : chunk {}
  ;

stat
  : varlist EQUAL explist {}
  | functioncall {}
  | DO block END {}
  | WHILE exp DO block END {}
  | REPEAT block UNTIL exp {}
  | IF exp THEN block END{}
  | FOR NAME EQUAL exp COMMA exp DO block END {}
  | FOR namelist IN explist DO block END {}
  | FUNCTION funcname funcbody {}
  | LOCAL FUNCTION NAME funcbody {}
  | LOCAL namelist {}
  ;

laststat
  : RETURN explist {}
  | BREAK {}
  ;

funcname
  : NAME {}
  | funcname DOT NAME {}
  | funcname SEMICOLON NAME {}
  ;

varlist
  : var {}
  | varlist COMMA var {}
  ;

var
  : NAME {}
  | prefixexp {}
  | START_SQUARE_BRACKET exp END_SQUARE_BRACKET {}
  | prefixexp DOT NAME {}
  ;

namelist
  : NAME {}
  | namelist COMMA NAME {}
  ;

explist
  : exp {}
  | explist COMMA exp {}
  ;

exp
  : NIL { $$ = Node("exp", ""); }
  | FALSE { $$ = Node("exp", $1); }
  | TRUE { $$ = Node("exp", $1); }
  | NUMBER { $$ = Node("exp", $1); }
  | STR { $$ = Node("exp", $1); }
  | DOTDOTDOT { $$ = Node("exp", $1); }
  | function { $$ = Node("exp", ""); }
  | prefixexp { $$ = Node("exp", $1.value); }
  | tableconstructor { $$ = Node("exp", ""); $$.children.push_back($1); }
  | exp binop exp {
      $$ = Node("exp", "");
      if      ($2.value == "+") {
        $$.value = std::to_string(std::atoi($1.value.c_str()) + std::atoi($3.value.c_str())); }
      else if ($2.value == "-") {
        $$.value = std::to_string(std::atoi($1.value.c_str()) - std::atoi($3.value.c_str())); }
      else if ($2.value == "/") {
        $$.value = std::to_string(std::atoi($1.value.c_str()) / std::atoi($3.value.c_str())); }
      else if ($2.value == "*") {
        $$.value = std::to_string(std::atoi($1.value.c_str()) * std::atoi($3.value.c_str())); }
  }
  | unop exp { $$ = Node("exp", ""); $$.children.push_back($2); }
  ;

prefixexp
  : var {}
  | functioncall {}
  | START_PARENTHESES exp END_PARENTHESES { $$ = Node("prefixexp", $2.value); }
  ;

functioncall
  : prefixexp args {}
  | prefixexp COLON NAME args {}
  ;

args
  : START_PARENTHESES explist END_PARENTHESES {}
  | functioncall {}
  | START_PARENTHESES exp END_PARENTHESES {}
  ;

function
  : FUNCTION funcbody {}
  ;

funcbody
  : START_PARENTHESES parlist END_PARENTHESES block END {}
  ;

parlist
  : namelist COMMA {}
  | namelist DOTDOTDOT {}
  | DOTDOTDOT {}
  ;

tableconstructor
  : START_SQUARE_BRACKET fieldlist END_SQUARE_BRACKET {}
  ;

fieldlist
  : field fieldsep {}
  | fieldlist field fieldsep {}
  ;

field
  : START_SQUARE_BRACKET exp END_SQUARE_BRACKET EQUAL exp {}
  | NAME EQUAL exp {}
  | exp { $$ = Node("field", $1.value); }
  ;

fieldsep
  : COMMA { $$ = Node("fieldsep", $1); }
  | SEMICOLON { $$ = Node("fieldsep", $1); }
  ;

binop
  : PLUS { $$ = Node("binop", $1); }
  | MINUS { $$ = Node("binop", $1); }
  | STAR { $$ = Node("binop", $1); }
  | SLASH { $$ = Node("binop", $1); }
  | CARET { $$ = Node("binop", $1); }
  | PERCENT { $$ = Node("binop", $1); }
  | DOTDOT { $$ = Node("binop", $1); }
  | LESS { $$ = Node("binop", $1); }
  | LESSEQUAL { $$ = Node("binop", $1); }
  | BIGGER { $$ = Node("binop", $1); }
  | BIGGEREQUAL { $$ = Node("binop", $1); }
  | EQUALEQUAL { $$ = Node("binop", $1); }
  | NOTEQUAL { $$ = Node("binop", $1); }
  | AND { $$ = Node("binop", $1); }
  | OR { $$ = Node("binop", $1); }
  ;

unop
  : MINUS { $$ = Node("unop", $1); }
  | NOT { $$ = Node("unop", $1); }
  | HASHTAG { $$ = Node("unop", $1); }
  ;
