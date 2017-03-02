%top{
	#include "binary.tab.hh"
	#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%

DO|do { return yy::parser::make_DO(yytext); }
END|end { return yy::parser::make_END(yytext); }
WHILE|while { return yy::parser::make_WHILE(yytext); }
UNTIL|until { return yy::parser::make_UNTIL(yytext); }
IF|if  { return yy::parser::make_IF(yytext); }
THEN|then { return yy::parser::make_THEN(yytext); }
ELSEIF|elseif { return yy::parser::make_ELSEIF(yytext); }
ELSE|else { return yy::parser::make_ELSE(yytext); }
FOR|for  { return yy::parser::make_FOR(yytext); }
IN|in { return yy::parser::make_IN(yytext); }
FUNCTION|function { return yy::parser::make_FUNCTION(yytext); }
LOCAL|local { return yy::parser::make_LOCAL(yytext); }
RETURN|return { return yy::parser::make_RETURN(yytext); }
BREAK|break { return yy::parser::make_BREAK(yytext); }
NIL|nil { return yy::parser::make_NIL(yytext); }
FALSE|false { return yy::parser::make_FALSE(yytext); }
TRUE|true { return yy::parser::make_TRUE(yytext); }
AND|and { return yy::parser::make_AND(yytext); }
OR|or { return yy::parser::make_OR(yytext); }
NOT|not { return yy::parser::make_NOT(yytext); }
REPEAT|repeat { return yy::parser::make_REPEAT(yytext); }

[A-Za-z][A-Za-z0-9]* { return yy::parser::make_NAME(yytext); }
'[^']*'|\"[^\"]*\" { return yy::parser::make_STR(yytext); }
[0-9]+|[0-9]+\.[0-9]+ { return yy::parser::make_NUMBER(yytext); }

\[ { return yy::parser::make_START_SQUARE_BRACKET(yytext); }
\] { return yy::parser::make_END_SQUARE_BRACKET(yytext); }
\( { return yy::parser::make_START_PARENTHESES(yytext); }
\) { return yy::parser::make_END_PARENTHESES(yytext); }
\{ { return yy::parser::make_START_BRACKET(yytext); }
\} { return yy::parser::make_END_BRACKET(yytext); }
= { return yy::parser::make_EQUAL(yytext); }
== { return yy::parser::make_EQUALEQUAL(yytext); }
, { return yy::parser::make_COMMA(yytext); }
\n ;
; { return yy::parser::make_SEMICOLON(yytext); }
: { return yy::parser::make_COLON(yytext); }
[ \t] ;
\+ { return yy::parser::make_PLUS(yytext); }
- { return yy::parser::make_MINUS(yytext); }
\* { return yy::parser::make_STAR(yytext); }
\/ { return yy::parser::make_SLASH(yytext); }
\^ { return yy::parser::make_CARET(yytext); }
% { return yy::parser::make_PERCENT(yytext); }
\. { return yy::parser::make_DOT(yytext); }
\.\. { return yy::parser::make_DOTDOT(yytext); }
\.\.\. { return yy::parser::make_DOTDOTDOT(yytext); }
\< { return yy::parser::make_LESS(yytext); }
\<= { return yy::parser::make_LESSEQUAL(yytext); }
\> { return yy::parser::make_BIGGER(yytext); }
\>= { return yy::parser::make_BIGGEREQUAL(yytext); }
~= { return yy::parser::make_NOTEQUAL(yytext); }
# { return yy::parser::make_HASHTAG(yytext); }

<<EOF>>	{ return yy::parser::make_END_OF_FILE(); }
%%
