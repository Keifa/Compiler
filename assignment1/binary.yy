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
  /*| NEWLINE {
      $$ = Node("chunk", ""); }
  | stat NEWLINE {
      $$ = Node("chunk", "");
      $$.children.push_back($1); }
  | chunk NEWLINE { $$ = $1; }*/
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
  : RETURN { $$ = Node("laststat", ""); }
  | RETURN explist {
      $$ = Node("laststat", "");
      $$.children.push_back($2); }
  | BREAK {
      $$ = Node("laststat", ""); }
  ;

funcname
  : NAME { $$ = Node("funcname", $1); }
  | funcname DOT NAME {
      $1.children.push_back(Node("funcname DOT NAME", $3));
      $$ = $1; }
  | funcname COLON NAME {
      $1.children.push_back(Node("funcname COLON NAME", $3));
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
  : NAME {
      $$ = Node("var", "");
      $$.children.push_back(Node("name", $1)); }
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
  : NIL { $$ = Node("exp", ""); }
  | FALSE { $$ = Node("exp", $1); }
  | TRUE { $$ = Node("exp", $1); }
  | NUMBER { $$ = Node("exp", $1); }
  | STR { $$ = Node("exp", $1); }
  | DOTDOTDOT { $$ = Node("exp", $1); }
  | function { $$ = $1; }
  | prefixexp { $$ = Node("exp", $1.value); }
  | tableconstructor { $$ = Node("exp", ""); }
  | exp binop exp {
      $$ = Node("exp", "");
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
      $$.children.push_back($2); }
  ;

functioncall
  : prefixexp args {
      $$ = Node("functioncall", "");
      $$.children.push_back($1);
      $$.children.push_back($2); }
  | prefixexp COLON NAME args {
      $$ = Node("functioncall", "");
      $$.children.push_back($1);
      $$.children.push_back(Node("name", $3));
      $$.children.push_back($4); }
  ;

args
  : START_PARENTHESES END_PARENTHESES { $$ = Node("args", ""); }
  | START_PARENTHESES explist END_PARENTHESES {
      $$ = Node("args", "");
      $$.children.push_back($2); }
  | tableconstructor {
      $$ = Node("args", "");
      $$.children.push_back($1); }
  | STR {
      $$ = Node("args", "");
      $$.children.push_back(Node("string", $1)); }
  ;

function
  : FUNCTION NAME funcbody {}

  ;
funcbody
  : START_PARENTHESES END_PARENTHESES block END {}
  | START_PARENTHESES parlist END_PARENTHESES block END {}
  ;

parlist
  : namelist COMMA {}
  | namelist DOTDOTDOT {}
  | DOTDOTDOT {}
  ;

tableconstructor
  : START_SQUARE_BRACKET END_SQUARE_BRACKET {}
  | START_SQUARE_BRACKET fieldlist END_SQUARE_BRACKET {}
  ;

fieldlist
  : field fieldsep {}
  | fieldlist field fieldsep {}
  ;

field
  : START_SQUARE_BRACKET exp END_SQUARE_BRACKET EQUAL exp {
      $$ = Node("field", "");
      $$.children.push_back($2);
      $$.children.push_back($5); }
  | NAME EQUAL exp {
      $$ = Node("field", "");
      $$.children.push_back(Node("name", $1));
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
