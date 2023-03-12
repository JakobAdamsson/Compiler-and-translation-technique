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

    void print_node()
    {
        std::cout << "PRINT NODE Value: " << this->value << " Type: " << this->type << " Dtype: " << this->dtype << std::endl;
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
                    // std::cout << "hej!!! value: " << (*i)->value << " type: " << (*i)->type << " dtype: " << std::endl;
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
            //  symboltable->current_method->printParameters();
        }
    }
    void VarDec_method(SymbolTable *symboltable, Node *i)
    {
        Variable *vardec_test = new Variable();
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
                    Record *rec = symboltable->lookup((*ii)->value);
                    if ((*ii)->type == this->identify)
                    {
                        if (rec == NULL)
                        {
                            std::cout << "NO RECORD FOUND FOR-> "
                                      << "ID: " << (*ii)->value << " TYPE: " << (*ii)->type << std::endl;
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
            return node->dtype;
        }
        if (node->type == fcall)
        {

            auto class_node = std::next(node->children.begin(), 0);

            Class *hej = fcall_check_first_child(symboltable, (*class_node));

            if (!hej)
            {

                return "";
            }
            auto method_node = std::next(node->children.begin(), 2);

            Method *tja = hej->lookupMethod((*method_node)->value);
            if (tja)
                return tja->dtype;
            else
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
                else if (child_dtype != common)
                {
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

                if (temp == "")
                {
                    std::cout << "NO RECORD FOUND FOR-> "
                              << "ID: " << temp << " TYPE: " << i->type << std::endl;
                }
                else
                {
                    std::cout << "FOUND RECORD FOR-> "
                              << "ID: " << temp << " TYPE: " << i->type << std::endl;
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
            Record *rec = symboltable->lookup(i->value);
            if (rec == NULL)
            {
                std::cout << "NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
                return NULL;
            }
            Class *cls = dynamic_cast<Class *>(rec);
            if (cls == nullptr)
            {
                std::cout << "NO CLASS FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
                return NULL;
            }
            return cls;
        }
        else if (i->type == thiss)
        {
            // symboltable->current->parentScope->printScope();
            Record *rec = symboltable->lookup("this");

            if (rec == NULL)
            {
                // symboltable->current->parentScope->printScope();
                std::cout << "NO RECORD FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
                return NULL;
            }
            Record *rec2 = symboltable->lookup(rec->type);
            Class *cls = dynamic_cast<Class *>(rec2);
            if (cls == nullptr)
            {
                std::cout << "NO CLASS FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
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
                          << "ID: " << i->value << " TYPE: " << i->dtype << std::endl;
                return NULL;
            }
            Record *rec2 = symboltable->lookup(rec->dtype);
            if (rec2 == NULL)
            {
                std::cout << "(FCall identifier)NO RECORD2 FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->dtype << std::endl;
                return NULL;
            }
            std::cout << "EYYY type:" << rec2->type << " id: " << rec2->id << " dtype: " << rec2->dtype << std::endl;
            Class *cls = dynamic_cast<Class *>(rec2);
            if (cls == nullptr)
            {
                std::cout << "(FCall identifier)NO CLASS FOUND FOR-> "
                          << "ID: " << i->value << " TYPE: " << i->type << std::endl;
                return NULL;
            }
            return cls;
        }

        return NULL;
    }
};

#endif
// create function that return the class
// check if the method name is in the class.
// do it have the right number of parameter
// do the type of parameters correspoing to the type in the method decalaration.

// kolla så att parametrar och argument stämmer överens
//