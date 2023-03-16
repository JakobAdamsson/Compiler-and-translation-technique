/*
Written By
Jakob Adamsson, jaad19@student.bth.se
Emil Gullbrandsson, emgb20@student.bth.se

*/

#ifndef NODE_H SYMBOLTABLE_HH
#define NODE_H SYMBOLTABLE_HH

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
    bool is_declared = false;
    string type, value, dtype;
    list<Node *> children;

    // Constructor
    Node(string t, string v, int l, string data_type = "") : type(t), value(v), lineno(l), dtype(data_type)
    {
    }
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

    void print_node(std::string msg = "PRINT NODE ")
    {
        std::cout << msg << " Value: " << this->value << " Type: " << this->type << " Dtype: " << this->dtype << " Line number: " << this->lineno << std::endl;
    }

    /* create_symboltable() when leaving this function you can expect that:
    1) all variables,methods,classes have been declared.
    2) Every identifier have been checked that they been declared inside their scope before being used.
    3) Checked that that no duplicate declarations exist.
    */
    void create_symboltable(SymbolTable *symboltable)
    {
        for (auto child = children.begin(); child != children.end(); child++)
        {
            if ((*child)->type == "VarDeclaration") // Here we add a variable declaration node to the symboltable
            {
                Variable *new_variable = new Variable();
                new_variable->type = (*child)->type;
                new_variable->dtype = (*child)->dtype;
                new_variable->id = (*child)->value;

                if (symboltable->where_to_add_var == "Class")
                {
                    Variable *var_check = symboltable->current_class->lookupVariable((*child)->value);

                    if (var_check != nullptr)
                    {
                        symboltable->add_error((*child)->lineno, "Variable " + (*child)->value + " already declared in class: " + symboltable->current_class->id);
                    }
                    symboltable->current_class->addVariable(new_variable->id, new_variable);
                }
                else if (symboltable->where_to_add_var == "Method")
                {
                    Variable *var_check = symboltable->current_method->lookupVariable((*child)->value);

                    if (var_check != nullptr)
                    {
                        symboltable->add_error((*child)->lineno, "Variable " + (*child)->value + " already declared in method: " + symboltable->current_method->id);
                    }
                    symboltable->current_method->addVariable(new_variable->id, new_variable);
                }
                symboltable->put(new_variable->id, new_variable);
                (*child)->create_symboltable(symboltable);
            }
            else if ((*child)->type == "Parameters")
            {
                for (auto grand_child = (*child)->children.begin(); grand_child != (*child)->children.end(); grand_child++)
                {

                    Variable *var_check = symboltable->current_method->lookupVariable((*grand_child)->value);

                    if (var_check != nullptr)
                    {
                        symboltable->add_error((*grand_child)->lineno, "Paramater " + (*grand_child)->value + " already declared in method: " + symboltable->current_method->id);
                    }
                    Variable *new_parameter = new Variable();
                    new_parameter->type = (*grand_child)->type;
                    new_parameter->dtype = (*grand_child)->dtype;
                    new_parameter->id = (*grand_child)->value;
                    symboltable->put(new_parameter->id, new_parameter);
                    symboltable->current_method->addVariable(new_parameter->id, new_parameter);
                    symboltable->current_method->addParameter(new_parameter);
                }
            }
            else if ((*child)->type == "MainClass")
            {
                Class *mainclass = new Class();
                mainclass->type = (*child)->type;
                mainclass->dtype = (*child)->dtype;
                mainclass->id = (*child)->value;
                symboltable->put(mainclass->id, mainclass);

                symboltable->current_class = mainclass; // updates current class
                symboltable->enterScope();

                Record *new_variable = new Variable();
                new_variable->type = (*child)->type;
                new_variable->dtype = (*child)->dtype;
                new_variable->id = "this";
                symboltable->put(new_variable->id, new_variable);

                (*child)->create_symboltable(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "ClassDeclaration")
            {
                // Check if class already declared
                Record *class_check = symboltable->lookup((*child)->value);
                if (class_check != NULL)
                {
                    symboltable->add_error((*child)->lineno, "Class " + (*child)->value + " already declared");
                }

                Class *new_class = new Class();

                new_class->type = (*child)->type;
                new_class->dtype = (*child)->dtype;
                new_class->id = (*child)->value;
                symboltable->put(new_class->id, new_class);
                symboltable->where_to_add_var = "Class";
                symboltable->current_class = new_class; // updates current class

                symboltable->enterScope();

                Record *new_variable = new Variable();
                new_variable->type = (*child)->type;
                new_variable->dtype = (*child)->dtype;
                new_variable->id = "this";
                symboltable->put(new_variable->id, new_variable);

                (*child)->create_symboltable(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "Method Identifier") // This is the method of the main class, we don't want to check this one
            {
                // Not sure what to do here
            }
            else if ((*child)->type == "MethodDeclaration")
            {
                // Check if method already declared
                Method *method_check = symboltable->current_class->lookupMethod((*child)->value);
                if (method_check != nullptr)
                {
                    symboltable->add_error((*child)->lineno, "Method " + (*child)->value + " already declared in class: " + symboltable->current_class->id);
                }
                Method *new_method = new Method();
                new_method->type = (*child)->type;
                new_method->dtype = (*child)->dtype;
                new_method->id = (*child)->value;
                symboltable->current_method = new_method;
                symboltable->current_class->addMethod(new_method->id, new_method);
                symboltable->put(new_method->id, new_method);
                symboltable->where_to_add_var = "Method";
                symboltable->enterScope();
                (*child)->create_symboltable(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "Identifier") // Here we check if a identifier is declared
            {

                Record *check_identifier = symboltable->lookup((*child)->value);
                if (!check_identifier)
                {
                    symboltable->add_error((*child)->lineno, "Identifier " + (*child)->value + " not declared");
                }

                (*child)->create_symboltable(symboltable);
            }
            else
            {
                (*child)->create_symboltable(symboltable);
            }
        }
    }

    void semantic_analysis(SymbolTable *symboltable)
    {

        for (auto child = children.begin(); child != children.end(); child++)
        {
            if ((*child)->type == "MainClass")
            {
                symboltable->enterScope();
                (*child)->semantic_analysis(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "ClassDeclaration")
            {
                symboltable->enterScope();
                (*child)->semantic_analysis(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "MethodDeclaration")
            {
                symboltable->enterScope();
                (*child)->semantic_analysis(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "Plus" || (*child)->type == "Divide" || (*child)->type == "Minus" || (*child)->type == "Mult")
            {
                for (auto grand_child = (*child)->children.begin(); grand_child != (*child)->children.end(); grand_child++)
                {
                    if ((*grand_child)->type == "Plus" || (*grand_child)->type == "Divide" || (*grand_child)->type == "Minus" || (*grand_child)->type == "Mult")
                    {
                        (*grand_child)->semantic_analysis(symboltable);
                    }
                    else if ((*grand_child)->type == "Identifier")
                    {
                        Record *check_identifier = symboltable->lookup((*grand_child)->value);
                        if (check_identifier && check_identifier->dtype != "Int") // This confirms that the identifier exists and that if it exists checks if it is of type Int
                        {
                            symboltable->add_error((*grand_child)->lineno, "Wrong type in numerical expression: " + (*grand_child)->type);
                        }
                    }
                    else if ((*grand_child)->type == "FCall")
                    {
                        // HÄR MÅSTE VI HANTERA FUNKTION CALL PÅ NÅGOT SÄTT!
                    }
                    else if ((*grand_child)->type != "Int" && (*grand_child)->type != "Num")
                    {
                        symboltable->add_error((*grand_child)->lineno, "Wrong type in numerical expression: " + (*grand_child)->type);
                    }
                }
            }
            else if ((*child)->type == "Eq" || (*child)->type == "And" || (*child)->type == "Or")
            {
                for (auto grand_child = (*child)->children.begin(); grand_child != (*child)->children.end(); grand_child++)
                {
                }
            }
            else
            {
                (*child)->semantic_analysis(symboltable);
            }
        }
    }
};

#endif
