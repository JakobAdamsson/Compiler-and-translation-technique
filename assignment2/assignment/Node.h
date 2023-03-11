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
    std::string midentify = "MethodDeclaration";
    std::string identify = "Identifier";
    std::string sment = "LRStatement";
    std::string parameter = "Parameter";
    std::string elsestate = "ELSE";
    std::string expression = "Expression";
    std::string fcall = "FCall";
    std::string assignment = "Assignment";
    std::string newvar = "NewVar";
    std::string thiss = "This";

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
        Variable *new_param = new Variable();
        new_param->id = i->value;
        new_param->type = i->type;
        new_param->dtype = i->dtype;
        symboltable->current_method->addParameter(i->value, symboltable->variable_type, i->dtype);
        symboltable->current_method->addToStruct(i->value, i->type, i->dtype);
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

        Variable *this_ = new Variable();
        this_->id = "this";
        this_->type = i->value;
        this_->dtype = i->value;
        classdec_test->addVariable(this_->id, this_);

        // Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.

        // Enter new scope
        symboltable->put(classdec_test->id, classdec_test);
        // symboltable->enterScope("hello");

        symboltable->enterScope(this->classdec + "(" + i->value + ")");
        symboltable->put(this_->id, this_);
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
                    Record *rec = symboltable->lookup((*ii)->value);
                    if ((*ii)->type == this->identify)
                    {
                        if (rec == NULL)
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
            if ((*i)->type == mclass)
            {
                symboltable->enterScope();
                (*i)->semantic_analysis_methods(symboltable);
                symboltable->exitScope();
            }
            else if ((*i)->type == classdec)
            {
                symboltable->enterScope();
                (*i)->semantic_analysis_methods(symboltable);
                symboltable->exitScope();
            }
            else if ((*i)->type == midentify)
            {
                symboltable->enterScope();
                (*i)->semantic_analysis_methods(symboltable);
                symboltable->exitScope();
            }
            else if ((*i)->type == fcall)
            {
                Class *cls = fcall_check_first_child(symboltable, (*i)->children.front());
                auto third_child = std::next((*i)->children.begin(), 2);
                Method *rec = cls->lookupMethod((*third_child)->value);
                if (rec == nullptr)
                {
                    std::cout << "NO RECORD FOUND FOR-> "
                              << "ID: " << (*third_child)->value << " TYPE: " << (*third_child)->type << std::endl;
                    return;
                }
                int no_param = rec->Parameters.size();
                // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa

                auto fourth_child = std::next((*i)->children.begin(), 3);
                int y;
                if ((*fourth_child)->type == "LRExp")
                {
                    y = 1 + check_parameters(symboltable, *fourth_child);
                }
                else if ((*fourth_child)->type == "Empty")
                {
                    y = 0;
                }
                else
                {
                    y = 1;
                }
                if (no_param != y)
                {
                    std::cout << "NÅGOT ÄR JÄVLIGT FEL" << std::endl;
                    return;
                }

                type_check_parameters(symboltable, *fourth_child, rec, no_param);

                if (symboltable->method_params == rec->Parameters2)
                {
                    std::cout << "The vectors are equal" << std::endl;
                }
                else
                {
                    std::cout << "The vectors are not equal" << std::endl;
                }

                rec->printParameters2();
                for (auto str : symboltable->method_params)
                {
                    std::cout << "symboltabbleapsd io   " << str << std::endl;
                }

                symboltable->method_params.clear();
                symboltable->method_params.shrink_to_fit();
            }
            else
            {
                (*i)->semantic_analysis_methods(symboltable);
            }
        }
    }

    bool isLeaf() const
    {
        return children.empty();
    }

    std::string checkAllLeavesHaveSameHej(const Node *node)
    {
        if (node->isLeaf())
        {
            // Return the node's 'hej' value
            return node->dtype;
        }
        else
        {
            // Recursively check all child nodes
            std::string commonHej = "";
            for (auto child : node->children)
            {
                std::string childHej = checkAllLeavesHaveSameHej(child);
                if (commonHej.empty())
                {
                    commonHej = childHej;
                }
                else if (childHej != commonHej)
                {
                    return "";
                }
            }
            return commonHej;
        }
    }
    int check_parameters(SymbolTable *symboltable, Node *i)
    {
        int x = 0;
        if (i->type == "LRExp")
        {
            x++;
        }
        else if (i->type == "Empty")
        {
            return x;
        }

        for (auto itr = i->children.begin(); itr != i->children.end(); itr++)
        {
            x += check_parameters(symboltable, *itr);
        }
        return x;
    }
    std::string check_expression(SymbolTable *symboltable, Node *i)
    {
    }

    void type_check_parameters(SymbolTable *symboltable, Node *i, Method *method, int no_param)
    {

        std::vector<std::string> params;

        // std::cout << "Value: " << i->value << " Type: " << i->type << " Dtype: " << i->dtype << std::endl;
        if (i->type == "Plus" || i->type == "Minus" || i->type == "Mult" || i->type == "(Expression)" || i->type == "Divide")
        {
            symboltable->method_params.push_back(i->checkAllLeavesHaveSameHej(i));
            return;
        }

        for (auto itr = i->children.begin(); itr != i->children.end(); itr++)
        {
            (*itr)->type_check_parameters(symboltable, *itr, method, no_param);
        }
        if (i->type != "LRExp")
        {

            if (i->type == identify)
            {
                Record *hejsan = symboltable->lookup(i->value);
                symboltable->method_params.push_back(hejsan->dtype);
            }
            else if (i->type == "Num")
            {
                symboltable->method_params.push_back(i->dtype);
            }

            std::cout << "TYPE: " << i->type << " VALUE: " << i->value << " DTYPE: " << i->dtype << std::endl;
        }

        // högraste noden med parameterar lrexp
        // Vi måste veta vilken metod vi är i
        // iterera igenom parametrarna, num eller id eller (exp)
        // vi hittar en id
        // value of type -> x int <- strings
        // str1 = x str2 = int
        // metod.findparams(str1, str2);
    }
    std::string check_something(Node *i)
    {
        if (i->type == "LRExp")
        {
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