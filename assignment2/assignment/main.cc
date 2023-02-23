#include <iostream>
#include "parser.tab.hh"
// #include "symboltable.hh"

extern Node *root;
extern FILE *yyin;
extern int yylineno;
extern int lexical_errors;

void yy::parser::error(std::string const &err)
{
  printf("Syntax errors found! See the logs below: \n");
  fprintf(stderr, "@error at line %d. Cannot generate a syntax for this input: %s\n", yylineno, err.c_str());
}

int main(int argc, char **argv)
{
  SymbolTable symboltable;
  //  Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if (argc > 1)
  {
    if (!(yyin = fopen(argv[1], "r")))
    {
      perror(argv[1]);
      return 1;
    }
  }

  yy::parser parser;

  if (!parser.parse() && !lexical_errors)
  {

    printf("\nThe compiler successfuly generated a syntax tree for the given input! \n");

    printf("\nPrint Tree:  \n");
    // root->print_tree();
    root->generate_tree();
    root->create_symboltable(&symboltable);
    symboltable.printTable();
    // root->generate_symboltable(&symboltable);
  }

  return 0;
}