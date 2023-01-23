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
%token <std::string> PUBLIC CLASS LBRACE RBRACE VOID MAIN LPAREN RPAREN STRING LBRACKET RBRACKET ID STATIC
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left PLUSOP MINUSOP
%left MULTOP

// definition of the production rules. All production rules are of type Node
%type <Node *> MainClass

%%
root: MainClass {root = $1;};
MainClass: PUBLIC CLASS ID LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET ID RPAREN LBRACE RBRACE RBRACE {
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
                    $$->children.push_back(new Node("RBRACE", $16, yylineno));
                    $$->children.push_back(new Node("RBRACE", $17, yylineno));
                    root = $$;
                    };
