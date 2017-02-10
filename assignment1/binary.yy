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
%type <Node> binop
%type <Node> unop

%%

root
  : chunk {
    root.children.push_back($1); }
  ;

chunk
  : stat {
      std::cout << "stat\n";
      $$ = Node("chunk", "");
      $$.children.push_back($1); }
  | stat SEMICOLON {
      std::cout << "stat SEMICOLON\n";
      $$ = Node("chunk", "");
      $$.children.push_back($1);
      $$.children.push_back(Node($2)); }
  | chunk stat {
      std::cout << "chunk stat\n";
      $1.children.push_back($2);
      $$ = $1; }
  | chunk stat SEMICOLON {
      std::cout << "chunk stat SEMICOLON\n";
      $1.children.push_back($2);
      $1.children.push_back(Node($3));
      $$ = $1; }
  | chunk laststat {
      std::cout << "chunk laststat\n";
      $1.children.push_back($2);
      $$ = $1; }
  | chunk laststat SEMICOLON {
      std::cout << "chunk laststat SEMICOLON\n";
      $1.children.push_back($2);
      $1.children.push_back(Node($3));
      $$ = $1; }
  ;

block
  : chunk {
      std::cout << "chunk\n";
      $$ = Node("block", "");
      $$.children.push_back($1); }
  ;

stat
  : varlist EQUAL explist {
      $$ = Node("stat", "");
      $$.children.push_back($1);
      $$.children.push_back(Node($2));
      $$.children.push_back($3); }
  | functioncall {
      $$ = Node("stat", "");
      $$.children.push_back($1); }
  | DO block END {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2);
      $$.children.push_back(Node($3)); }
  | WHILE exp DO block END {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2);
      $$.children.push_back(Node($3));
      $$.children.push_back($4);
      $$.children.push_back(Node($5)); }
  | REPEAT block UNTIL exp {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2);
      $$.children.push_back(Node($3));
      $$.children.push_back($4); }
  | IF exp THEN block END {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2);
      $$.children.push_back(Node($3));
      $$.children.push_back($4);
      $$.children.push_back(Node($5)); }
  | FOR NAME EQUAL exp COMMA exp DO block END {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      Node temp("name");
      temp.children.push_back(Node($2));
      $$.children.push_back(temp);
      $$.children.push_back(Node($3));
      $$.children.push_back($4);
      $$.children.push_back(Node($5));
      $$.children.push_back($6);
      $$.children.push_back(Node($7));
      $$.children.push_back($8);
      $$.children.push_back(Node($9)); }
  | FOR namelist IN explist DO block END {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2);
      $$.children.push_back(Node($3));
      $$.children.push_back($4);
      $$.children.push_back(Node($5));
      $$.children.push_back($6);
      $$.children.push_back(Node($7)); }
  | FUNCTION funcname funcbody {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2);
      $$.children.push_back($3); }
  | LOCAL FUNCTION NAME funcbody {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back(Node($2));
      Node temp("name");
      temp.children.push_back($3);
      $$.children.push_back(temp);
      $$.children.push_back($4); }
  | LOCAL namelist {
      $$ = Node("stat");
      $$.children.push_back(Node($1));
      $$.children.push_back($2); }
  ;

laststat
  : RETURN {
      $$ = Node("laststat", "");
      $$.children.push_back(Node("RETURN")); }
  | RETURN explist {
      $$ = Node("laststat", "");
      $$.children.push_back(Node("RETURN"));
      $$.children.push_back($2); }
  | BREAK {
      $$ = Node("laststat", "");
      $$.children.push_back(Node("BREAK")); }
  ;

funcname
  : NAME {
      $$ = Node("funcname", $1);
      Node temp("name", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp); }
  | funcname DOT NAME {
      $$.children.push_back(Node("."));
      Node temp("name", "");
      temp.children.push_back(Node($3));
      $1.children.push_back(temp);
      $$ = $1; }
  | funcname COLON NAME {
      $1.children.push_back(Node(":"));
      Node temp("name", "");
      temp.children.push_back(Node($3));
      $1.children.push_back(temp);
      $$ = $1; }
  ;

varlist
  : var {
      $$ = Node("varlist", "");
      $$.children.push_back($1); }
  | varlist COMMA var {
      $1.children.push_back(Node(","));
      $1.children.push_back($3);
      $$ = $1; }
  ;

var
  : NAME {
      $$ = Node("var", "");
      Node temp("name", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp); }
  | prefixexp START_SQUARE_BRACKET exp END_SQUARE_BRACKET {
      $$ = Node("var", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("["));
      $$.children.push_back($3);
      $$.children.push_back(Node("]")); }
  | prefixexp DOT NAME {
      $$ = Node("var", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("."));
      Node temp("name", "");
      temp.children.push_back(Node($3));
      $$.children.push_back(temp); }
  ;

namelist
  : NAME {
      $$ = Node("namelist", "");
      Node temp("name", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp); }
  | namelist COMMA NAME {
      $1.children.push_back(Node(","));
      Node temp("name", "");
      temp.children.push_back(Node($3));
      $1.children.push_back(temp);
      $$ = $1; }
  ;

