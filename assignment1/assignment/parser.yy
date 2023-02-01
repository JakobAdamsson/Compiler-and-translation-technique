/*
Authors:
Jakob Adamsson(jaad19)
Emil Gullbrandsson(emgb20)


This file is a part of the course DV1655 Compiler and translation techniques at BTH.
*/
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #include <vector>
  #include <iostream>
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  
}

// definition of set of tokens. All tokens are of type string
%token <std::string> INT LBRACKET RBRACKET BOOLEAN ID SEMICOLON NUM TRUE 
%token <std::string> FALSE THIS NEW NOT LPAREN RPAREN AND OR LT GT EQ PLUS
%token <std::string> MINUS TIMES DIVIDE DOT LENGTH LBRACE RBRACE COMMA IF RETURN 
%token <std::string> ELSE WHILE PRINT EQUALSIGN PUBLIC STATIC VOID MAIN STRING CLASS 
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left OR
%left AND
%left EQ
%left LT GT
%left NEW
%right NOT
%left PLUS MINUS 
%left TIMES DIVIDE 
%left LBRACKET RBRACKET LPAREN RPAREN

// definition of the production rules. All production rules are of type Node
%type <Node *> Type VarDeclaration Term Expression LRExp Statement 
%type <Node *> Program LRStatement MainClass StateEpsilon 
%type <Node *> MethodDeclaration LRVarDec LRParamater LRVarOrStatementDec LRMethodDec
%type <Node *> ClassDeclaration Goal LRClassDec 

%%
root: Program{root = $1;};


Program: Goal
            {
              $$ = $1;
            }
            | Program ClassDeclaration
            {
              $$ = $1;
              $$->children.push_back($2);
            };

Type:       INT 
            {
              $$ = new Node("Int", "", yylineno);
            }

            | BOOLEAN
            {
              $$ = new Node("Boolean", "", yylineno);
            }
            | ID
            {
              $$ = new Node("Identifier", $1, yylineno);
            }
            | INT LBRACKET RBRACKET
            {
              $$ = new Node("IntArr", "", yylineno);
            };
VarDeclaration: Type ID SEMICOLON
            {
              $$ = new Node("VarDeclaration", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("ID", $2, yylineno));
            };


