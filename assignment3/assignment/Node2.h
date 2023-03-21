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
#include "ir.h"

using namespace std;

class Node
{
public:
    // Node attributes
    int id, lineno;
    bool is_declared = false;
    string type, value, dtype;
    std::vector<Node *> children;
    // std::vector<Node *> children(children.begin(), children.end());

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

        // printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.", filename);
        // printf("eyy\n");
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

    void generate_ir(SymbolTable *symboltable)
    {

        generate_ir_content(symboltable);
    }

    void generate_ir_content(SymbolTable *symboltable)
    {
        std::ofstream dotFile("ir.dot");
        dotFile << "digraph G {" << std::endl;
        for (auto &[name, block] : symboltable->Blocks)
        {
            // Print the name of the block and its TAC instructions in a box
            dotFile << "\t" << name << " [shape=box, label=\"" << name << "\\n";
            for (auto &tac : block->tacInstructions)
            {
                dotFile << tac->dump() + "\\n";
            }
            dotFile << "\"];" << std::endl;

            // Create edges to the trueExit and falseExit BBlocks (if they exist)
            if (block->trueExit)
            {
                dotFile << "\t" << name << " -> " << block->trueExit->name << " [label=\"true\"];" << std::endl;
            }
            if (block->falseExit)
            {
                dotFile << "\t" << name << " -> " << block->falseExit->name << " [label=\"false\"];" << std::endl;
            }
        }

        dotFile << "}" << std::endl;
        dotFile.close();
    }

    // for while block i need a header, boolean expression should be inside their ownblock, so that we can visit it over again and again

    void ir_loop(SymbolTable *symboltable, Node *node)
    {
        for (Node *child : node->children)
        {
            if (child->type == "If statement")
            {

                BBlock *true_block = new BBlock();
                true_block->name = "TrueBlock" + std::to_string(symboltable->num_blocks++);
                symboltable->Blocks.insert(std::make_pair(true_block->name, true_block));

                BBlock *false_block = new BBlock();
                false_block->name = "FalseBlock" + std::to_string(symboltable->num_blocks++);
                symboltable->Blocks.insert(std::make_pair(false_block->name, false_block));

                BBlock *join_block = new BBlock();
                join_block->name = "JoinBlock" + std::to_string(symboltable->num_blocks++);
                symboltable->Blocks.insert(std::make_pair(join_block->name, join_block));
                symboltable->block_stack.push_back(join_block);

                true_block->trueExit = join_block;
                false_block->trueExit = join_block;

                symboltable->current_block->trueExit = true_block;
                symboltable->current_block->falseExit = false_block;

                symboltable->current_block = true_block;
                child->children[1]->ir_loop(symboltable, child->children[1]);

                std::cout << symboltable->current_block->name << " Falseblock: " + false_block->name << std::endl;
                symboltable->current_block = false_block;
                child->children[1]->ir_loop(symboltable, child->children[2]);

                symboltable->current_block = join_block;

                if (symboltable->block_stack.size() > 1)
                {
                    BBlock *old_block = symboltable->block_stack.front();
                    symboltable->block_stack.pop_back();
                    symboltable->current_block->trueExit = old_block;
                }
            }
            else if (child->type == "While")
            {
                BBlock *header_block = new BBlock();
                header_block->name = "HeaderWhileBlock" + std::to_string(symboltable->num_blocks++);
                symboltable->Blocks.insert(std::make_pair(header_block->name, header_block));
                symboltable->current_block->trueExit = header_block;
                symboltable->block_stack.push_back(header_block);
                child->children[0]->ir_loop(symboltable, child->children[0]);

                BBlock *bool_block = new BBlock();
                bool_block->name = "BoolBlock" + std::to_string(symboltable->num_blocks++);
                symboltable->Blocks.insert(std::make_pair(bool_block->name, bool_block));
                symboltable->current_block = bool_block;
                bool_block->trueExit = header_block;
                child->children[1]->ir_loop(symboltable, child->children[1]);

                BBlock *join_block = new BBlock();
                join_block->name = "WhileJoinBlock" + std::to_string(symboltable->num_blocks++);
                symboltable->Blocks.insert(std::make_pair(join_block->name, join_block));
                // symboltable->block_stack.push_back(join_block);

                header_block->trueExit = bool_block;
                header_block->falseExit = join_block;

                if (symboltable->block_stack.size() > 0)
                {
                    BBlock *old_block = symboltable->block_stack.back();
                    symboltable->block_stack.pop_back();
                    symboltable->current_block->trueExit = old_block;
                }
                symboltable->current_block = join_block;
            }
            else if (child->type == "Assignment")
            {

                handle_assignment(symboltable, child);
            }

            else
            {
                ir_loop(symboltable, child);
            }
        }
    }

