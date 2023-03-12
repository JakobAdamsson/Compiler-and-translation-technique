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
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
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

//defition of operator precedence
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
%type <Node *> Type VarDeclaration Term Expression Statement 
%type <Node *> Program LRStatement MainClass StateEpsilon 
%type <Node *> MethodDeclaration LRVarDec LRParamater LRVarOrStatementDec LRMethodDec
%type <Node *> ClassDeclaration Goal LRClassDec LRArguments

%%
root: Program{root = $1;};

/*
Needs to have a Goal production inorder to be valid Java.
*/
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
              $$ = new Node($1, $1, yylineno);
            }
            | INT LBRACKET RBRACKET
            {
              $$ = new Node("IntArr", "", yylineno);
            };
VarDeclaration: Type ID SEMICOLON
            {
              // CHANGED THIS MIGHT DESTROY SOMETHING ELSE
              std::string dtype = $1->type;
              // CHANGE TO $2 IF THIS BUGS!
              std::cout << "aLSdjLAnfraskdlnä " << $1->value<<std::endl;
              $$ = new Node("VarDeclaration",$2, yylineno, dtype);
              $$->children.push_back($1);

              //$$->children.push_back(new Node("ID", $2, yylineno,dtype));
            };


Expression: Term 
            {
              $$ = $1;
            }
            | Expression DOT ID LPAREN LRArguments RPAREN
            {
              $$ = new Node("FCall", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("Dot", "", yylineno));
              $$->children.push_back(new Node("Identifier", $3, yylineno,"Method"));
              $$->children.push_back($5);
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
              //$$->children.push_back(new Node("PLUS", "", yylineno));
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
            };

Term:       NUM
            {
              $$ = new Node("Num", $1, yylineno, "Int");
            }
            | TRUE
            {
              $$ = new Node("True", "", yylineno);
            }
            | FALSE
            {
              $$ = new Node("False", "", yylineno);
            }
            |ID
            {
              $$ = new Node("Identifier", $1, yylineno);

            }
            | THIS
            {
              $$ = new Node("this", "", yylineno);
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
              $$ = new Node("NewVar", $2, yylineno, "Class");
              //$$->children.push_back(new Node("New", "", yylineno));
              //$$->children.push_back(new Node("Identifier", $2, yylineno, "Class"));
            } 
            | NOT Expression
            {
              $$ = new Node("Not", "", yylineno);
              $$->children.push_back($2);
            }
            | LPAREN Expression RPAREN
            {
              $$ = $2;
            }
            | CLASS
            {
              $$ = new Node("Class", "", yylineno);
            };
Statement: ID LBRACKET Expression RBRACKET EQUALSIGN Expression SEMICOLON
            {
              $$ = new Node("ArrModifier", "", yylineno);
              $$->children.push_back(new Node("Identifier", $1, yylineno));
              $$->children.push_back($3);
              //$$->children.push_back(new Node("Equal", "", yylineno));
              $$->children.push_back($6);

            }
            | ID EQUALSIGN Expression SEMICOLON
            {
              $$ = new Node("Assignment", "", yylineno);
              $$->children.push_back(new Node("Identifier", $1, yylineno));
              //$$->children.push_back(new Node("Equal", "", yylineno));
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
              $$->children.push_back($3);
              $$->children.push_back($5);
              $$->children.push_back($6);
            };
MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE LRStatement RBRACE RBRACE
            {
              $$ = new Node("MainClass", $3, yylineno);
              $$->children.push_back(new Node("Identifier", $3, yylineno));
              $$->children.push_back(new Node("Method Identifier", $13, yylineno));
              $$->children.push_back($16);
            };
MethodDeclaration: PUBLIC Type ID LPAREN LRParamater RPAREN LBRACE LRVarOrStatementDec RETURN Expression SEMICOLON RBRACE
            {
              std::string dtype = $2->type;
              // CHANGE TO $2 HERE IF IT BUGS!
              $$ = new Node("MethodDeclaration", $3, yylineno, dtype);
              $$->children.push_back(new Node("Public", "", yylineno));
              $$->children.push_back($2);
              $$->children.push_back(new Node("Identifier", $3, yylineno));
              $$->children.push_back($5);
              $$->children.push_back($8);
              $$->children.push_back($10);
            };
ClassDeclaration: CLASS ID LBRACE LRVarDec LRMethodDec RBRACE
            {
              $$ = new Node("ClassDeclaration", $2, yylineno);
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
// LRExp: %empty
//             {
//               $$ = new Node("Empty", "", yylineno);
//             }
//             | Expression
//             {
//               $$ = new Node("Expression", "", yylineno);
//               $$->children.push_back($1);
//             }
//             | LRExp COMMA Expression   
//             {
//               $1->children.push_back($3);
//               $$ = $1;
//             };
/*
Left recursive statement. It may either be empty, have one statement or multiple. If multiple statements are given,
Then it calls upon itself untill no more statements are being read.
*/
LRStatement: Statement
              {
                $$ = new Node("Statement", "", yylineno);
                $$->children.push_back($1);
              }
              | LRStatement Statement
              {
                $1->children.push_back($2);
                $$ = $1;

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
                $$ = new Node("VarDeclarations", "", yylineno);
                $$->children.push_back($1);

              }
              | LRVarDec VarDeclaration
              {
                $1->children.push_back($2);
                $$ = $1;
          
              };
/* 
Left recursion on method parameters, it may either be empty, have one parameters or multiple. If multiple parameters are given,
Then it calls upon itself untill no more parameters are being read.
*/
LRParamater: %empty
              {
                $$ = new Node("Parameters", "", yylineno);
              }
              | Type ID
              {
  
                $$ = new Node("Parameters", "", yylineno, $1->type);
                $$->children.push_back(new Node("Identifier", $2, yylineno, $1->type));
                //$$ = $1;
              }
              | LRParamater COMMA Type ID
              {
                $1->children.push_back(new Node("Identifer", $4, yylineno, $3->type));
                $$ = $1;

              };
LRArguments: %empty
              {
                $$ = new Node("Arguments", "", yylineno);
              }
              | Expression
              {
                $$ = new Node("Arguments", "", yylineno);
                $$->children.push_back($1);
              }
              | LRArguments COMMA Expression
              {
                $1->children.push_back($3);
                $$ = $1;
              };
  
/*
Left recursion on statement or var declaration. It calls upon it self untill no more VarDeclaration or Statements are being read.
It accepts either no VarDeclaration or Statement, one VarDeclaration or Statement or multiple VarDeclaration or Statements.
*/
LRVarOrStatementDec: %empty
              {
                $$ = new Node("Empty", "", yylineno);
              }
              | Statement
              {
                $$ = new Node("Statement", "", yylineno);
                $$->children.push_back($1);
              }
              | VarDeclaration
              {
                $$ = new Node("VarDeclarations", "", yylineno);
                $$->children.push_back($1);

                //$$->children.push_back($1);
              }
              | LRVarOrStatementDec Statement
              {
                $1->children.push_back($2);
                $$ = $1;
                //$$->children.push_back($2);
              }
              | LRVarOrStatementDec VarDeclaration
              {
                $1->children.push_back($2);
                $$ = $1;
                //$$->children.push_back($2);

              };


/*
Left Recursive Method Declaration, It requires either one method declaration or multiple
It stops when no more method declarations are being read.
*/
LRMethodDec: MethodDeclaration
              {
                $$ = new Node("MethodDeclarations", "", yylineno);
                $$->children.push_back($1);
              }
              | LRMethodDec MethodDeclaration
              {
                $$ = $1;
                $1->children.push_back($2);
                
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