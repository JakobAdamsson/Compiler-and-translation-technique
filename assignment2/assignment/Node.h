#ifndef NODE_H
#define NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "symboltable.hh"

using namespace std;

class Node
{
public:
    // Node attributes
    int id, lineno;
    string type, value;
    list<Node *> children;

    // Identifiers
    std::string mclass = "MainClass";
    std::string classdec = "ClassDeclaration";
    std::string vardec = "VarDeclaration";
    std::string midentify = "MethodDeclaration";
    std::string identify = "Identifier";
    std::string sment = "LRStatement";
    std::string parameter = "Parameter";
    std::string ifstate = "If statement";
    std::string elsestate = "ELSE";
    std::string methoddec = "MethodDec";
    std::string expression = "Expression";
    std::string fcall = "FCall";

    // Constructor
    Node(string t, string v, int l) : type(t), value(v), lineno(l) {}
    Node()
    {
        type = "uninitialised";
        value = "uninitialised";
    } // Bison needs this.

    void print_tree(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << "  ";
        cout << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
        for (auto i = children.begin(); i != children.end(); i++)
            (*i)->print_tree(depth + 1);
    }

    void generate_tree()
    {
        std::ofstream outStream;
        char *filename = "tree.dot";
        outStream.open(filename);

        int count = 0;
        outStream << "digraph {" << std::endl;
        generate_tree_content(count, &outStream);
        outStream << "}" << std::endl;
        outStream.close();

        printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.", filename);
        printf("eyy\n");
    }

    void generate_tree_content(int &count, ofstream *outStream)
    {
        id = count++;
        *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

        for (auto i = children.begin(); i != children.end(); i++)
        {
            (*i)->generate_tree_content(count, outStream);
            *outStream << "n" << id << " -> n" << (*i)->id << endl;
        }
    }

    void create_symboltable(SymbolTable *symboltable)
    {
        // Please keep in mind that it only iteratetes through one level of the tree(e.g root only has mainclass and class dec).
        symboltable->variable_type = this->type;
        for (auto i = children.begin(); i != children.end(); i++)
        {

            if ((*i)->type == this->mclass)
            {

                Mainclass(symboltable, (*i));
            }

            else if ((*i)->type == this->classdec)
            {
                // create record och add
                ClassDec(symboltable, (*i));
            }

            else if ((*i)->type == this->midentify)
            {
                MethDec(symboltable, (*i));
            }
            else if ((*i)->type == this->vardec)
            {
                // När vi är här så är vi i method-scope
                if (symboltable->current->scopeName == this->classdec)
                {
                    VarDec_class(symboltable, (*i));
                }
                else
                {
                    VarDec_method(symboltable, (*i));
                }
            }
            else if ((*i)->type == this->parameter)
            {
                addMethodParameters(symboltable, (*i));
            }
            else
            {
                (*i)->create_symboltable(symboltable);
            }
        }
    }

    void addMethodParameters(SymbolTable *symboltable, Node *i)
    {
        symboltable->current_method->addParameter(i->value, symboltable->variable_type);
        symboltable->current_method->printParameters();
    }
    void VarDec_method(SymbolTable *symboltable, Node *i)
    {
        Variable vardec_test;

        // Assing a variable the current scope
        // Add to current scope

        // Fill data
        vardec_test.id = i->value;
        vardec_test.type = i->type;
        symboltable->current_method->addVariable(vardec_test.id, vardec_test);
        symboltable->current_method->printVariables();

        // Add the record to the current scope record
        symboltable->put(vardec_test.id, vardec_test);
    }

    void VarDec_class(SymbolTable *symboltable, Node *i)
    {
        Variable vardec_test;

        // Assing a variable the current scope
        // Add to current scope

        // Fill data
        vardec_test.id = i->value;
        vardec_test.type = i->type;
        symboltable->current_class->addVariable(vardec_test.id, vardec_test);
        symboltable->current_class->printVariables();

        // Add the record to the current scope record
        symboltable->put(vardec_test.id, vardec_test);
    }
    void MethDec(SymbolTable *symboltable, Node *i)
    {
        // Create a new record
        Method methoddec_test;
        // Fill the data
        symboltable->current_method = &methoddec_test;
        methoddec_test.id = i->value;
        methoddec_test.type = i->type;

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
        symboltable->put(methoddec_test.id, methoddec_test);

        // Enter new scope
        symboltable->enterScope(this->midentify);

        i->create_symboltable(symboltable);

        // symboltable.printCurrent();

        // std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;
        symboltable->current_class->addMethod(methoddec_test.id, methoddec_test);
        symboltable->current_class->printMethods();
        symboltable->exitScope();
    }

    // t as in type :)
    void Mainclass(SymbolTable *symboltable, Node *i)
    {
        // Create a new record
        Class mainclass_test;
        // Fill the data
        mainclass_test.id = i->value;
        mainclass_test.type = i->type;

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
        symboltable->put(mainclass_test.id, mainclass_test);

        // Enter new scope
        symboltable->enterScope(this->mclass);

        i->create_symboltable(symboltable);

        // symboltable.printCurrent();

        // std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

        symboltable->exitScope();
    }

    void ClassDec(SymbolTable *symboltable, Node *i)
    {

        // Create a new record
        Class classdec_test;
        // Fill the data
        symboltable->current_class = &classdec_test;
        classdec_test.id = i->value;
        classdec_test.type = i->type;

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.

        // Enter new scope
        symboltable->put(classdec_test.id, classdec_test);
        symboltable->enterScope(this->classdec);

        i->create_symboltable(symboltable);

        // symboltable.printCurrent();

        // std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

        symboltable->exitScope();
    }
};

#endif