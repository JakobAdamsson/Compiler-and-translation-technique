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
    string type, value, dtype;
    list<Node *> children;

    // Identifiers
    std::string mclass = "MainClass";
    std::string classdec = "ClassDeclaration";
    std::string vardec = "VarDeclaration";
    std::string midentify = "MethodDeclaration";
    std::string identify = "Identifier";
    std::string sment = "LRStatement";
    std::string parameter = "Parameter";
    std::string elsestate = "ELSE";
    std::string methoddec = "MethodDec";
    std::string expression = "Expression";
    std::string fcall = "FCall";
    std::string assignment = "Assignment";
    // Constructor
    Node(string t, string v, int l, string data_type = "") : type(t), value(v), lineno(l), dtype(data_type) {}
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
                std::cout << "ÄR VI HÄR?" << std::endl;
                MethDec(symboltable, (*i));
            }
            else if ((*i)->type == this->vardec)
            {
                // När vi är här så är vi i method-scope
                if (symboltable->current->scopeName.substr(0, 5) == "Class")
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
        // symboltable->current_method->printParameters();
    }
    void VarDec_method(SymbolTable *symboltable, Node *i)
    {
        Variable *vardec_test = new Variable();

        // Assing a variable the current scope
        // Add to current scope

        // Fill data
        vardec_test->id = i->value;
        vardec_test->type = i->type;
        vardec_test->dtype = i->dtype;
        // vardec_test.dtype = symboltable->variable_type;
        symboltable->current_method->addVariable(vardec_test->id, vardec_test);
        // symboltable->current_method->printVariables();

        // Add the record to the current scope record
        symboltable->put(vardec_test->id, vardec_test);
    }

    void VarDec_class(SymbolTable *symboltable, Node *i)
    {
        Variable *vardec_test = new Variable();

        // Assing a variable the current scope
        // Add to current scope

        // Fill data
        vardec_test->id = i->value;
        vardec_test->type = i->type;
        vardec_test->dtype = i->dtype;
        symboltable->current_class->addVariable(vardec_test->id, vardec_test);
        // symboltable->current_class->printVariables();

        // Add the record to the current scope record
        symboltable->put(vardec_test->id, vardec_test);
    }
    void MethDec(SymbolTable *symboltable, Node *i)
    {
        // Create a new record

        Method *methoddec_test = new Method();
        // Fill the data
        symboltable->current_method = methoddec_test;
        methoddec_test->id = i->value;
        methoddec_test->type = i->type;
        methoddec_test->dtype = i->dtype;

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
        symboltable->put(methoddec_test->id, methoddec_test);

        // Enter new scope
        symboltable->enterScope(this->midentify + "(" + i->value + ")");

        i->create_symboltable(symboltable);

        // symboltable.printCurrent();

        // std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;
        symboltable->current_class->addMethod(methoddec_test->id, methoddec_test);
        // symboltable->current_class->printMethods();
        symboltable->exitScope();
    }

    // t as in type :)
    void Mainclass(SymbolTable *symboltable, Node *i)
    {
        // Create a new record
        Class *mainclass_test = new Class();
        // Fill the data

        mainclass_test->id = i->value;
        mainclass_test->type = i->type;

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.

        symboltable->put(mainclass_test->id, mainclass_test);
        // Enter new scope
        symboltable->enterScope(this->mclass + "(" + i->value + ")");

        i->create_symboltable(symboltable);

        // symboltable.printCurrent();

        // std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

        symboltable->exitScope();
    }

    void ClassDec(SymbolTable *symboltable, Node *i)
    {

        // Create a new record
        Class *classdec_test = new Class();
        // Fill the data
        symboltable->current_class = classdec_test;
        classdec_test->id = i->value;
        classdec_test->type = i->type;

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.

        // Enter new scope
        symboltable->put(classdec_test->id, classdec_test);
        // symboltable->enterScope("hello");

        symboltable->enterScope(this->classdec + "(" + i->value + ")");
        i->create_symboltable(symboltable);

        // symboltable.printCurrent();

        // std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

        symboltable->exitScope();
    }

    void semantic_analysis_variables(SymbolTable *symboltable)
    {
        for (auto i = children.begin(); i != children.end(); i++)
        {

            if ((*i)->type == this->mclass)
            {
                symboltable->enterScope();
                (*i)->semantic_analysis_variables(symboltable);
                symboltable->exitScope();
            }
            else if ((*i)->type == this->midentify)
            {
                // Now we are in method scope
                symboltable->enterScope();
                (*i)->semantic_analysis_variables(symboltable);

                // Record *res = symboltable->lookup((*i)->value);
                // std::cout << symboltable->current->scopeName << "EYYYYYYY" << std::endl;
                // res->printRecord();
                symboltable->exitScope();

                // Method meth = (Method)res;
            }
            else if ((*i)->type == this->classdec)
            {
                symboltable->enterScope();
                (*i)->semantic_analysis_variables(symboltable);
                symboltable->exitScope();
            }
            else if ((*i)->type == this->assignment)
            {
                // std::cout << symboltable->current->scopeName << std::endl;
                for (auto ii = (*i)->children.begin(); ii != (*i)->children.end(); ii++)
                {
                    // std::cout << (*ii)->value << " : " << (*ii)->type << " DTYPE: " << (*ii)->dtype << std::endl;
                    Record *hej = symboltable->lookup((*ii)->value);
                    if ((*ii)->type == this->identify)
                    {
                        if (hej == NULL)
                        {
                            std::cout << "NO RECORD FOUND FOR-> "
                                      << "ID: " << (*ii)->value << " TYPE: " << (*ii)->type << std::endl;
                            return;
                        }
                        else
                            std::cout << "RECORD FOUND FOR-> "
                                      << "ID: " << (*ii)->value << " TYPE: " << (*ii)->type << std::endl;
                    }
                }
            }
            else
            {
                (*i)->semantic_analysis_variables(symboltable);
            }
        }
    }
    void semantic_analysis_methods(SymbolTable *symboltable)
    {
        for (auto i = children.begin(); i != children.end(); i++)
        {
            if ((*i)->type == classdec)
            {
                Record *rec = symboltable->lookup((*i)->value);
                if (rec == NULL)
                {
                    std::cout << "NO RECORD FOUND FOR-> "
                              << "ID: " << (*i)->value << " TYPE: " << (*i)->type << std::endl;
                    return;
                }
                Class *cls = dynamic_cast<Class *>(rec);
                if (cls == nullptr)
                {
                    std::cout << "CAST FAILED FOR-> "
                              << "ID: " << (*i)->value << " TYPE: " << (*i)->type << std::endl;
                }
                symboltable->this_fcall_current_class = cls;
            }
            else if ((*i)->type == fcall)
            {
                (*i)->fcall_post_order(symboltable, *i);
                symboltable->fcall_current_class = nullptr;
            }

            else
            {
                (*i)->semantic_analysis_methods(symboltable);
            }
        }
    };
    void fcall_post_order(SymbolTable *symboltable, Node *i)
    {
        for (auto ii = i->children.begin(); ii != i->children.end(); ii++)
        {
            (*ii)->fcall_post_order(symboltable, *(ii));
        }
        if (i->dtype == "Class" && i->type == identify)
        {
            Record *rec = symboltable->lookup(i->value);
            if (rec == NULL)
            {
                std::cout << "NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
                return;
            }
            Class *cls = dynamic_cast<Class *>(rec);
            if (cls == nullptr)
            {
                std::cout << "CAST FAILED FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
            }
            symboltable->fcall_current_class = cls;
        }
        else if (i->dtype == "Method" && i->type == identify)
        {
            if (symboltable->fcall_current_class->lookupMethod(i->value) == 0)
            {
                std::cout << "NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
                return;
            }
            else
            {
                std::cout << "RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
            }
        }
        else if (i->dtype == "This")
        {
        }
    }
};

#endif
