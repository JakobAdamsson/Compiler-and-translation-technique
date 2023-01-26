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
%token <std::string> INT LBRACKET RBRACKET BOOLEAN ID SEMICOLON NUM TRUE FALSE THIS NEW NOT LPAREN RPAREN AND OR LT GT EQ PLUS MINUS TIMES DIVIDE DOT LENGTH LBRACE RBRACE COMMA IF ELSE WHILE PRINT INTARR
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl


// definition of the production rules. All production rules are of type Node
%type <Node *> Type VarDeclaration Term Expression lrecexp

%%


root: Expression {root = $1;};
Type: INT LBRACKET RBRACKET 
      {
        $$ = new Node("Type", "", yylineno);
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
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
            }

            | Expression AND Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("AND", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression OR Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("OR", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression LT Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("LT", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression GT Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("GT", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression EQ Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("EQ", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression PLUS Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("PLUS", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression MINUS Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("MINUS", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression TIMES Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("TIMES", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression DIVIDE Term
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("DIVIDE", $2, yylineno));
              $$->children.push_back($3);
            }
            | Expression LBRACKET Expression RBRACKET
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("LBRACKET", $2, yylineno));
              $$->children.push_back($3);
              $$->children.push_back(new Node("RBRACKET", $4, yylineno));
            }
            | Expression DOT LENGTH
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("DOT", $2, yylineno));
              $$->children.push_back(new Node("LENGTH", $3, yylineno));
            }

            | Expression DOT ID LPAREN lrecexp RPAREN
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("DOT", $2, yylineno));
              $$->children.push_back(new Node("ID", $3, yylineno));
              $$->children.push_back(new Node("LPAREN", $4, yylineno));
              $$->children.push_back($5);
              $$->children.push_back(new Node("RPAREN", $6, yylineno));
            };
Term: NUM
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("NUM", $1, yylineno));
            }
            | TRUE
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("TRUE", $1, yylineno));
            }

            | FALSE
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("FALSE", $1, yylineno));
            }

            | ID
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("ID", $1, yylineno));
            }

            | THIS
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("THIS", $1, yylineno));
            }

            | NEW INT LBRACKET Expression RBRACKET
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("NEW", $1, yylineno));
              $$->children.push_back(new Node("INT", $2, yylineno));
              $$->children.push_back(new Node("LBRACKET", $3, yylineno));
              $$->children.push_back($4);
              $$->children.push_back(new Node("RBRACKET", $5, yylineno));
            }

            | NEW ID LPAREN RPAREN
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("NEW", $1, yylineno));
              $$->children.push_back(new Node("ID", $2, yylineno));
              $$->children.push_back(new Node("LPAREN", $3, yylineno));
              $$->children.push_back(new Node("RPAREN", $4, yylineno));
            }
             
            | NOT Expression
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("NOT", $1, yylineno));
              $$->children.push_back($2);
            }

            | LPAREN Expression RPAREN
            {
              $$ = new Node("Expression", "", yylineno);
              $$->children.push_back(new Node("LPAREN", $1, yylineno));
              $$->children.push_back($2);
              $$->children.push_back(new Node("RPAREN", $3, yylineno));
            };

lrecexp: %empty |Expression| lrecexp COMMA Expression
            {
              $$ = new Node("lrecexp", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back(new Node("COMMA", $2, yylineno));
              $$->children.push_back($3);
            };
