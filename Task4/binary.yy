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
  Node root("root");
  int counter = 0;
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
%token <std::string> ELSE
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

%type <Node> chunk
%type <Node> block
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
//%type <Node> binop
//%type <Node> unop

%type <Node> elseifLoop
%type <Node> baseExp
%type <Node> powExp
%type <Node> notHashUnExp
%type <Node> divMulModExp
%type <Node> addSubExp
%type <Node> dotDotExp
%type <Node> compareExp
%type <Node> andExp
%type <Node> orExp

%%

root
  : chunk { root = $1; }
  ;

chunk
  : stat {
      $$ = Node("chunk", "");
      $$.children.push_back($1); }
  | laststat {
      $$ = Node("chunk", "");
      $$.children.push_back($1); }
  | SEMICOLON {
    $$ = Node("chunk", "");
    $$.children.push_back($1); }
  | chunk stat {
      $1.children.push_back($2);
      $$ = $1; }
  | chunk laststat {
      $1.children.push_back($2);
      $$ = $1; }
  | chunk SEMICOLON {
      $1.children.push_back($2);
      $$ = $1; }
  ;

block
  : chunk {
      $$ = Node("block", "");
      $$.children.push_back($1); }
  ;

stat
  : varlist EQUAL explist {
      $$ = Node("stat", "assignment");
      $$.children.push_back($1);
      $$.children.push_back($3); }
  | functioncall { $$ = $1; }
  | DO block END {
      $$ = Node("stat", $1);
      $$.children.push_back($2); }
  | WHILE exp DO block END {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4); }
  | REPEAT block UNTIL exp {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4); }
  | IF exp THEN block END {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4); }
  | IF exp THEN block ELSE block END {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4);
      Node temp = Node("else");
      temp.children.push_back($6);
      $$.children.push_back(temp); }
  | IF exp THEN block elseifLoop END {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4);
      $$.children.push_back($5); }
  | IF exp THEN block elseifLoop ELSE block END {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4);
      $$.children.push_back($5);
      $$.children.push_back($7); }
  | FOR NAME EQUAL exp COMMA exp DO block END {
      $$ = Node("stat", $1);
      $$.children.push_back(Node("name", $2));
      $$.children.push_back($4);
      $$.children.push_back($6);
      $$.children.push_back($8); }
  | FOR namelist IN explist DO block END {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($4);
      $$.children.push_back($6); }
  | FUNCTION funcname funcbody {
      $$ = Node("stat", $1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | LOCAL FUNCTION NAME funcbody {
      $$ = Node("stat", $1 + " " + $2);
      $$.children.push_back(Node("name", $3));
      $$.children.push_back($4); }
  | LOCAL namelist {
      $$ = Node("stat", $1);
      $$.children.push_back($2); }
  ;

elseifLoop
  : ELSEIF exp THEN block {
      $$ = Node("elseifLoop");
      Node temp("elseif");
      temp.children.push_back($2);
      temp.children.push_back($4);
      $$.children.push_back(temp); }
  | elseifLoop ELSEIF exp THEN block {
      Node temp("elseif");
      temp.children.push_back($3);
      temp.children.push_back($5);
      $1.children.push_back(temp);
      $$ = $1; }
  ;

laststat
  : RETURN {
      $$ = Node("laststat", $1);
      $$.children.push_back(Node("RETURN")); }
  | RETURN explist {
      $$ = Node("laststat", $1);
      $$.children.push_back($2); }
  | BREAK { $$ = Node("laststat", $1); }
  ;

funcname
  : NAME { $$ = Node("funcname", $1); }
  | funcname DOT NAME {
      $1.children.push_back(Node("name", $3));
      $$ = $1; }
  | funcname COLON NAME {
      $1.children.push_back(Node("name", $3));
      $$ = $1; }
  ;

varlist
  : var {
      $$ = Node("varlist", "");
      $$.children.push_back($1); }
  | varlist COMMA var {
      $1.children.push_back($3);
      $$ = $1; }
  ;

var
  : NAME { $$ = Node("var", $1); }
  | prefixexp START_SQUARE_BRACKET exp END_SQUARE_BRACKET {
      $$ = Node("var", "");
      $$.children.push_back($1);
      $$.children.push_back($3); }
  | prefixexp DOT NAME {
      $$ = Node("var", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("name", $3)); }
  ;

namelist
  : NAME {
      $$ = Node("namelist", "");
      $$.children.push_back(Node("name", $1)); }
  | namelist COMMA NAME {
      $1.children.push_back(Node("name", $3));
      $$ = $1; }
  ;

explist
  : exp {
      $$ = Node("explist", "");
      $$.children.push_back($1); }
  | explist COMMA exp {
      $1.children.push_back($3);
      $$ = $1; }
  ;

exp
  : orExp { $$ = $1; }
  /*| exp binop exp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }*/
  /*| unop exp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }*/
  ;

orExp
  : andExp { $$ = $1; }
  | orExp OR andExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

andExp
  : compareExp { $$ = $1; }
  | andExp AND compareExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

compareExp
  : dotDotExp { $$ = $1; }
  | compareExp LESS dotDotExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | compareExp BIGGER dotDotExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | compareExp LESSEQUAL dotDotExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | compareExp BIGGEREQUAL dotDotExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | compareExp NOTEQUAL dotDotExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | compareExp EQUAL dotDotExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

dotDotExp
  : addSubExp { $$ = $1; }
  | dotDotExp DOTDOT addSubExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

addSubExp
  : divMulModExp { $$ = $1; }
  | addSubExp PLUS divMulModExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | addSubExp MINUS divMulModExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

divMulModExp
  : notHashUnExp { $$ = $1; }
  | divMulModExp SLASH notHashUnExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | divMulModExp STAR notHashUnExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | divMulModExp PERCENT notHashUnExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

notHashUnExp
  : powExp { $$ = $1; }
  | notHashUnExp NOT powExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | notHashUnExp HASHTAG powExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | MINUS powExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }
  ;

powExp
  : baseExp { $$ = $1; }
  | powExp CARET baseExp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
  ;

baseExp
  : NIL { $$ = Node("exp", $1); }
  | FALSE { $$ = Node("exp", $1); }
  | TRUE { $$ = Node("exp", $1); }
  | NUMBER { $$ = Node("exp", $1); }
  | STR {
      $1.insert(0, "\\");
      $1.insert($1.length() - 1, "\\");
      $$ = Node("exp", $1); }
  | DOTDOTDOT { $$ = Node("exp", $1); }
  | function { $$ = $1; }
  | prefixexp { $$ = $1; }
  | tableconstructor { $$ = $1; }
  ;

prefixexp
  : var { $$ = $1; }
  | functioncall { $$ = $1; }
  | START_PARENTHESES exp END_PARENTHESES { $$ = $2; }
  ;

functioncall
  : prefixexp args {
      $$ = Node("functioncall", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }
  | prefixexp COLON NAME args {
      $$ = Node("functioncall", "");
      $$.children.push_back($1);
      Node temp("name", $3);
      temp.children.push_back(Node($1));
      $$.children.push_back(temp);
      $$.children.push_back($4); }
  ;

args
  : START_PARENTHESES END_PARENTHESES {
      $$ = Node("args", ""); }
  | START_PARENTHESES explist END_PARENTHESES {
      $$ = Node("args", "");
      $$.children.push_back($2); }
  | tableconstructor {
      $$ = Node("args", "");
      $$.children.push_back($1); }
  | STR {
      $1 = $1.substr(1, $1.length() - 2);
      $$ = Node("args", $1); }
  ;

function
  : FUNCTION NAME funcbody {
      $$ = Node("function", "");
      $$.children.push_back(Node($1));
      Node temp("name");
      temp.children.push_back($2);
      $$.children.push_back(temp);
      $$.children.push_back($3); }
  ;

funcbody
  : START_PARENTHESES END_PARENTHESES block END {
      $$ = Node("funcbody", "");
      $$.children.push_back($3); }
  | START_PARENTHESES parlist END_PARENTHESES block END {
      $$ = Node("funcbody", "");
      $$.children.push_back($2);
      $$.children.push_back($4); }
  ;

parlist
  : namelist {
      $$ = Node("parlist", "");
      $$.children.push_back($1); }
  | DOTDOTDOT {
      $$ = Node("parlist", "");
      $$.children.push_back(Node("...")); }
  | namelist COMMA {
      $$ = Node("parlist", "");
      $$.children.push_back($1); }
  | namelist DOTDOTDOT {
      $$ = Node("parlist", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("...")); }
  ;

tableconstructor
  : START_BRACKET END_BRACKET {
      $$ = Node("tableconstructor", ""); }
  | START_BRACKET fieldlist END_BRACKET {
      $$ = Node("tableconstructor", "");
      $$.children.push_back($2); }
  ;

fieldlist
  : field {
      $$ = Node("fieldlist", "");
      $$.children.push_back($1); }
  | field fieldsep {
      $$ = Node("fieldlist", "");
      $$.children.push_back($1);
      //$$.children.push_back($2);
    }
  | fieldlist field {
      $1.children.push_back($2);
      $$ = $1; }
  | fieldlist field fieldsep {
      $1.children.push_back($2);
      //$1.children.push_back($3);
      $$ = $1; }
  ;

field
  : START_SQUARE_BRACKET exp END_SQUARE_BRACKET EQUAL exp {
      $$ = Node("field", "");
      $$.children.push_back($2);
      $$.children.push_back($5); }
  | NAME EQUAL exp {
      $$ = Node("field", "");
      Node temp("name", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp);
      $$.children.push_back(Node($2));
      $$.children.push_back($3); }
  | exp {
      $$ = Node("field", "");
      $$.children.push_back($1); }
  ;

fieldsep
  : COMMA { $$ = Node("fieldsep", $1); }
  | SEMICOLON { $$ = Node("fieldsep", $1); }
  ;

/*
binop
  : CARET { $$ = Node("binop", $1); }
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
*/
