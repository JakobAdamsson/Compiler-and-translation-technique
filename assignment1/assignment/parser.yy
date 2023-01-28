%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
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
%token <std::string> END 
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl


// definition of the production rules. All production rules are of type Node
%type <Node *> Type VarDeclaration Term Expression lrecexp Statement 
%type <Node *> Program lrecstatement MainClass StateQuest StateEpsilon 
%type <Node *> MethodDeclaration lrecvardec lrectype lrecparameter lrecvardecorstate lrecmethoddec
%type <Node *> ClassDeclaration Goal lrecclassdec

%%
root: Program {root = $1;};


Program: Type
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            }
            
            | VarDeclaration
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);  
            } 
            
            | Expression
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            }
            
            | Statement
            {          
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            }
            | MainClass
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            }
            | MethodDeclaration
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            }
            | ClassDeclaration
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            }
            | Goal
            {
              $$ = new Node("Program", "", yylineno);
              $$->children.push_back($1);
            };

Type: INT LBRACKET RBRACKET 
            {
              $$ = new Node("ARRDEC", "", yylineno);
              $$->children.push_back(new Node("INTARR", $1, yylineno));
              $$->children.push_back(new Node("LBRACKET", $2, yylineno));
              $$->children.push_back(new Node("RBRACKET", $3, yylineno));
            }
            | INT 
            {
              $$ = new Node("INT", $1, yylineno);
            }

            | BOOLEAN{
              $$ = new Node("BOOLEAN", $1, yylineno);

            }
            | ID
            {
              $$ = new Node("IDENTIFIER", $1, yylineno);
            };
VarDeclaration: Type ID SEMICOLON
            {
              $$ = new Node("VarDeclaration", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("ID", $2, yylineno));
              $$->children.push_back(new Node("SEMICOLON", $3, yylineno));
            };


