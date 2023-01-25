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
%token <std::string> INT LBRACKET RBRACKET BOOLEAN ID SEMICOLON
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl


// definition of the production rules. All production rules are of type Node
%type <Node *> Type VarDeclaration

%%
root: VarDeclaration {root = $1;};
Type: INT LBRACKET RBRACKET 
      {
        $$ = new Node("Type", "", yylineno);
        $$->children.push_back(new Node("INTARR", $1, yylineno));
        // $$->children.push_back(new Node("ID", $2, yylineno));
        $$->children.push_back(new Node("LBRACKET", $2, yylineno));
        $$->children.push_back(new Node("RBRACKET", $3, yylineno));

      }
                    
                    
      | INT 
      {
        $$ = new Node("Type", "", yylineno);
        $$->children.push_back(new Node("INT", $1, yylineno));
        // $$->children.push_back(new Node("ID", $2, yylineno));
      }

      | BOOLEAN{
        $$ = new Node("Type", "", yylineno);
        $$-> children.push_back(new Node("BOOLEAN", $1,yylineno));
        // $$-> children.push_back(new Node("ID", $2,yylineno));

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
