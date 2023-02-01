/*
Authors:
Jakob Adamsson(jaad19)
Emil Gullbrandsson(emgb20)


This file is a part of the course DV1655 Compiler and translation techniques at BTH.
*/
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
"true"                  {printf("Found true\n");return yy::parser::make_TRUE(yytext);}
"false"                 {printf("Found false\n");return yy::parser::make_FALSE(yytext);}
"this"                  {printf("Found this\n");return yy::parser::make_THIS(yytext);}
"new"                   {printf("Found new\n");return yy::parser::make_NEW(yytext);}                   
"!"                     {printf("Found !\n");return yy::parser::make_NOT(yytext);}
"("                     {printf("Found (\n");return yy::parser::make_LPAREN(yytext);}
")"                     {printf("Found )\n");return yy::parser::make_RPAREN(yytext);}
"&&"                    {printf("Found &&\n");return yy::parser::make_AND(yytext);}
"||"                    {printf("Found ||\n");return yy::parser::make_OR(yytext);}
"<"                     {printf("Found <\n");return yy::parser::make_LT(yytext);}
">"                     {printf("Found >\n");return yy::parser::make_GT(yytext);}
"=="                    {printf("Found ==\n");return yy::parser::make_EQ(yytext);}
"+"                     {printf("Found +\n");return yy::parser::make_PLUS(yytext);}
"-"                     {printf("Found -\n");return yy::parser::make_MINUS(yytext);}
"*"                     {printf("Found *\n");return yy::parser::make_TIMES(yytext);}
"/"                     {printf("Found /\n");return yy::parser::make_DIVIDE(yytext);}
"."                     {printf("Found .\n");return yy::parser::make_DOT(yytext);}
"length"                {printf("Found lenght\n");return yy::parser::make_LENGTH(yytext);}
"{"                     {printf("Found {\n");return yy::parser::make_LBRACE(yytext);}
"}"                     {printf("Found }\n");return yy::parser::make_RBRACE(yytext);}
"if"                    {printf("Found if\n");return yy::parser::make_IF(yytext);}
"else"                  {printf("Found else\n");return yy::parser::make_ELSE(yytext);}
"while"                 {printf("Found while\n");return yy::parser::make_WHILE(yytext);}
"System.out.println"    {printf("Found System.out.println\n");return yy::parser::make_PRINT(yytext);}
","                     {printf("Found ,\n");return yy::parser::make_COMMA(yytext);}
"="                     {printf("Found =\n");return yy::parser::make_EQUALSIGN(yytext);}
"public"                {printf("Found PUBLIC\n");return yy::parser::make_PUBLIC(yytext);}
"static"                {printf("Found STATIC\n");return yy::parser::make_STATIC(yytext);}
"void"                  {printf("Found VOID\n");return yy::parser::make_VOID(yytext);}
"main"                  {printf("Found MAIN\n");return yy::parser::make_MAIN(yytext);}
"String"                {printf("Found STRING\n");return yy::parser::make_STRING(yytext);}
"class"                 {printf("Found CLASS\n");return yy::parser::make_CLASS(yytext);}
"return"                {printf("Found RETURN\n");return yy::parser::make_RETURN(yytext);}
[a-zA-Z][a-zA-Z0-9_]*   {printf("Found ID\n");return yy::parser::make_ID(yytext);}
"//".*                 {printf("Found Comment!\n");/* DO NOTHING */ }
0|[1-9][0-9]*           {printf("Found NUM\n");return yy::parser::make_NUM(yytext);}
[ \t\r]+                {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                 {printf("Found END\n");return yy::parser::make_END();}
%%


