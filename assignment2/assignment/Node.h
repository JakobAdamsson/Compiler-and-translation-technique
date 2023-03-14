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

    string type, value, dtype;
    list<Node *> children;

    // Identifiers
    std::string mclass = "MainClass";
    std::string classdec = "ClassDeclaration";
    std::string vardec = "VarDeclaration";
    std::string vardecs = "VarDeclarations";
    std::string midentify = "MethodDeclaration";
    std::string identify = "Identifier";
    std::string sment = "LRStatement";
    std::string parameter = "Parameters";
    std::string elsestate = "ELSE";
    std::string expression = "Expression";
    std::string fcall = "FCall";
    std::string assignment = "Assignment";
    std::string newvar = "NewVar";
    std::string thiss = "this";
    std::string minus = "Minus";
    std::string plus = "Plus";
    std::string mult = "Mult";
    std::string divide = "Divide";
    std::string ifstate = "If statement";
    std::string gt = "Gt";
    std::string lt = "Lt";
    std::string eq = "==";
    std::string arrmodifier = "ArrModifier";
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

    void print_node()
    {
        std::cout << "PRINT NODE Value: " << this->value << " Type: " << this->type << " Dtype: " << this->dtype << " Line number: " << this->lineno << std::endl;
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
        for (auto child : i->children)
        {
            Variable *new_param = new Variable();
            new_param->id = child->value;
            new_param->type = child->type;
            new_param->dtype = child->dtype;
            symboltable->current_method->addParameter(child->value, symboltable->variable_type, new_param);
            symboltable->put(child->value, new_param);
        }
    }
    void VarDec_method(SymbolTable *symboltable, Node *i)
    {
        Variable *vardec_test = new Variable();
        // Fill data
        vardec_test->id = i->value;
        vardec_test->type = i->type;
        vardec_test->dtype = i->dtype;
        symboltable->current_method->addVariable(vardec_test->id, vardec_test);

        // Add the record to the current scope record
        symboltable->put(vardec_test->id, vardec_test);
    }

    void VarDec_class(SymbolTable *symboltable, Node *i)
    {
        Variable *vardec_test = new Variable();
        // Fill data
        vardec_test->id = i->value;
        vardec_test->type = i->type;
        vardec_test->dtype = i->dtype;
        symboltable->current_class->addVariable(vardec_test->id, vardec_test);

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

        symboltable->current_class->addMethod(methoddec_test->id, methoddec_test);
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

        Variable *this_ = new Variable();
        this_->id = "this";
        this_->type = i->value;
        this_->dtype = i->value;
        mainclass_test->addVariable(this_->id, this_);
        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.

        symboltable->put(mainclass_test->id, mainclass_test);
        // Enter new scope
        symboltable->enterScope(this->mclass + "(" + i->value + ")");
        symboltable->put(this_->id, this_);
        i->create_symboltable(symboltable);

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
        classdec_test->dtype = "Class";

        Variable *this_ = new Variable();
        this_->id = "this";
        this_->type = i->value;
        this_->dtype = i->value;
        classdec_test->addVariable(this_->id, this_);

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.

        // Enter new scope
        symboltable->put(classdec_test->id, classdec_test);

        symboltable->enterScope(this->classdec + "(" + i->value + ")");
        symboltable->put(this_->id, this_);
        i->create_symboltable(symboltable);

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

                symboltable->exitScope();
            }
            else if ((*i)->type == this->classdec)
            {
                symboltable->enterScope();
                (*i)->semantic_analysis_variables(symboltable);
                symboltable->exitScope();
            }
            else if ((*i)->type == this->assignment)
            {
                for (auto ii = (*i)->children.begin(); ii != (*i)->children.end(); ii++)
                {
                    Record *rec = symboltable->lookup((*ii)->value);
                    if ((*ii)->type == this->identify)
                    {
                        if (rec == NULL)
                        {
                            std::cout << "ERROR IN SEMANTIC ANALYSIS VARIABLES NO RECORD FOUND FOR-> "
                                      << "ID: " << (*ii)->value << " TYPE: " << (*ii)->type << " LINENUMBER: " << (*ii)->lineno << std::endl;
                            // return;
                        }
                    }
                }
            }
            else
            {
                (*i)->semantic_analysis_variables(symboltable);
            }
        }
    }

    bool isLeaf() const
    {
        return children.empty();
    }

    std::string check_leafs(Node *node, SymbolTable *symboltable)
    {

        if (node->isLeaf())
        {
            // Return the node's 'hej' value

            if (node->type == identify)
            {
                Record *rec = symboltable->lookup(node->value);
                if (!rec)
                {
                    std::cout << "ERROR IN CHECK LEAFES NO RECORD FOUND FOR-> "
                              << "ID: " << node->value << " TYPE: " << node->type << " Dtype: " << node->dtype << " LINENUMBER: " << node->lineno << std::endl;
                    return "";
                }
                return rec->dtype;
            }
            if (node->type == thiss)
            {
                Record *rec = symboltable->lookup("this");
                if (!rec)
                {
                    std::cout << "ERROR IN CHECK LEAFES NO RECORD FOUND FOR-> "
                              << "ID: " << node->value << " TYPE: " << node->type << " Dtype: " << node->dtype << " LINENUMBER: " << node->lineno << std::endl;
                    return "";
                }
                return rec->dtype;
            }

            return node->dtype;
        }

        if (node->type == fcall)
        {
            Class *method_caller = fcall_check_first_child(symboltable, node);
            auto method_node = std::next(node->children.begin(), 1);
            if (method_caller)
            {
                Method *method_function = method_caller->lookupMethod((*method_node)->value);
                if (method_function)
                {
                    return method_function->dtype;
                }
            }
            return "";
        }

        else
        {
            // Recursively check all child nodes
            std::string common = "";
            for (auto child : node->children)
            {
                std::string child_dtype = check_leafs(child, symboltable);
                if (common.empty())
                {
                    common = child_dtype;
                }
                else if ((common == "Int" && child_dtype == "IntArr") || (common == "IntArr" && child_dtype == "Int"))
                {
                    return common;
                }
                else if (child_dtype != common)
                {
                    std::cout << "THESE ARE NOT EQUAL!" << child_dtype << " == " << common << " children size = " << child->children.size() << std::endl;
                    child->print_node();
                    return "";
                }
            }
            return common;
        }
    }

    void check_assignment(SymbolTable *symboltable, Node *i)
    {

        for (auto itr = i->children.begin(); itr != i->children.end(); itr++)
        {
            if ((*itr)->type == minus || (*itr)->type == mult || (*itr)->type == divide || (*itr)->type == plus || (*itr)->type == assignment)
            {
                std::string temp = check_leafs(*itr, symboltable);
                auto first_child = std::next((*itr)->children.begin(), 0);
                if (temp == "")
                {
                    std::cout << "ERROR IN CHECK ASSIGNMENT TYPE ERROR-> "
                              << "ID: " << (*first_child)->value << " TYPE: " << (*first_child)->type << " DTYPE: " << temp << " LINENUMBER: " << (*first_child)->lineno << std::endl;
                    (*itr)->print_node();
                }
            }
            else if ((*itr)->type == this->mclass)
            {
                symboltable->enterScope();
                check_assignment(symboltable, *itr);
                symboltable->exitScope();
            }

            else if ((*itr)->type == this->classdec)
            {
                symboltable->enterScope();
                check_assignment(symboltable, *itr);
                symboltable->exitScope();
            }
            else if ((*itr)->type == this->midentify)
            {
                symboltable->enterScope();
                check_assignment(symboltable, *itr);
                symboltable->exitScope();
            }
            else if ((*itr)->type == lt || (*itr)->type == gt || (*itr)->type == eq)
            {

                std::string swag_yolo = check_leafs((*itr), symboltable);

                if (swag_yolo == "")
                {
                    std::cout << "ERROR IN CHECK ASSIGNMENT INVALID COMPARISON-> "
                              << "ID: " << (*itr)->value << " TYPE: " << (*itr)->type << " DTYPE: " << swag_yolo << " LINENUMBER: " << (*itr)->lineno << std::endl;
                }

                check_assignment(symboltable, *itr);
            }
            else
            {
                check_assignment(symboltable, *itr);
            }
        }
    }

    Class *fcall_check_first_child(SymbolTable *symboltable, Node *i)
    {
        if (i->type == newvar)
        {
            Class *rec2 = symboltable->lookup2(i->value);
            if (rec2)
            {
                return rec2;
            }

            Record *rec = symboltable->lookup(i->value);
            i->print_node();
            if (rec == NULL)
            {
                std::cout << "ERROR IN (fcall_chick_first_child)NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << " LINENUMBER: " << i->lineno << std::endl;
                return NULL;
            }
            rec->printRecord();
            symboltable->printCurrent();
            Class *cls = dynamic_cast<Class *>(rec);
            if (cls == nullptr)
            {
                std::cout << "NO CLASS FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << " LINENUMBER: " << i->lineno << std::endl;
                symboltable->printCurrent();
                return NULL;
            }
            return cls;
        }
        else if (i->type == thiss)
        {
            Record *rec = symboltable->lookup("this");

            if (rec == NULL)
            {
                std::cout << "ERROR IN (fcall_chick_first_child)NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << " LINENUMBER: " << i->lineno << std::endl;
                return NULL;
            }
            Class *cls = symboltable->lookup2(rec->type);
            // rec2->printRecord();
            // Class *cls = dynamic_cast<Class *>(rec2);
            if (cls == nullptr)
            {
                std::cout << "ERROR IN (fcall_chick_first_child)NO CLASS FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << " LINENUMBER: " << i->lineno << std::endl;
                return NULL;
            }
            return cls;

            // Det kan också vara en identifier och det kan vara ett fcall.
        }
        else if (i->type == identify)
        {
            Record *rec = symboltable->lookup(i->value);
            if (rec == NULL)
            {
                std::cout << "(FCall identifier)NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->dtype << " LINENUMBER: " << i->lineno << std::endl;
                return NULL;
            }
            Record *rec2 = symboltable->lookup(rec->dtype);
            if (rec2 == NULL)
            {
                std::cout << "(FCall identifier)NO RECORD2 FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->dtype << " LINENUMBER: " << i->lineno << std::endl;
                return NULL;
            }
            Class *cls = dynamic_cast<Class *>(rec2);
            if (cls == nullptr)
            {
                std::cout << "(FCall identifier)NO CLASS FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << " LINENUMBER: " << i->lineno << std::endl;
                return NULL;
            }
            return cls;
        }
        else
        {
            auto child1 = std::next(i->children.begin(), 0);

            return fcall_check_first_child(symboltable, (*child1));
        }

        return NULL;
    }

    std::string semantic_analysis_methods(SymbolTable *symboltable, Node *i)
    {
        std::string dtype_check;
        for (auto itr = i->children.begin(); itr != i->children.end(); itr++)
        {
            if ((*itr)->type == this->mclass)
            {
                symboltable->enterScope();
                semantic_analysis_methods(symboltable, *itr);
                symboltable->exitScope();
            }
            else if ((*itr)->type == this->midentify)
            {
                // Now we are in method scope
                symboltable->enterScope();
                auto method_type = std::next((*itr)->children.begin(), 1);
                auto return_type = std::next((*itr)->children.begin(), 5);
                std::string return_type_string = (*return_type)->dtype;
                if ((*return_type)->type == identify || (*return_type)->type == thiss)
                {
                    if ((*return_type)->type == thiss)
                    {
                        Record *rec = symboltable->lookup(thiss);
                        if (rec)
                        {
                            return_type_string = rec->dtype;
                        }
                    }
                    else
                    {
                        Record *rec_return = symboltable->lookup((*return_type)->value);
                        if (rec_return)
                        {
                            return_type_string = rec_return->dtype;
                        }
                    }
                }
                else if ((*return_type)->type == "Plus" || (*return_type)->type == "Minus" || (*return_type)->type == "Divide" || (*return_type)->type == "Mult")
                {
                    return_type_string = check_leafs(*return_type, symboltable);
                }

                if (((*method_type)->dtype != return_type_string))
                {
                    std::cout << (*method_type)->dtype << " == " << return_type_string << std::endl;

                    std::cout << "ERROR Method type dont match return type for: " << (*method_type)->value << " LINENUMBER: " << (*method_type)->lineno << std::endl;
                }

                (*itr)->semantic_analysis_methods(symboltable, *itr);

                symboltable->exitScope();
            }
            else if ((*itr)->type == this->classdec)
            {
                symboltable->enterScope();
                (*itr)->semantic_analysis_methods(symboltable, *itr);
                symboltable->exitScope();
            }
            else if ((*itr)->type == this->fcall)
            {
                auto class_node = std::next((*itr)->children.begin(), 0);
                auto argument_node = std::next((*itr)->children.begin(), 2);
                Class *hej = fcall_check_first_child(symboltable, (*class_node));

                auto method_node = std::next((*itr)->children.begin(), 1);

                Method *tja = hej->lookupMethod((*method_node)->value);
                if ((*argument_node)->children.size() != tja->Parameters2.size())
                {
                    std::cout << "ERROR METHOD PARAMS DOES NOT EQUAL THE ARGUMETNTS IN SIZE: " << (*method_node)->value << " LINENUMBER:  " << (*method_node)->lineno << std::endl;
                }
                dtype_check = tja->dtype;
                check_arguments(symboltable, (*argument_node), tja->Parameters2);
            }
            else
            {
                (*itr)->semantic_analysis_methods(symboltable, *itr);
            }
        }
        return dtype_check;
    }

    void check_arguments(SymbolTable *symboltable, Node *itr, std::vector<Variable *> params)
    {
        int i = 0;
        auto thirdchild = std::next(itr->children.begin(), 1);
        for (auto child : itr->children)
        {

            if (child->type == identify)
            {
                Record *rec = symboltable->lookup(child->value);
                if (rec->dtype != params[i]->dtype)
                {

                    std::cout << "ERROR (FCALL) WRONG TYPE FOR ARGUMENT: " << (*thirdchild)->value << " On index: " << i << "LINE NUMBER: " << (*thirdchild)->lineno << std::endl;
                }
            }
            else if (child->type == mult || child->type == divide || child->type == minus || child->type == plus)
            {
                std::string child_type = check_leafs(child, symboltable);
                if (child_type != params[i]->dtype)
                {
                    std::cout << "ERROR (FCALL) WRONG TYPE FOR ARGUMENT: " << (*thirdchild)->value << " On index: " << i << " LINENUMBER: " << (*thirdchild)->lineno << std::endl;
                }
            }
            else if (child->type == fcall)
            {

                std::string child_type = semantic_analysis_methods(symboltable, itr);
                if (child_type != params[i]->dtype)
                {
                    std::cout << "ERROR (FCALL) WRONG TYPE FOR ARGUMENT: " << (*thirdchild)->value << " On index: " << i << " LINENUMBER: " << (*thirdchild)->lineno << std::endl;
                }
            }
            i++;
        }
    }

    void check_int_arrs(SymbolTable *symboltable, Node *i)
    {

        for (auto child : i->children)
        {
            if (child->type == this->mclass)
            {
                symboltable->enterScope();
                check_int_arrs(symboltable, child);
                symboltable->exitScope();
            }

            else if (child->type == this->classdec)
            {
                symboltable->enterScope();
                check_int_arrs(symboltable, child);
                symboltable->exitScope();
            }
            else if (child->type == this->midentify)
            {
                symboltable->enterScope();
                check_int_arrs(symboltable, child);
                symboltable->exitScope();
            }
            else if (child->type == arrmodifier)
            {
                auto target_child = std::next(child->children.begin(), 0);
                std::string target_child_stroonk = check_leafs((*target_child), symboltable);
                std::cout << target_child_stroonk << std::endl;

                if (target_child_stroonk != "IntArr")
                {
                    std::cout << "ERROR (ARRMODIFIER) WRONG TYPE FOR TARGET: " << (*target_child)->value << " LINENUMBER: " << (*target_child)->lineno << std::endl;
                }

                auto index_child = std::next(child->children.begin(), 1);

                auto value_child = std::next(child->children.begin(), 2);

                if ((*index_child)->type == mult || (*index_child)->type == divide || (*index_child)->type == minus || (*index_child)->type == plus || (*index_child)->type == identify)
                {
                    std::string child_type_i = check_leafs((*index_child), symboltable);
                    if (child_type_i != "Int")
                    {
                        std::cout << "ERROR (ARRMODIFIER, INDEX) WRONG TYPE FOR ARGUMENT: " << (*index_child)->value << " Line number: " << (*index_child)->lineno << std::endl;
                    }
                }
                else if ((*index_child)->dtype != "Int")
                {
                    std::cout << "ERROR (ARRMODIFIER) WRONG TYPE FOR INDEX: " << (*index_child)->value << " LINENUMBER: " << (*index_child)->lineno << std::endl;
                }

                if ((*value_child)->type == mult || (*value_child)->type == divide || (*value_child)->type == minus || (*value_child)->type == plus || (*value_child)->type == identify)
                {
                    std::string child_type_v = check_leafs((*value_child), symboltable);
                    if (child_type_v != "Int")
                    {
                        std::cout << "ERROR (ARRMODIFIER, VALUE) WRONG TYPE FOR ARGUMENT: " << (*value_child)->value << " LINENUMBER " << (*value_child)->lineno << std::endl;
                    }
                }
                else if ((*value_child)->type == "ArrDec")
                {
                    // look på vänstra barn noden och kolla så att det är en intarr
                    // på högra noden måste vi kolla så att det är en int.
                    auto child1 = std::next((*value_child)->children.begin(), 0);
                    std::string child1_string = check_leafs((*child1), symboltable);
                    auto child2 = std::next((*value_child)->children.begin(), 1);
                    std::string child2_string = check_leafs((*child2), symboltable);
                    std::cout << "DSADSASADASDAS_: " << child2_string << std::endl;
                    if (child1_string != "IntArr" && child2_string != "Int")
                    {
                        std::cout << "ERROR (ARRMODIFIER, VALUE) WRONG TYPE FOR ARGUMENT: " << (*value_child)->value << " LINENUMBER " << (*value_child)->lineno << std::endl;
                    }
                }
                else if ((*value_child)->dtype != "Int")
                {
                    std::cout << "ERROR (ARRMODIFIER) WRONG TYPE FOR VALUE: " << (*value_child)->dtype << "LINE NUMBER: " << (*value_child)->lineno << std::endl;
                }
            }
            else if (child->type == "ArrDec")
            {
                // look på vänstra barn noden och kolla så att det är en intarr
                // på högra noden måste vi kolla så att det är en int.
                auto child1 = std::next(child->children.begin(), 0);
                std::string child1_string = check_leafs((*child1), symboltable);
                auto child2 = std::next(child->children.begin(), 1);
                std::string child2_string = check_leafs((*child2), symboltable);
                std::cout << "DSADSASADASDAS_: " << child2_string << child1_string << std::endl;
                if (child1_string != "IntArr" || child2_string != "Int")
                {
                    std::cout << "ERROR (ARRMODIFIER, VALUE) WRONG TYPE FOR ARGUMENT: " << child->value << " LINENUMBER " << child->lineno << std::endl;
                }
            }

            else
            {
                check_int_arrs(symboltable, child);
            }
        }
    };
};

#endif