    std::string handle_assignment(SymbolTable *symboltable, Node *node)
    {
        std::string x, y, z, op;

        if (node->type == "Num")
        {

            return node->value;
        }
        else if (node->type == "Plus")
        {
            y = handle_assignment(symboltable, node->children[0]);
            y = handle_assignment(symboltable, node->children[0]);
            return "+";
        }
        else if (node->type == "Minus")
        {
            y = handle_assignment(symboltable, node->children[0]);
            return "-";
        }
        else if (node->type == "Mult")
        {
            y = handle_assignment(symboltable, node->children[0]);
            return "*";
        }
        else if (node->type == "Divide")
        {
            y = handle_assignment(symboltable, node->children[0]);
            return "/";
        }

        return "";
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
                new_variable->dtype = (*child)->value;
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
                new_variable->dtype = (*child)->value;
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
            else if ((*child)->type == "FCall")
            {
                // Tror att vi måste kolla first child här och se till så att det är en fcall eller en newvar, annars tror jag att det ska ge ett felmedellande om variabeln in te är deklaraded?? kanske.. :D
                // TLDR: om det är en ID här så måste vi kolla så att den är deklarerad
                //  MEN VI SPARAR DETTA TILL SIST!!

                // Get the args node
                auto args = std::next((*child)->children.begin(), 2);
                for (auto arg = (*args)->children.begin(); arg != (*args)->children.end(); arg++)
                {
                    if ((*arg)->type == "Identifier")
                    {
                        Record *check_identifier = symboltable->lookup((*arg)->value);
                        if (!check_identifier)
                        {
                            symboltable->add_error((*arg)->lineno, "Identifier " + (*arg)->value + " not declared");
                        }
                    }
                }

                // (*child)->create_symboltable(symboltable); // ska tas bort tror vi :)

                // Kolla om arguments har identifiers, om det finns, gör lookup.
            }
            else
            {
                (*child)->create_symboltable(symboltable);
            }
        }
    }

    void
    semantic_analysis(SymbolTable *symboltable)
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
                std::vector<Node *> grand_children((*child)->children.begin(), (*child)->children.end());
                Node *method_type = grand_children[1];

                Node *return_node = grand_children.back();

                std::string return_dtype;
                if (return_node->type == "Identifier")
                {
                    Record *check_identifier = symboltable->lookup(return_node->value);
                    if (!check_identifier)
                    {
                        symboltable->add_error(return_node->lineno, "Identifier " + return_node->value + " not declared");
                    }
                    else
                    {
                        return_dtype = check_identifier->dtype;
                    }
                }
                else if (return_node->type == "Int")
                {
                    return_dtype = "Int";
                }
                else if (return_node->type == "ArrDec")
                {
                    std::vector<Node *> ArrDec_children(return_node->children.begin(), return_node->children.end());
                    if (ArrDec_children[1]->type == "FCall")
                    {
                        std::string ArrDec_fcall = validate_fcall(symboltable, ArrDec_children[1]);
                        return_dtype = validate_fcall(symboltable, ArrDec_children[1]);
                    }
                    else
                    {
                        return_dtype = "Int";
                    }
                }
                else if (return_node->type == "True" || return_node->type == "false" || return_node->type == "Boolean")
                {
                    return_dtype = "Boolean";
                }
                else if (return_node->type == "NewVar")
                {
                    return_dtype = return_node->value;
                }
                else if (return_node->type == "Num")
                {
                    return_dtype = "Int";
                }
                else if (return_node->type == "this")
                {

                    Record *this_record = symboltable->lookup("this");
                    Record *this_class = symboltable->lookup(this_record->dtype);
                    Class *check_class_class = dynamic_cast<Class *>(this_class);
                    return_dtype = check_class_class->id;
                }
                else if (return_node->type == "FCall")
                {
                    return_dtype = validate_fcall(symboltable, return_node);
                }
                else
                {
                    return_dtype = check_datatype(symboltable, return_node);
                }
                if (return_dtype != method_type->dtype)
                {
                    symboltable->add_error((*child)->lineno, "Wrong return type : " + return_dtype + " != " + method_type->dtype);
                }

                (*child)->semantic_analysis(symboltable);
                symboltable->exitScope();
            }
            else if ((*child)->type == "Plus" || (*child)->type == "Divide" || (*child)->type == "Minus" || (*child)->type == "Mult" || (*child)->type == "Gt" || (*child)->type == "Lt")
            {

                for (auto grand_child = (*child)->children.begin(); grand_child != (*child)->children.end(); grand_child++)
                {
                    if ((*grand_child)->type == "Plus" || (*grand_child)->type == "Divide" || (*grand_child)->type == "Minus" || (*grand_child)->type == "Mult" || (*grand_child)->type == "Gt" || (*grand_child)->type == "Lt")
                    {
                        (*grand_child)->semantic_analysis(symboltable);
                    }
                    else if ((*grand_child)->type == "Identifier")
                    {
                        Record *check_identifier = symboltable->lookup((*grand_child)->value);

                        if (check_identifier && check_identifier->dtype != "Int") // We dont need to check if the identifier have been declared here, that have been done in create symbol table. we only need to an error msg if it is not of type Int
                        {
                            if ((!(*grand_child)->children.size() == 1 && check_identifier->dtype == "IntArr")) // This is if the length of an array is used.
                            {
                                symboltable->add_error((*grand_child)->lineno, "Wrong type in numerical expression: " + (*grand_child)->type);
                            }
                            else if ((!(*grand_child)->children.size() == 1 && check_identifier->dtype == "Int")) // kolla här
                            {

                                symboltable->add_error((*grand_child)->lineno, "This type doesnt have length " + (*grand_child)->type);
                            }
                            else if (check_identifier->dtype != "Int")
                            {
                                symboltable->add_error((*grand_child)->lineno, check_identifier->id + " is of type: " + check_identifier->dtype + " not of type: Int");
                            }
                        }
                        else if ((*grand_child)->children.size() != 0)
                        {
                            symboltable->add_error((*grand_child)->lineno, check_identifier->dtype + " Identifier: " + (*grand_child)->value + " does not have length");
                        }
                    }
                    else if ((*grand_child)->type == "ArrDec")
                    {

                        std::string arrdec_string = check_datatype(symboltable, (*grand_child));
                    }
                    else if ((*grand_child)->type == "FCall")
                    {
                        // HÄR MÅSTE VI HANTERA FUNKTION CALL PÅ NÅGOT SÄTT!
                        // Funktionscallet måste bli INT här.
                    }
                    else if ((*grand_child)->type != "Int" && (*grand_child)->type != "Num")
                    {
                        symboltable->add_error((*grand_child)->lineno, "Wrong type in numerical expression: " + (*grand_child)->type);
                    }
                }
            }
            else if ((*child)->type == "And" || (*child)->type == "Or")
            {
                for (auto grand_child = (*child)->children.begin(); grand_child != (*child)->children.end(); grand_child++)
                { // MAYBE WE HAVE NOT THOUGT ABOUT EVERY CASE FOR NOT :)
                    if ((*grand_child)->type == "And" || (*grand_child)->type == "Or" || (*grand_child)->type == "Gt" || (*grand_child)->type == "Lt" || (*grand_child)->type == "==")
                    {

                        (*grand_child)->semantic_analysis(symboltable);
                    }
                    else if ((*grand_child)->type == "Not")
                    {
                        std::string test_dtype = check_datatype(symboltable, (*grand_child));
                    }
                    else if ((*grand_child)->type == "Identifier")
                    {
                        Record *check_identifier = symboltable->lookup((*grand_child)->value);
                        if (check_identifier && check_identifier->dtype != "Boolean") // We dont need to check if the identifier have been declared here, that have been done in create symbol table. we only need to an error msg if it is not of type Int
                            symboltable->add_error((*grand_child)->lineno, "Wrong type in boolean expression: " + (*grand_child)->type);
                    }
                    else if ((*grand_child)->type != "Boolean") // may have to do something here if it is valid to do something like "int && int"
                    {
                        symboltable->add_error((*grand_child)->lineno, "Wrong type in boolean expression: " + (*grand_child)->type);
                    }
                }
            }
            else if ((*child)->type == "==")
            {
                auto grand_child1 = std::next((*child)->children.begin(), 0);
                Record *grand_child_exists = symboltable->lookup((*grand_child1)->value);
                std::string grand_child_dtype1 = check_dtype_eq(symboltable, (*grand_child1));

                auto grand_child2 = std::next((*child)->children.begin(), 1);
                std::string grand_child_dtype2 = check_dtype_eq(symboltable, (*grand_child2));
                if (grand_child_dtype1 != grand_child_dtype2)
                {
                    symboltable->add_error((*child)->lineno, "Type mismatch in equality expression: " + grand_child_dtype1 + " and " + grand_child_dtype2);
                }
            }
            else if ((*child)->type == "VarDeclaration")
            {
                // This section will is for when a new variable is declared that is of class. We need to check if that class exists.
                Variable *var_declaration = new Variable();
                var_declaration->type = (*child)->type;
                var_declaration->dtype = (*child)->dtype;
                var_declaration->id = (*child)->value;

                if (var_declaration->dtype != "Int" && var_declaration->dtype != "Boolean" && var_declaration->dtype != "IntArr")
                {
                    Record *type_check = symboltable->lookup((*child)->dtype);
                    if (type_check == nullptr)
                    {

                        symboltable->add_error((*child)->lineno, "Type " + (*child)->dtype + " not declared");
                    }
                }
            }
            else if ((*child)->type == "ArrModifier")
            {
                // Check first child
                auto grand_child1 = std::next((*child)->children.begin(), 0);
                Record *grand_child_exists = symboltable->lookup((*grand_child1)->value);
                if (grand_child_exists->dtype != "IntArr")
                {
                    symboltable->add_error((*child)->lineno, "Not an array" + (*grand_child1)->value);
                }

                // Check second child
                auto grand_child2 = std::next((*child)->children.begin(), 1);
                std::string grand_child_dtype2 = check_dtype_arrmodifier(symboltable, (*grand_child2));

                grand_child_dtype2 = check_datatype(symboltable, (*grand_child2));
                if (grand_child_dtype2 != "Int")
                {
                    symboltable->add_error((*child)->lineno, "Not a valid datatype for index: " + (*grand_child2)->value);
                }

                // Check third child
                auto grand_child3 = std::next((*child)->children.begin(), 2);
                Record *check_for_thing = symboltable->lookup((*grand_child3)->value);

                std::string grand_child_dtype3 = check_datatype(symboltable, (*grand_child3));

                if (!((grand_child_dtype3 == "IntArr" && (*grand_child3)->children.size() == 1)) && ((grand_child_dtype3 == "Int") && (*grand_child3)->children.size() == 1) && (*grand_child3)->type != "ArrDec")
                {
                    symboltable->add_error((*child)->lineno, "Not a valid datatype for value of arraymodifier: " + (*grand_child3)->value);
                }
            }
            else if ((*child)->type == "Assignment")
            {
                // Here we will check that each assignment will have the same type on both sides of the equalssign.
                // We assume that any encountered PLUS MINUS MULT DIVIDE LT Gt have been correctly evaluated.
                // We should also be able to assume that any AND OR and == also are correctly but this is not implemented yet.
                auto grand_child1 = std::next((*child)->children.begin(), 0);
                Record *grand_child_exists = symboltable->lookup((*grand_child1)->value);
                std::string grand_child_dtype1;
                if (grand_child_exists)
                {
                    grand_child_dtype1 = grand_child_exists->dtype;
                }
                else
                {
                    grand_child_dtype1 = (*grand_child1)->value + " isnon";
                }
                auto grand_child2 = std::next((*child)->children.begin(), 1);

                std::string grand_child_dtype2;

                if ((*grand_child2)->type == "Identifier")
                {

                    Record *grand_child2_exists = symboltable->lookup((*grand_child2)->value);
                    if (!((*grand_child2)->children.size() == 1 && grand_child2_exists->dtype == "IntArr")) // This is if the length of an array is used.
                    {
                        grand_child_dtype2 = grand_child2_exists->dtype;
                    }
                    else
                    {
                        grand_child_dtype2 = "Int";
                    }
                }
                else if ((*grand_child2)->type == "Boolean" || (*grand_child2)->type == "And" || (*grand_child2)->type == "Or" || (*grand_child2)->type == "Lt" || (*grand_child2)->type == "Gt" || (*grand_child2)->type == "==")
                {
                    grand_child_dtype2 = "Boolean";
                }
                else if ((*grand_child2)->type == "Not")
                {
                    grand_child_dtype2 = check_datatype(symboltable, (*grand_child2));
                }

                else if ((*grand_child2)->type == "Int" || (*grand_child2)->type == "Num" || (*grand_child2)->type == "Plus" || (*grand_child2)->type == "Divide" || (*grand_child2)->type == "Minus" || (*grand_child2)->type == "Mult")
                {
                    grand_child_dtype2 = "Int";
                }
                else if ((*grand_child2)->type == "FCall")
                {

                    // Do something

                    grand_child_dtype2 = validate_fcall(symboltable, (*grand_child2));
                    // Kolla arguments here?
                }
                else if ((*grand_child2)->type == "IntArrDec")
                {
                    grand_child_dtype2 = check_datatype(symboltable, (*grand_child2));
                }
                else if ((*grand_child2)->type == "ArrDec")
                {
                    grand_child_dtype2 = check_datatype(symboltable, (*grand_child2));
                }
                else if ((*grand_child2)->type == "this")
                {
                    Record *this_record = symboltable->lookup("this");
                    grand_child_dtype2 = this_record->dtype;
                }
                else if ((*grand_child2)->type == "NewVar")
                {

                    Record *newvar_record = symboltable->lookup((*grand_child2)->value);
                    if (!newvar_record)
                    {
                        symboltable->add_error((*grand_child2)->lineno, "NewVar class doesnt exists");
                        grand_child_dtype2 = "grand_child_dtype2 doesnt exist";
                    }
                    else
                    {
                        grand_child_dtype2 = newvar_record->id;
                    }
                }
                if (grand_child_dtype1 != grand_child_dtype2)
                {
                    symboltable->add_error(((*grand_child1)->lineno), "Wrong types for assignment of: " + grand_child_dtype1 + " + " + grand_child_dtype2);
                }

                (*child)->semantic_analysis(symboltable);
            }
            else
            {
                (*child)->semantic_analysis(symboltable);
            }
        }
    }

    // ONLY USE WHEN CHECKING ARRAY MODIFIER!
    std::string check_dtype_arrmodifier(SymbolTable *symboltable, Node *node)
    {
        std::string node_dtype;
        if (node->type == "Plus" || (node)->type == "Divide" || (node)->type == "Minus" || (node)->type == "Mult" || (node)->type == "Int" || (node)->type == "Num")
        {
            node_dtype = "Int";
        }
        else if (node->type == "Identifier")
        {
            Record *node_exists = symboltable->lookup((node)->value);
            if (!(node->children.size() == 1 && node_exists->dtype == "IntArr")) // This is if the length of an array is used.
            {
                node_dtype = node_exists->dtype;
            }
        }
        else if ((node)->type == "FCall")
        {
            // Do something
        }
        return node_dtype;
    }
    std::string check_dtype_eq(SymbolTable *symboltable, Node *node)
    {
        std::string node_dtype;
        if ((node)->type == "Identifier")
        {

            Record *grand_child2_exists = symboltable->lookup(node->value);
            if (!(node->children.size() == 1 && grand_child2_exists->dtype == "IntArr")) // This is if the length of an array is used.
            {
                node_dtype = grand_child2_exists->dtype;
            }
            else
            {
                node_dtype = "Int";
            }
        }
        else if (node->type == "Boolean" || node->type == "And" || node->type == "Or" || node->type == "Lt" || node->type == "Gt")
        {
            node_dtype = "Boolean";
        }
        else if (node->type == "==")
        {

            node_dtype = "Boolean";
            node->semantic_analysis(symboltable);
        }
        else if (node->type == "Int" || node->type == "Num" || node->type == "Plus" || node->type == "Divide" || node->type == "Minus" || node->type == "Mult")
        {
            node_dtype = "Int";
        }
        else if (node->type == "FCall")
        {
            // Do something
        }
        else if (node->type == "IntArr")
        {
            node_dtype = "IntArr"; // This mamybe need changing
        }
        return node_dtype;
    }

    std::string validate_fcall(SymbolTable *symboltable, Node *node)
    {

        if (node->type == "FCall")
        {

            fcall_check_arguments(symboltable, node);

            auto child1 = std::next(node->children.begin(), 0);
            auto child2 = std::next(node->children.begin(), 1);
            if ((*child1)->type == "Identifier")
            {
                // Lookvariabel up på identifiern för current_class för att kolla att den variabeln är deklarerad
                Record *check_identifier = symboltable->lookup((*child1)->value);
                if (!check_identifier)
                {
                    symboltable->add_error((*child1)->lineno, "Identifier " + (*child1)->value + " not declared");
                }

                // Göra en lookup på den datatypen för att kolla att den classen är deklarerad
                Record *check_class = symboltable->lookup(check_identifier->dtype); // BLIR FEL HÄR!
                if (!check_class)
                {
                    symboltable->add_error((*child1)->lineno, "Class " + check_identifier->dtype + " not declared");
                }
                Class *check_class_class = dynamic_cast<Class *>(check_class);

                if (check_class_class == nullptr)
                {
                    symboltable->add_error((*child1)->lineno, "Class cast failed: " + check_identifier->dtype);
                }

                // göra en lookupmethod lookupmethod för child->value på den klassen
                Method *check_method = check_class_class->lookupMethod((*child2)->value);
                if (check_method == nullptr)
                {
                    symboltable->add_error((*child2)->lineno, "Method " + (*child2)->value + " not declared in class: " + check_class_class->id);
                    return "NoDtype";
                }
                return check_method->dtype;
            }
            else if ((*child1)->type == "NewVar")
            {
                Record *newvar_record = symboltable->lookup2((*child1)->value);
                Class *newvar_class = dynamic_cast<Class *>(newvar_record);
                if (newvar_class == nullptr)
                {
                    symboltable->add_error((*child1)->lineno, "Class cast failed: " + (*child1)->value);
                    return "NoDtype";
                }
                Method *newvar_method = newvar_class->lookupMethod((*child2)->value);
                if (newvar_method == nullptr)
                {
                    symboltable->add_error((*child2)->lineno, "Method " + (*child2)->value + " not declared in class: " + newvar_class->id);
                    return "NoDtype";
                }
                return newvar_method->dtype;
                // göra en look up child1 dtype som ska vara en klass
                //  göra en lookupmethod för child -> value på den klassen
            }
            else if ((*child1)->type == "FCall")
            {
                std::string return_type = validate_fcall(symboltable, (*child1));

                Record *fcall_record = symboltable->lookup(return_type);
                if (!fcall_record)
                {
                    symboltable->add_error((*child1)->lineno, "Method " + (*child1)->value + " not declared in class: ");
                    return "Nothingfound";
                }

                Class *fcall_class = dynamic_cast<Class *>(fcall_record);
                Method *fcall_method = fcall_class->lookupMethod((*child2)->value);
                if (fcall_method == nullptr)
                {
                    symboltable->add_error((*child2)->lineno, "Method " + (*child2)->value + " not declared in class: " + fcall_class->id);
                    return "NoDtype";
                }
                return fcall_method->dtype;
            }
            else if ((*child1)->type == "this")
            {
                Record *this_record = symboltable->lookup("this");
                Record *this_class = symboltable->lookup(this_record->dtype);
                Class *check_class_class = dynamic_cast<Class *>(this_class);

                Method *check_method = check_class_class->lookupMethod((*child2)->value);
                if (check_method == nullptr)
                {
                    symboltable->add_error((*child2)->lineno, "Method " + (*child2)->value + " not declared in class: " + check_class_class->id);
                    return "NoDtype";
                }
                return check_method->dtype;
            }
            else
            {
                return "";
            }
        }
        return "";
    }

    void fcall_check_arguments(SymbolTable *symboltable, Node *node)
    {

        auto class_child = std::next(node->children.begin(), 0);
        auto method_child = std::next(node->children.begin(), 1);
        auto args_child = std::next(node->children.begin(), 2);
        Class *check_class_class;
        if ((*class_child)->type == "this")
        {
            Record *this_record = symboltable->lookup("this");
            Record *this_class = symboltable->lookup(this_record->dtype);
            check_class_class = dynamic_cast<Class *>(this_class);
        }
        else if ((*class_child)->type == "NewVar")
        {

            Record *newvar_record = symboltable->lookup2((*class_child)->value);

            check_class_class = dynamic_cast<Class *>(newvar_record);
        }
        else if ((*class_child)->type == "FCall")
        {
            std::string class_name = (*class_child)->validate_fcall(symboltable, (*class_child));

            Record *this_class = symboltable->lookup(class_name);

            if (!this_class)
            {
                symboltable->add_error((*class_child)->lineno, "Method " + (*class_child)->value + " not declared in class: ");
                return;
            }
            check_class_class = dynamic_cast<Class *>(this_class);
        }
        else if ((*class_child)->type == "Identifier")
        {
            Record *check_identifier = symboltable->lookup((*class_child)->value);
            Record *check_class = symboltable->lookup(check_identifier->dtype);
            check_class_class = dynamic_cast<Class *>(check_class);
        }

        Method *check_method = check_class_class->lookupMethod((*method_child)->value);
        if (!check_method)
        {
            return;
        }
        if ((*args_child)->children.size() != check_method->Parameters.size())
        {
            symboltable->add_error((*args_child)->lineno, "Wrong number of arguments in function call");
            return;
        }

        std::vector<Node *> arg_vector((*args_child)->children.begin(), (*args_child)->children.end());

        int index = 0;
        std::string temp;
        while (index < check_method->Parameters.size())
        {

            if (arg_vector[index]->type == "Plus" || arg_vector[index]->type == "Divide" || arg_vector[index]->type == "Minus" || arg_vector[index]->type == "Mult" || arg_vector[index]->type == "Int" || arg_vector[index]->type == "Num")
            {
                temp = "Int";
            }
            else if (arg_vector[index]->type == "Boolean" || arg_vector[index]->type == "And" || arg_vector[index]->type == "Or" || arg_vector[index]->type == "Lt" || arg_vector[index]->type == "Gt" || arg_vector[index]->type == "==")
            {
                temp = "Boolean";
            }
            else if (arg_vector[index]->type == "FCall")
            {
                temp = validate_fcall(symboltable, arg_vector[index]);
            }
            else if (arg_vector[index]->type == "Identifier")
            {
                Record *check_identifier = symboltable->lookup(arg_vector[index]->value);
                temp = check_identifier->dtype;
            }
            else if (arg_vector[index]->type == "this")
            {
                Record *this_record = symboltable->lookup("this");
                Record *this_class = symboltable->lookup(this_record->dtype);
                check_class_class = dynamic_cast<Class *>(this_class);
                temp = check_class_class->id;
            }
            else if (arg_vector[index]->type == "IntArr")
            {
                temp = "IntArr";
            }
            else
            {
                temp = arg_vector[index]->dtype;
            }

            if (check_method->Parameters[index]->dtype != temp)
            {
                symboltable->add_error((*args_child)->lineno, "Wrong type of argument in function call");
            }

            index++;
        }
    }

    std::string check_datatype(SymbolTable *symboltable, Node *node)
    {
        std::vector<Node *> children(node->children.begin(), node->children.end());
        std::string return_dtype;
        if (node->type == "Not")
        {
            return_dtype = check_datatype(symboltable, children[0]);

            if (return_dtype != "Boolean")
            {
                symboltable->add_error(node->lineno, "Wrong type for Not");
            }
        }
        else if (node->type == "Identifier")
        {
            Record *id_record = symboltable->lookup(node->value);
            if (!id_record)
            {
                return_dtype = "";
            }

            else
            {

                return_dtype = id_record->dtype;
            }
        }
        else if ((node->type == "Boolean"))
        {
            return_dtype = "Boolean";
        }
        else if ((node->type == "FCall"))
        {
            return_dtype = validate_fcall(symboltable, node);
        }
        else if (node->type == "Num")
        {
            return_dtype = "Int";
        }
        else if (node->type == "ArrDec")
        {
            std::string check_for_intarr = check_datatype(symboltable, children[0]);
            if (check_for_intarr != "IntArr")
            {
                symboltable->add_error(node->lineno, "Not an array");
            }
            std::string check_index = check_datatype(symboltable, children[1]);

            if (check_index != "Int")
            {
                symboltable->add_error(node->lineno, "Not valid index for array");
            }

            if (children.size() == 3)
            {
                symboltable->add_error(node->lineno, "Wrong use of length");
            }
            return_dtype = "Int";
        }
        else if (node->type == "IntArrDec")
        {

            std::string check_index_type = check_datatype(symboltable, children[2]);
            if (check_index_type != "Int" && check_index_type != "Num")
            {
                symboltable->add_error(node->lineno, " wrong index type");
            }

            if (children[0]->type == "New")
            {
                return_dtype = "IntArr";
            }
            else
            {
                return_dtype = "Int";
            }
        }
        else if (node->type == "Plus" || node->type == "Divide" || node->type == "Minus" || node->type == "Mult")
        {
            return_dtype = "Int";
        }

        return return_dtype;
    }
};

#endif
