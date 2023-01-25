%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%
"int"                   {printf("Found int\n") ; return yy::parser::make_INT(yytext);}
"["                     {printf("Found [\n") ; return yy::parser::make_LBRACKET(yytext);}
"]"                     {printf("Found ]\n") ; return yy::parser::make_RBRACKET(yytext);}
"boolean"               {printf("Found boolean\n") ; return yy::parser::make_BOOLEAN(yytext);}
";"                     {printf("Found semicolon\n");return yy::parser::make_SEMICOLON(yytext);}
[a-zA-Z][a-zA-Z0-9]*    {printf("Found ID\n;");return yy::parser::make_ID(yytext);}
[ \t\r]+                {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                 return yy::parser::make_END();
%%