explist
  : exp {
      $$ = Node("explist", "");
      $$.children.push_back($1); }
  | explist COMMA exp {
      $1.children.push_back(Node(","));
      $1.children.push_back($3);
      $$ = $1; }
  ;

exp
  : NIL { $$ = Node("exp", $1); }
  | FALSE {
      $$ = Node("exp", $1); }
  | TRUE {
      $$ = Node("exp", $1); }
  | NUMBER { $$ = Node("exp", $1); }
  | STR {
      $1.erase(0);
      $1.erase($1.length());
      $$ = Node("exp", "string: " + $1); }
  | DOTDOTDOT {
      $$ = Node("exp", $1); }
  | function {
      $$ = Node("exp", "");
      $$.children.push_back($1); }
  | prefixexp {
      $$ = Node("exp", "");
      $$.children.push_back($1); }
  | tableconstructor {
      $$ = Node("exp", "");
      $$.children.push_back($1); }
  | exp binop exp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3);
      if($2.value == "+")
        $$.value = std::to_string(std::strtof($1.value.c_str(), 0) + std::strtof($3.value.c_str(), 0));
      else if ($2.value == "-")
        $$.value = std::to_string(std::strtof($1.value.c_str(), 0) - std::strtof($3.value.c_str(), 0));
      else if ($2.value == "/")
        $$.value = std::to_string(std::strtof($1.value.c_str(), 0) / std::strtof($3.value.c_str(), 0));
      else if ($2.value == "*")
        $$.value = std::to_string(std::strtof($1.value.c_str(), 0) * std::strtof($3.value.c_str(), 0)); }
  | unop exp {
      $$ = Node("exp", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }
  ;

prefixexp
  : var {
      $$ = Node("prefixexp", "");
      $$ .children.push_back($1); }
  | functioncall {
      $$ = Node("prefixexp", "");
      $$.children.push_back($1); }
  | START_PARENTHESES exp END_PARENTHESES {
      $$ = Node("prefixexp", "");
      $$.children.push_back(Node("("));
      $$.children.push_back($2);
      $$.children.push_back(Node(")")); }
  ;

functioncall
  : prefixexp args {
      $$ = Node("functioncall", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }
  | prefixexp COLON NAME args {
      $$ = Node("functioncall", "");
      $$.children.push_back($1);
      $$.children.push_back(Node(":"));
      Node temp("name", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp);
      $$.children.push_back($4); }
  ;

args
  : START_PARENTHESES END_PARENTHESES { $$ = Node("args", "()"); }
  | START_PARENTHESES explist END_PARENTHESES {
      $$ = Node("args", "(explist)");
      $$.children.push_back($2); }
  | tableconstructor {
      $$ = Node("args", "tableconstructor");
      $$.children.push_back($1); }
  | STR {
      $1.erase(0);
      $1.erase($1.length());
      $$ = Node("args", "(" + $1 + ")"); }
  ;

function
  : FUNCTION NAME funcbody {
      $$ = Node("function", "");
      $$.children.push_back(Node($1));
      Node temp("name");
      temp.children.push_back($2);
      $$.children.push_back(temp);
      $$.children.push_back($3);}
  ;

funcbody
  : START_PARENTHESES END_PARENTHESES block END {
      $$ = Node("funcbody", "()");
      $$.children.push_back($3);
      $$.children.push_back(Node("END")); }
  | START_PARENTHESES parlist END_PARENTHESES block END {
      $$ = Node("funcbody", "(parlist)");
      $$.children.push_back($2);
      $$.children.push_back($4);
      $$.children.push_back(Node("END")); }
  ;

parlist
  : namelist COMMA {
      $$ = Node("parlist", "");
      $$.children.push_back($1);
      $$.children.push_back(Node(",")); }
  | namelist DOTDOTDOT {
      $$ = Node("parlist", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("...")); }
  | DOTDOTDOT {
      $$ = Node("parlist", "");
      $$.children.push_back(Node("...")); }
  ;

tableconstructor
  : START_SQUARE_BRACKET END_SQUARE_BRACKET {
      $$ = Node("tableconstructor", "");
      $$.children.push_back(Node("["));
      $$.children.push_back(Node("]")); }
  | START_SQUARE_BRACKET fieldlist END_SQUARE_BRACKET {
      $$ = Node("tableconstructor", "");
      $$.children.push_back(Node("["));
      $$.children.push_back($2);
      $$.children.push_back(Node("]")); }
  ;

fieldlist
  : field fieldsep {
      $$ = Node("fieldlist", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }
  | fieldlist field fieldsep {
      $$ = Node("fieldlist", "");
      $$.children.push_back($1);
      $$.children.push_back($2);
      $$.children.push_back($3); }
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
      $$.children.push_back($3); }
  | exp {
      $$ = Node("field", "");
      $$.children.push_back($1); }
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
