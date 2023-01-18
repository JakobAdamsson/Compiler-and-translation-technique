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
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP LBRACKET RBRACKET
%token END 0 "end of file"

// definition of the production rules. All production rules are of type Node
%type <Node *> test
%%
test: INT            { $$ = new Node("Expression", "", yylineno); 
                       $$->children.push_back(new Node("int", $1, yylineno));
                       root = $$;
                       printf("Hello\n");
                     };
    
