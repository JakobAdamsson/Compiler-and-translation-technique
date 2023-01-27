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
%token <std::string> MINUS TIMES DIVIDE DOT LENGTH LBRACE RBRACE COMMA IF 
%token <std::string> ELSE WHILE PRINT INTARR EQUALSIGN 
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl


// definition of the production rules. All production rules are of type Node
%type <Node *> Type VarDeclaration Term Expression lrecexp Statement Program

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
              $$ = new Node("Type", "", yylineno);
              $$->children.push_back(new Node("INT", $1, yylineno));
            }

            | BOOLEAN{
              $$ = new Node("Type", "", yylineno);
              $$-> children.push_back(new Node("BOOLEAN", $1,yylineno));

            }
            | ID
            {
              $$ = new Node("Type", "", yylineno);
              $$-> children.push_back(new Node("ID", $1,yylineno));
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
              //$$->children.push_back($1);
            }

            | Expression AND Expression
            {
              $$ = new Node("AND", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression OR Expression
            {
              $$ = new Node("OR", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression LT Expression
            {
              $$ = new Node("LT", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($3);
            }
            | Expression GT Expression
            {
              $$ = new Node("GT", "", yylineno);
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
              $$ = new Node("PRINTSTATEMENT", "", yylineno);
              $$->children.push_back(new Node("PRINT", $1, yylineno));
              $$->children.push_back(new Node("Expression", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("SEMICOLON", $4, yylineno));
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
              $$ = new Node("lrecexp", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("COMMA", $2, yylineno));
              $$->children.push_back($3);
            };