Expression: Term 
            {
              $$ = $1;
            }

            | Expression AND Expression
            {
              $$ = new Node("AND", "&&", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression OR Expression
            {
              $$ = new Node("OR", "||", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression LT Expression
            {
              $$ = new Node("LT", "<", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression GT Expression
            {
              $$ = new Node("GT", ">", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression EQ Expression
            {
              $$ = new Node("EQ", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression PLUS Expression
            {
              $$ = new Node("PLUS", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("PLUS", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression MINUS Expression
            {
              $$ = new Node("MINUS", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression TIMES Expression
            {
              $$ = new Node("TIMES", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression DIVIDE Expression
            {
              $$ = new Node("DIVIDE", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression LBRACKET Expression RBRACKET
            {
              $$ = $1;
              $$->children.push_back(new Node("LBRACKET", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("RBRACKET", $4, yylineno));
            }
            | Expression DOT LENGTH
            {
              $$ = $1;
              $$->children.push_back(new Node("DOT", $2, yylineno));
              $$->children.push_back(new Node("LENGTH", $3, yylineno));
            }

            | Expression DOT ID LPAREN lrecexp RPAREN
            {
              $$ = new Node("EXPREC", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("DOT", $2, yylineno));
              $$->children.push_back(new Node("ID", $3, yylineno));
              $$->children.push_back(new Node("LPAREN", $4, yylineno));
              $$->children.push_back($5);
              $$->children.push_back(new Node("RPAREN", $6, yylineno));
            };

Term:         NUM
            {
              $$ = new Node("NUM", $1, yylineno);
            }
            | TRUE
            {
              $$ = new Node("TRUE", $1, yylineno);
            }

            | FALSE
            {
              $$ = new Node("FALSE", $1, yylineno);
            }

            | ID
            {
              $$ = new Node("ID", $1, yylineno);
            }

            | THIS
            {
              $$ = new Node("THIS", $1, yylineno);
            }

            | NEW INT LBRACKET Expression RBRACKET
            {
              $$ = new Node("INTARRDEC", "", yylineno);
              $$->children.push_back(new Node("NEW", $1, yylineno));
              $$->children.push_back(new Node("INT", $2, yylineno));
              $$->children.push_back(new Node("LBRACKET", $3, yylineno));
              $$->children.push_back($4);
              $$->children.push_back(new Node("RBRACKET", $5, yylineno));
            }

            | NEW ID LPAREN RPAREN
            {
              $$ = new Node("DECEXP", "", yylineno);
              $$->children.push_back(new Node("NEW", $1, yylineno));
              $$->children.push_back(new Node("ID", $2, yylineno));
              $$->children.push_back(new Node("LPAREN", $3, yylineno));
              $$->children.push_back(new Node("RPAREN", $4, yylineno));
            }
             
            | NOT Expression
            {
              $$ = new Node("NOTEXP", "", yylineno);
              $$->children.push_back($2);
            }

            | LPAREN Expression RPAREN
            {
              $$ = new Node("LPAREN EXP RPAREN", "", yylineno);
              $$->children.push_back(new Node("LPAREN", $1, yylineno));
              $$->children.push_back($2);
              $$->children.push_back(new Node("RPAREN", $3, yylineno));
            };
Statement: ID LBRACKET Expression RBRACKET EQUALSIGN Expression SEMICOLON
            {
              $$ = new Node("ARRSTATEMENT", "", yylineno);
              $$->children.push_back(new Node("ID", $1, yylineno));
              $$->children.push_back(new Node("LBRACKET", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("RBRACKET", $4, yylineno));
              $$->children.push_back(new Node("EQUALSIGN", $5, yylineno));
              $$->children.push_back($6);
              $$->children.push_back(new Node("SEMICOLON", $7, yylineno));
            }
            | ID EQUALSIGN Expression SEMICOLON
            {
              $$ = new Node("ASSIGNSTATEMENT", "", yylineno);
              $$->children.push_back(new Node("ID", $1, yylineno));
              $$->children.push_back(new Node("EQUAL", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("SEMICOLON", $4, yylineno));
            }
            | PRINT LPAREN Expression RPAREN SEMICOLON
            {
              $$ = new Node("PRINTSTATEMENT", $1, yylineno);
              $$->children.push_back(new Node("LPAREN", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("RPAREN", $4, yylineno));
              $$->children.push_back(new Node("SEMICOLON", $5, yylineno));

            }
            | WHILE LPAREN Expression RPAREN Statement
            {
              $$ = new Node("WHILE STATEMENT", $1, yylineno);
              $$->children.push_back(new Node("LPAREN", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("RPAREN", $4, yylineno));
              $$->children.push_back($5);
            }
            | LBRACE lrecstatement RBRACE
            {
              $$ = new Node("LBRACE STATEMENT RBRACE", "", yylineno);
              $$->children.push_back(new Node("LBRACE", $1, yylineno));
              $$->children.push_back($2);
              $$->children.push_back(new Node("RBRACE", $3, yylineno));
            }
            | IF LPAREN Expression RPAREN Statement StateEpsilon
            {
              $$ = new Node("IF STATEMENT", "", yylineno);
              $$->children.push_back(new Node("IF", $1, yylineno));
              $$->children.push_back(new Node("LPAREN", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("RPAREN", $4, yylineno));
              $$->children.push_back($5);
              $$->children.push_back($6);
            };



MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE lrecstatement RBRACE RBRACE
            {
              $$ = new Node("MainClass", "", yylineno);
              $$->children.push_back(new Node("PUBLIC", $1, yylineno));
              $$->children.push_back(new Node("CLASS", $2, yylineno));
              $$->children.push_back(new Node("ID", $3, yylineno));
              $$->children.push_back(new Node("LBRACE", $4, yylineno));
              $$->children.push_back(new Node("PUBLIC", $5, yylineno));
              $$->children.push_back(new Node("STATIC", $6, yylineno));
              $$->children.push_back(new Node("VOID", $7, yylineno));
              $$->children.push_back(new Node("MAIN", $8, yylineno));
              $$->children.push_back(new Node("LPAREN", $9, yylineno));
              $$->children.push_back(new Node("STRING", $10, yylineno));
              $$->children.push_back(new Node("LBRACKET", $11, yylineno));
              $$->children.push_back(new Node("RBRACKET", $12, yylineno));
              $$->children.push_back(new Node("ID", $13, yylineno));
              $$->children.push_back(new Node("RPAREN", $14, yylineno));
              $$->children.push_back(new Node("LBRACE", $15, yylineno));
              $$->children.push_back($16);
              $$->children.push_back(new Node("RBRACE", $17, yylineno));
              $$->children.push_back(new Node("RBRACE", $18, yylineno));
            };


MethodDeclaration: PUBLIC Type ID LPAREN lrecparameter RPAREN LBRACE lrecvardecorstate RETURN Expression SEMICOLON RBRACE
            {
              $$ = new Node("MethodDeclaration", "", yylineno);
              $$->children.push_back(new Node("PUBLIC", $1, yylineno));
              $$->children.push_back($2);
              $$->children.push_back(new Node("ID", $3, yylineno));
              $$->children.push_back(new Node("LPAREN", $4, yylineno));
              $$->children.push_back($5);
              $$->children.push_back(new Node("RPAREN", $6, yylineno));
              $$->children.push_back(new Node("LBRACE", $7, yylineno));
              $$->children.push_back($8);
              $$->children.push_back(new Node("RETURN", $9, yylineno));
              $$->children.push_back($10);
              $$->children.push_back(new Node("SEMICOLON", $11, yylineno));
              $$->children.push_back(new Node("RBRACE", $12, yylineno));
            };




ClassDeclaration: CLASS ID LBRACE lrecvardec lrecmethoddec RBRACE
            {
              $$ = new Node("ClassDeclaration", "", yylineno);
              $$->children.push_back(new Node("CLASS", $1, yylineno));
              $$->children.push_back(new Node("ID", $2, yylineno));
              $$->children.push_back(new Node("LBRACE", $3, yylineno));
              $$->children.push_back($4);
              $$->children.push_back($5);
              $$->children.push_back(new Node("RBRACE", $6, yylineno));
            
            };

Goal: MainClass lrecclassdec END
            {
              $$ = new Node("Goal", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($2);
              $$->children.push_back(new Node("END", $3, yylineno));
            };

lrecexp: %empty
            {
              $$ = new Node("EMPTY", "", yylineno);
            }
            | Expression
            {
              $$ = $1;
            }
            | lrecexp COMMA Expression   
            {
              $$ = new Node("lrecexp", "ɛ", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("COMMA", $2, yylineno));
              $$->children.push_back($3);
            };

lrecstatement: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | Statement
              {
                $$ = $1;
              }
              | lrecstatement Statement
              {
                $$ = new Node("lrecstatement", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };
lrectype: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | Type
              {
                $$ = $1;
              }
              | lrectype Type ID COMMA
              {
                $$ = new Node("lrectype", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
                $$->children.push_back(new Node("IDENTIFIER", $3, yylineno));
                $$->children.push_back(new Node("COMMA", $4, yylineno));
              };
lrecvardec: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | VarDeclaration
              {
                $$ = $1;
              }
              | lrecvardec VarDeclaration
              {
                $$ = new Node("lrecvardec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };
lrecparameter: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | Type ID
              {
                $$ = new Node("lrecparameter", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back(new Node("IDENTIFIER", $2, yylineno));
              }
              | lrecparameter COMMA Type ID
              {
                $$ = new Node("lrecparameter", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back(new Node("COMMA", $2, yylineno));
                $$->children.push_back($3);
                $$->children.push_back(new Node("IDENTIFIER", $4, yylineno));
              };

lrecvardecorstate: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | VarDeclaration
              {
                $$ = $1;
              }
              | Statement
              {
                $$ = $1;
              }
              | lrecvardecorstate VarDeclaration
              {
                $$ = new Node("lrecvarorvardec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              }
              | lrecvardecorstate Statement
              {
                $$ = new Node("lrecvarorstate", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };

lrecmethoddec: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | MethodDeclaration
              {
                $$ = $1;
              }
              | lrecmethoddec MethodDeclaration
              {
                $$ = new Node("lrecmethoddec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };
              
lrecclassdec: %empty
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              }
              | ClassDeclaration
              {
                $$ = $1;
              }
              | lrecclassdec ClassDeclaration
              {
                $$ = new Node("lrecclassdec", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };

StateQuest: Statement 
              {
                $$ = new Node("STATEMENT", "", yylineno);
                $$->children.push_back($1);
              }
              | StateQuest Statement  
              {
                $$ = new Node("STATEMENT", "", yylineno);
                $$->children.push_back($1);
                $$->children.push_back($2);
              };

StateEpsilon: %empty 
              {
                $$ = new Node("EMPTY", "ɛ", yylineno);
              } 
              | ELSE Statement 
              {
                $$ = new Node("ELSE", $1, yylineno);
                $$->children.push_back($2);
              };