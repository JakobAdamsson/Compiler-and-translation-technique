%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%
"public"                {return yy::parser::make_PUBLIC(yytext);}
"class"                 {return yy::parser::make_CLASS(yytext);}
"{"                     {return yy::parser::make_LBRACE(yytext);}
"}"                     {return yy::parser::make_RBRACE(yytext);}
"void"                  {return yy::parser::make_VOID(yytext);}
"main"                  {return yy::parser::make_MAIN(yytext);}
"("                     {return yy::parser::make_LPAREN(yytext);}
")"                     {return yy::parser::make_RPAREN(yytext);}
"String"                {return yy::parser::make_STRING(yytext);}
"["                     {return yy::parser::make_LBRACKET(yytext);}
"]"                     {return yy::parser::make_RBRACKET(yytext);}
"static"                {return yy::parser::make_STATIC(yytext);}
[a-zA-Z]*[a-zA-Z0-9]*   {return yy::parser::make_ID(yytext);}

[ \t\r]+                {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                 return yy::parser::make_END();
%%


