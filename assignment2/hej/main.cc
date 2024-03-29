#include <iostream>
#include "parser.tab.hh"

extern Node *root;
extern FILE *yyin;
extern int yylineno;
extern int lexical_errors;
extern yy::parser::symbol_type yylex();

enum errCodes
{
  SUCCESS = 0,
  LEXICAL_ERROR = 1,
  SYNTAX_ERROR = 2,
  AST_ERROR = 3,
  SEMANTIC_ERROR = 4,
  ST_ERROR = 5,
  SEGMENTATION_FAULT = 139
};

int errCode = errCodes::SUCCESS;

void yy::parser::error(std::string const &err)
{
  if (!lexical_errors)
  {
    std::cout << "Syntax errors found! See the logs below:" << std::endl;
    std::cout << "\t@error at line " << yylineno << ". Cannot generate a syntax for this input:" << err.c_str() << std::endl;
    std::cout << "End of syntax errors!" << std::endl;
    errCode = errCodes::SYNTAX_ERROR;
  }
}

int main(int argc, char **argv)
{
  SymbolTable symboltable;
  // Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if (argc > 1)
  {
    if (!(yyin = fopen(argv[1], "r")))
    {
      perror(argv[1]);
      return 1;
    }
  }
  //
  if (USE_LEX_ONLY)
    yylex();
  else
  {
    yy::parser parser;

    bool parseSuccess = !parser.parse();

    if (lexical_errors)
      errCode = errCodes::LEXICAL_ERROR;

    if (parseSuccess && !lexical_errors)
    {
      printf("\nThe compiler successfuly generated a syntax tree for the given input! \n");

      printf("\nPrint Tree:  \n");
      try
      {
        // root->print_tree();
        root->generate_tree();
      }
      catch (...)
      {
        errCode = errCodes::AST_ERROR;
      }
      try
      {
        root->create_symboltable(&symboltable);
        symboltable.root->generate_tree_st();
      }
      catch (...)
      {
        errCode = errCodes::ST_ERROR;
      }
      try
      {
        symboltable.resetTable();
        std::cout << "Starting Variable analysis" << std::endl;
        root->semantic_analysis_variables(&symboltable);
        std::cout << "Variable analysis done" << std::endl;
      }
      catch (...)
      {
        errCode = errCodes::SEMANTIC_ERROR;
      }
      try
      {
        symboltable.resetTable();
        std::cout << "Starting assignment analysis" << std::endl;
        root->check_assignment(&symboltable, root);
        std::cout << "assignment analysis done" << std::endl;
      }
      catch (...)
      {
        errCode = errCodes::SEMANTIC_ERROR;
      }
      try
      {
        symboltable.resetTable();
        std::cout << "Starting method analysis" << std::endl;
        root->semantic_analysis_methods(&symboltable, root);
        std::cout << "Method analysis done" << std::endl;
      }
      catch (...)
      {
        errCode = errCodes::SEMANTIC_ERROR;
      }
      try
      {
        symboltable.resetTable();
        std::cout << "Starting array analysis" << std::endl;
        root->check_int_arrs(&symboltable, root);
        std::cout << "array analysis done" << std::endl;
      }
      catch (...)
      {
        errCode = errCodes::SEMANTIC_ERROR;
      }
    }
  }

  return errCode;
}