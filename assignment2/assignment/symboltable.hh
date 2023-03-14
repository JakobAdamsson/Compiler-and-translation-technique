
#include <stdio.h>
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <map>

class Record
{
public:
    std::string id;
    std::string type;
    std::string dtype;

    // Getters and Setters
    virtual void printRecord()
    {
        std::cout << "id: " << id << " type: " << type <<" dtype: " <<dtype<<std::endl;
    };
};
class Variable : public Record
{
};
typedef struct _Parameters3
{
    std::string type;
    std::string id;
    std::string dtype;
    int x;
} _Parameters3;
class Method : public Record
{
public:
    std::map<std::string, std::string> Parameters;
    std::vector<Variable *> Parameters2;
    std::map<std::string, Variable *> Variables;
    std::map<std::string, _Parameters3 *> Parameters3;
    int param_number = 0;

    // Methods
    void addVariable(std::string key, Variable *type)
    {
        Variables.insert(std::pair<std::string, Variable *>(key, type));
    };
    void addParameter(std::string key, std::string type, Variable *param)
    {
        Parameters.insert(std::pair<std::string, std::string>(key, type));
        Parameters2.push_back(param);
    };
    void addToStruct(std::string type, std::string id, std::string dtype)
    {
        _Parameters3 *p3 = new _Parameters3;
        p3->type = type;
        p3->id = id;
        p3->dtype = dtype;
        p3->x = param_number++;
        Parameters3.insert(std::pair<std::string, _Parameters3 *>(type, p3));
    }

    void printVariables()
    {
        for (auto i = Variables.begin(); i != Variables.end(); i++)
        {
            std::cout << "Variable: " << i->first << " type: " << i->second->type << std::endl;
        }
    }
    void printParameters2()
    {
        for (auto str : Parameters2)
        {
            std::cout << "Paramters: " << str->id << " dtype: " << str->dtype << std::endl;
        }
    }
    void printParameters()
    {
        for (auto i = Parameters.begin(); i != Parameters.end(); i++)
        {
            std::cout << "Parameter: " << i->first << " type: " << i->second << std::endl;
        }
    }
};

class Class : public Record
{
public:
    std::map<std::string, Variable *> Variables;
    std::map<std::string, Method *> Methods;

    // Methods
    void addVariable(std::string key, Variable *type)
    {
        Variables.insert(std::pair<std::string, Variable *>(key, type));
    };
    void addMethod(std::string key, Method *type) // borde
    {
        Methods.insert(std::pair<std::string, Method *>(key, type));
    };
    Variable lookupVariable(std::string key){

    };
    Method *lookupMethod(std::string method_name)
    {
        int x;
        if (Methods.find(method_name) != Methods.end())
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        if (x)
        {
            return Methods[method_name];
        }
        return nullptr;
    };

    void printVariables()
    {
        for (auto i = Variables.begin(); i != Variables.end(); i++)
        {
            std::cout << "Variable: " << i->first << " type: " << i->second->type << std::endl;
        }
    }
    void printMethods()
    {
        for (auto i = Methods.begin(); i != Methods.end(); i++)
        {
            std::cout << "Method: " << i->first << " type: " << i->second->type << std::endl;
        }
    }
};

class Scope
{
public:
    int next = 0; // next child to visit
    Scope *parentScope;
    std::list<Scope *> childrenScopes;
    std::map<std::string, Record *> records;
    std::string scopeName;
    int id;

    void putRecord(std::string key, Record *item)
    {
        records.insert(std::make_pair(key, item));
    }