Expression: Term 
            {
              $$ = $1;
            }

            | Expression AND Expression
            {
              $$ = new Node("And", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression OR Expression
            {
              $$ = new Node("Or", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression LT Expression
            {
              $$ = new Node("Lt", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression GT Expression
            {
              $$ = new Node("Gt", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression EQ Expression
            {
              $$ = new Node("==", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression PLUS Expression
            {
              $$ = new Node("Plus", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("PLUS", "", yylineno));
              $$->children.push_back($3);
            }
            | Expression MINUS Expression
            {
              $$ = new Node("Minus", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression TIMES Expression
            {
              $$ = new Node("Mult", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression DIVIDE Expression
            {
              $$ = new Node("Divide", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression LBRACKET Expression RBRACKET
            {
              $$ = new Node("ArrDec", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression DOT LENGTH
            {
              $$ = $1;
              $$->children.push_back(new Node("Dot", "", yylineno));
              $$->children.push_back(new Node("Lenght", "", yylineno));
            }

            | Expression DOT ID LPAREN LRExp RPAREN
            {
              $$ = new Node("FCall", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("Dot", "", yylineno));
              $$->children.push_back(new Node("Identifier", $3, yylineno));
              $$->children.push_back($5);
            };

Term:       NUM
            {
              $$ = new Node("Num", "", yylineno);
            }
            | TRUE
            {
              $$ = new Node("True", "", yylineno);
            }
            | FALSE
            {
              $$ = new Node("False", "", yylineno);
            }
            | ID
            {
              $$ = new Node("Identifier", $1, yylineno);
            }
            | THIS
            {
              $$ = new Node("This", "", yylineno);
            }
            | NEW INT LBRACKET Expression RBRACKET
            {
              $$ = new Node("IntArrDec", "", yylineno);
              $$->children.push_back(new Node("New", "", yylineno));
              $$->children.push_back(new Node("Int", "", yylineno));
              $$->children.push_back($4);
            }
            | NEW ID LPAREN RPAREN
            {
              $$ = new Node("NewVar", "", yylineno);
              $$->children.push_back(new Node("New", "", yylineno));
              $$->children.push_back(new Node("Identifier", $2, yylineno));
            } 
            | NOT Expression
            {
              $$ = new Node("Not", "", yylineno);
              $$->children.push_back($2);
            }
            | LPAREN Expression RPAREN
            {
              $$ = new Node("ArrAcc", "", yylineno);
              $$->children.push_back($2);
            };
Statement: ID LBRACKET Expression RBRACKET EQUALSIGN Expression SEMICOLON
            {
              $$ = new Node("ArrModifier", "", yylineno);
              $$->children.push_back(new Node("Identifier", $1, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("Equal", "", yylineno));
              $$->children.push_back($6);

            }
            | ID EQUALSIGN Expression SEMICOLON
            {
              $$ = new Node("Assignment", "", yylineno);
              $$->children.push_back(new Node("Identifier", $1, yylineno));
              $$->children.push_back(new Node("Equal", "", yylineno));
              $$->children.push_back($3);
            }
            | PRINT LPAREN Expression RPAREN SEMICOLON
            {
              $$ = new Node("Print", "", yylineno);
              $$->children.push_back($3);
            }
            | WHILE LPAREN Expression RPAREN Statement
            {
              $$ = new Node("While", "", yylineno);
              $$->children.push_back($3);
              $$->children.push_back($5);
            }
            | LBRACE LRStatement RBRACE
            {
              $$ = $2;
            }

            | IF LPAREN Expression RPAREN Statement StateEpsilon
            {
              $$ = new Node("If statement", "", yylineno);
              $$->children.push_back(new Node("If", "", yylineno));
              $$->children.push_back($3);
              $$->children.push_back($5);
              $$->children.push_back($6);
            };
MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE LRStatement RBRACE RBRACE
            {
              $$ = new Node("MainClass", "", yylineno);
              $$->children.push_back(new Node("Public", "", yylineno));
              $$->children.push_back(new Node("Class", "", yylineno));
              $$->children.push_back(new Node("Identifier", $3, yylineno));
              $$->children.push_back(new Node("Public", "", yylineno));
              $$->children.push_back(new Node("Static", "", yylineno));
              $$->children.push_back(new Node("Void", "", yylineno));
              $$->children.push_back(new Node("Main", "", yylineno));
              $$->children.push_back(new Node("Lparen", "", yylineno));
              $$->children.push_back(new Node("String", "", yylineno));
              $$->children.push_back(new Node("Identifier", $13, yylineno));
              $$->children.push_back($16);
            };
MethodDeclaration: PUBLIC Type ID LPAREN LRParamater RPAREN LBRACE LRVarOrStatementDec RETURN Expression SEMICOLON RBRACE
            {
              $$ = new Node("MethodDeclaration", "", yylineno);
              $$->children.push_back(new Node("Public", "", yylineno));
              $$->children.push_back($2);
              $$->children.push_back(new Node("Identifier", $3, yylineno));
              $$->children.push_back($5);
              $$->children.push_back($8);
              $$->children.push_back(new Node("Return", "", yylineno));
              $$->children.push_back($10);
            };
ClassDeclaration: CLASS ID LBRACE LRVarDec LRMethodDec RBRACE
            {
              $$ = new Node("ClassDeclaration", "", yylineno);
              $$->children.push_back(new Node("Class", "", yylineno));
              $$->children.push_back(new Node("Identifier", $2, yylineno));
              $$->children.push_back($4);
              $$->children.push_back($5);
            };
/*
This is how the structure that the program parsed is supposed to follow. 
In Java the structure is as follows:
public class MainClass {
  public static void main(String[] a) {
    System.out.println(new A().foo());
  }
}
*/
Goal: MainClass LRClassDec END
            {
              $$ = new Node("Goal", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($2);
            };
/*
Left recursive expression. It may either be empty, have one expression or multiple. If multiple expressions are given,
Then it calls upon itself untill no more expressions are being read.
*/
LRExp: %empty
            {
              $$ = new Node("Empty", "", yylineno);
            }
            | Expression
            {
              $$ = $1;
            }
            | LRExp COMMA Expression   
            {
              $$ = new Node("LRExp", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("Comma", "", yylineno));
              $$->children.push_back($3);
            };
/*
Left recursive statement. It may either be empty, have one statement or multiple. If multiple statements are given,
Then it calls upon itself untill no more statements are being read.
*/
LRStatement: Statement
              {
                $$ = $1;
              }
              | LRStatement Statement
              {
                $$ = new Node("LRStatement", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };
/*
Left recursive var declarations. It may either be empty, have one var declaration or multiple. If multiple var declarations are given,
Then it calls upon itself untill no more var declarations are being read.
*/
LRVarDec: %empty
              {
                $$ = new Node("Empty", "", yylineno);
              }
              | VarDeclaration
              {
                $$ = $1;
              }
              | LRVarDec VarDeclaration
              {
                $$ = new Node("LRVarDec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };
/* 
Left recursion on method parameters, it may either be empty, have one parameters or multiple. If multiple parameters are given,
Then it calls upon itself untill no more parameters are being read.
*/
LRParamater: %empty
              {
                $$ = new Node("Empty", "", yylineno);
              }
              | Type ID
              {
                $$ = new Node("LRParamater", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back(new Node("Identifier", $2, yylineno));
              }
              | LRParamater COMMA Type ID
              {
                $$ = new Node("LRParamater", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back(new Node("Comma", "", yylineno));
                $$->children.push_back($3);
                $$->children.push_back(new Node("Identifier", $4, yylineno));
              };
  
/*
Left recursion on statement or var declaration. It calls upon it self untill no more VarDeclaration or Statements are being read.
It accepts either no VarDeclaration or Statement, one VarDeclaration or Statement or multiple VarDeclaration or Statements.
*/
LRVarOrStatementDec: %empty
              {
                $$ = new Node("Empty", "", yylineno);
              }
              | VarDeclaration
              {
                $$ = $1;
              }
              | Statement
              {
                $$ = $1;
              }
              | LRVarOrStatementDec VarDeclaration
              {
                $$ = new Node("LRVarOrStatementDec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              }
              | LRVarOrStatementDec Statement
              {
                $$ = new Node("LRVarOrStatementDec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };


/*
Left Recursive Method Declaration, It requires either one method declaration or multiple
It stops when no more method declarations are being read.
*/
LRMethodDec: MethodDeclaration
              {
                $$ = $1;
              }
              | LRMethodDec MethodDeclaration
              {
                $$ = new Node("LRMethodDec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };    

/*Statement Epsilon Handles the question mark operator, optional else statement*/
StateEpsilon: %empty
              {
                $$ = new Node("EMPTY", "", yylineno);
              }
              | ELSE Statement 
              {
                $$ = new Node("ELSE", "", yylineno);
                $$->children.push_back($2);
              };
              
            
/*
Left Recursive Class Declaration. It requires atleast one class declaration and stops when no more class declarations are read.
*/
LRClassDec: ClassDeclaration
              {
                $$ = $1;
              }
              | LRClassDec ClassDeclaration
              {
                $$ = new Node("LRClassDec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };