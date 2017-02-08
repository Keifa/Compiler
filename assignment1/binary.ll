%top{ 
	#include "binary.tab.hh"
	#define YY_DECL yy::parser::symbol_type yylex()
} 
%option noyywrap nounput batch noinput
%% 
(([^\n;|=\\$ \t'\"<()\\]*(\\.)?)*)	{ return yy::parser::make_TEXT(yytext); }
[\n] 							{ return yy::parser::make_NEWLINE(yytext); }
[;] 							{ return yy::parser::make_SEMICOLON(yytext); }
[|] 							{ return yy::parser::make_PIPELINE(yytext); }
[ \t] 							{ return yy::parser::make_WHITESPACE(yytext); }
[$][a-zA-Z]+					{ return yy::parser::make_DOLLARSIGN(yytext); }
'[^']*'							{ return yy::parser::make_SINGLEQUOTE(yytext); }
\"(\\.|[^"])*\"					{ return yy::parser::make_DOUBLEQUOTE(yytext); }
[=]								{ return yy::parser::make_EQUAL	(yytext); }
<<EOF>>							{ return yy::parser::make_END(); }
%%