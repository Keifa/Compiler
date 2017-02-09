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

chunk
  : stat {
      $$ = Node("chunk", "");
      $$.children.push_back($1);
      root = $$; }
  | stat SEMICOLON {
      $$ = Node("chunk", "");
      $$.children.push_back($1);
      root = $$; }
  | chunk stat {
      $1.children.push_back($2);
      $$ = $1; }
  | chunk stat SEMICOLON {
      $1.children.push_back($2);
      $$ = $1; }
  | chunk laststat {
      $1.children.push_back($2);
      $$ = $1;}
  | chunk laststat SEMICOLON {
      $1.children.push_back($2);
      $$ = $1; }
  | NEWLINE {
      $$ = Node("chunk", ""); }
  | stat NEWLINE {
      $$ = Node("chunk", "");
      $$.children.push_back($1); }
  | chunk NEWLINE { $$ = $1; }
  ;

block
  : chunk {
      $$ = Node("block", "");
      $$.children.push_back($1);
      //root = $$;
    }
  /*| block chunk {
      $1.children.push_back($2);
      $$ = $1; }*/
  ;

stat
  : varlist EQUAL explist {
      $$ = Node("stat", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("="));
      $$.children.push_back($3); }
  | functioncall {
      $$ = Node("stat", "");
      $$.children.push_back($1); }
  | DO block END { }
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
  : NIL {
      $$ = Node("exp", $1);
      $$.children.push_back(Node("NIL")); }
  | FALSE {
      $$ = Node("exp", $1);
      $$.children.push_back(Node("FALSE")); }
  | TRUE {
      $$ = Node("exp", $1);
      $$.children.push_back(Node("TRUE")); }
  | NUMBER {
      $$ = Node("exp", $1);
      Node temp("number", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp); }
  | STR {
      $$ = Node("exp", $1);
      Node temp("string", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp); }
  | DOTDOTDOT {
      $$ = Node("exp", $1);
      $$.children.push_back(Node("...")); }
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
        $$.value = std::to_string(std::atoi($1.value.c_str()) + std::atoi($3.value.c_str()));
      else if ($2.value == "-")
        $$.value = std::to_string(std::atoi($1.value.c_str()) - std::atoi($3.value.c_str()));
      else if ($2.value == "/")
        $$.value = std::to_string(std::atoi($1.value.c_str()) / std::atoi($3.value.c_str()));
      else if ($2.value == "*")
        $$.value = std::to_string(std::atoi($1.value.c_str()) * std::atoi($3.value.c_str()));
  }
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
  : START_PARENTHESES END_PARENTHESES {
      $$ = Node("args", "");
      $$.children.push_back(Node("("));
      $$.children.push_back(Node(")"));}
  | START_PARENTHESES explist END_PARENTHESES {
      $$ = Node("args", "");
      $$.children.push_back(Node("("));
      $$.children.push_back($2);
      $$.children.push_back(Node(")")); }
  | tableconstructor {
      $$ = Node("args", "");
      $$.children.push_back($1); }
  | STR {
      $$ = Node("args", "");
      Node temp("str", "");
      temp.children.push_back(Node($1));
      $$.children.push_back(temp); }
  ;

function
  : FUNCTION NAME funcbody {}

  ;
funcbody
  : START_PARENTHESES END_PARENTHESES block END {}
  | START_PARENTHESES parlist END_PARENTHESES block END {}
  ;

parlist
  : namelist COMMA {
      $$ = Node("parlist", "");
      $$.children.push_back($1);
      $$.children.push_back(Node(","));
  }
  | namelist DOTDOTDOT {
      $$ = Node("parlist", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("..."));
  }
  | DOTDOTDOT {
      $$ = Node("parlist", "");
      $$.children.push_back(Node("..."));}
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
  : COMMA { $$ = Node("fieldsep", $1); $$.children.push_back(Node(","));}
  | SEMICOLON { $$ = Node("fieldsep", $1); $$.children.push_back(Node(";")); }
  ;

binop
  : PLUS { $$ = Node("binop", $1); $$.children.push_back(Node("+")); }
  | MINUS { $$ = Node("binop", $1); $$.children.push_back(Node("-")); }
  | STAR { $$ = Node("binop", $1); $$.children.push_back(Node("*")); }
  | SLASH { $$ = Node("binop", $1); $$.children.push_back(Node("/")); }
  | CARET { $$ = Node("binop", $1); $$.children.push_back(Node("^")); }
  | PERCENT { $$ = Node("binop", $1); $$.children.push_back(Node("%")); }
  | DOTDOT { $$ = Node("binop", $1); $$.children.push_back(Node("..")); }
  | LESS { $$ = Node("binop", $1); $$.children.push_back(Node("<")); }
  | LESSEQUAL { $$ = Node("binop", $1); $$.children.push_back(Node("<=")); }
  | BIGGER { $$ = Node("binop", $1); $$.children.push_back(Node(">")); }
  | BIGGEREQUAL { $$ = Node("binop", $1); $$.children.push_back(Node(">=")); }
  | EQUALEQUAL { $$ = Node("binop", $1); $$.children.push_back(Node("==")); }
  | NOTEQUAL { $$ = Node("binop", $1); $$.children.push_back(Node("~=")); }
  | AND { $$ = Node("binop", $1); $$.children.push_back(Node("AND"));}
  | OR { $$ = Node("binop", $1); $$.children.push_back(Node("OR"));}
  ;

unop
  : MINUS { $$ = Node("unop", $1); $$.children.push_back(Node("-")); }
  | NOT { $$ = Node("unop", $1); $$.children.push_back(Node("NOT")); }
  | HASHTAG { $$ = Node("unop", $1); $$.children.push_back(Node("#")); }
  ;