    Scope *nextChild(std::string name)
    {

        Scope *next_Child;
        if (next == childrenScopes.size()) // If false it means that current scope has no children scope and a new scope will be crea
        {
            // create new child scope
            next_Child = new Scope();
            next_Child->parentScope = this;
            next_Child->scopeName = name;
            childrenScopes.push_back(next_Child);
        }
        else
        {
            // This code is retrieving a pointer to the next child Scope object from the list of child Scope objects stored in the current Scope object.
            auto l_front = childrenScopes.begin();
            std::advance(l_front, next);
            next_Child = *l_front;
        }
        next++;
        return next_Child;
    }
    void printScope(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            std::cout << "  ";

        std::cout << "Scope: " << this->scopeName << std::endl;
        for (auto itr = records.begin(); itr != records.end(); ++itr)
        {
            for (int i = 0; i < depth + 1; i++)
                std::cout << "  ";
            std::cout << itr->second->type << ": " << itr->first << std::endl;
        }
        if (records.empty())
        {
            for (int i = 0; i < depth + 1; i++)
                std::cout << "  ";
            std::cout << "Empty\n"
                      << std::endl;
        }
        for (auto itr = childrenScopes.begin(); itr != childrenScopes.end(); ++itr)
        {
            (*itr)->printScope(depth + 1);
        }
    }
    void resetScope()
    {

        next = 0;
        for (auto it = childrenScopes.begin(); it != childrenScopes.end(); ++it)
        {
            (*it)->resetScope();
        }
    }
    Record *lookup(std::string key)
    {
        // contains
        /*
            m.count(key) > 0
            m.count(key) == 1
            m.count(key) != 0
        */
        if (records.count(key)) // does it exist in the current scope?
        {
            return records[key];
        }
        else
        {
            if (parentScope == NULL)
            {
                return NULL;
            }
            else
            {
                return parentScope->lookup(key); // Delegate the request to the parent
            }
        }
    }

    void generate_tree_st()
    {
        std::ofstream outStream;
        char *filename = "st.dot";
        outStream.open(filename);

        int count = 0;
        outStream << "digraph {" << std::endl;
        generate_semantic_tree_content(count, &outStream);
        outStream << "}" << std::endl;
        outStream.close();

        printf("\nBuilt a parse-tree at %s. Use 'make st' to generate the pdf version.", filename);
        printf("eyy\n");
    }

    void generate_semantic_tree_content(int &count, std::ofstream *outStream)
    {

        id = count++;
        std::string buffer = "\n";
        for (auto &kvp : this->records)
        {
            if (kvp.second->type == "MethodDeclaration")
            {
                buffer += kvp.second->dtype + " " + kvp.first + "()" + "\n";
            }
            else
            {
                buffer += kvp.second->dtype + " " + kvp.first + "\n";
            }
        }
        *outStream << "n" << id << " [label=\""
                   << "Scope"
                   << ":" << scopeName
                   << buffer
                   << "\"];"
                   << std::endl;

        for (auto i = childrenScopes.begin(); i != childrenScopes.end(); i++)
        {
            (*i)->generate_semantic_tree_content(count, outStream);
            *outStream << "n" << id << " -> n" << (*i)->id << std::endl;
        }
    }
};

class SymbolTable
{
public:
    Scope *root;
    Scope *current;
    Method *current_method;
    Class *current_class;
    std::vector<std::string> method_params;

    Class *fcall_current_class;
    Class *this_fcall_current_class;
    std::string variable_type;
    Variable *thiss;
    int id;
    SymbolTable()
    {
        root = new Scope();
        root->scopeName = "root";
        current = root;
    }
    void enterScope(std::string name = "")
    {
        current = current->nextChild(name);
    }
    void exitScope()
    {
        current = current->parentScope;
    }
    void put(std::string key, Record *item)
    {
        current->putRecord(key, item); // I current scope, ska den använda records, som är en map med string,record par och använda functionen add variabeln på det record med motsvarande key;
    }
    Record *lookup(std::string key)
    {
        return current->lookup(key);
    }

    void printCurrent()
    {
        current->printScope();
    }
    void printTable()
    {
        root->printScope();
    }
    void resetTable()
    {
        root->resetScope(); // reset all scopes
    }
};
