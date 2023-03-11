%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%
"int"                   {return yy::parser::make_INT(yytext);}
"["                     {return yy::parser::make_LBRACKET(yytext);}
"]"                     {return yy::parser::make_RBRACKET(yytext);}
"boolean"               {return yy::parser::make_BOOLEAN(yytext);}
";"                     {return yy::parser::make_SEMICOLON(yytext);}
"true"                  {return yy::parser::make_TRUE(yytext);}
"false"                 {return yy::parser::make_FALSE(yytext);}
"this"                  {return yy::parser::make_THIS(yytext);}
"new"                   {return yy::parser::make_NEW(yytext);}                   
"!"                     {return yy::parser::make_NOT(yytext);}
"("                     {return yy::parser::make_LPAREN(yytext);}
")"                     {return yy::parser::make_RPAREN(yytext);}
"&&"                    {return yy::parser::make_AND(yytext);}
"||"                    {return yy::parser::make_OR(yytext);}
"<"                     {return yy::parser::make_LT(yytext);}
">"                     {return yy::parser::make_GT(yytext);}
"=="                    {return yy::parser::make_EQ(yytext);}
"+"                     {return yy::parser::make_PLUS(yytext);}
"-"                     {return yy::parser::make_MINUS(yytext);}
"*"                     {return yy::parser::make_TIMES(yytext);}
"/"                     {return yy::parser::make_DIVIDE(yytext);}
"."                     {return yy::parser::make_DOT(yytext);}
"length"                {return yy::parser::make_LENGTH(yytext);}
"{"                     {return yy::parser::make_LBRACE(yytext);}
"}"                     {return yy::parser::make_RBRACE(yytext);}
"if"                    {return yy::parser::make_IF(yytext);}
"else"                  {return yy::parser::make_ELSE(yytext);}
"while"                 {return yy::parser::make_WHILE(yytext);}
"System.out.println"    {return yy::parser::make_PRINT(yytext);}
","                     {return yy::parser::make_COMMA(yytext);}
"="                     {return yy::parser::make_EQUALSIGN(yytext);}
"public"                {return yy::parser::make_PUBLIC(yytext);}
"static"                {return yy::parser::make_STATIC(yytext);}
"void"                  {return yy::parser::make_VOID(yytext);}
"main"                  {return yy::parser::make_MAIN(yytext);}
"String"                {return yy::parser::make_STRING(yytext);}
"class"                 {return yy::parser::make_CLASS(yytext);}
"return"                {return yy::parser::make_RETURN(yytext);}
[a-zA-Z][a-zA-Z0-9_]*   {return yy::parser::make_ID(yytext);}
"//".*                  {/* DO NOTHING */ }
0|[1-9][0-9]*           {return yy::parser::make_NUM(yytext);}
[ \t\r]+                {}
.                       { if(!lexical_errors) printf("Lexical errors found! See the logs below: \n"); printf("\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {if(lexical_errors) printf("End of lexical errors\n"); return yy::parser::make_END();}
%%


