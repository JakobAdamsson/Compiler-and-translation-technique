
#include <stdio.h>
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <map>
#include <vector>

class Record
{
public:
    std::string id;
    std::string type;

    // Getters and Setters
    void printRecord()
    {
        std::cout << "id: " << id << " type: " << type << std::endl;
    };
};
class Variable : public Record
{
};

class Statement : public Record
{
};
class Method : public Record
{
    std::map<std::string, std::string> Parameters;
    std::map<std::string, std::string> Variables;

    // Methods
    void addVariable(std::string key, std::string type)
    {
        Variables.insert(std::pair<std::string, std::string>(key, type));
    };
    void addParameter(std::string key, std::string type)
    {
        Parameters.insert(std::pair<std::string, std::string>(key, type));
    };
};

class Class : public Record
{
public:
    std::map<std::string, Variable> Variables;
    std::map<std::string, Method> Methods;

    // Methods
    void addVariable(std::string key, Variable type)
    {
        Variables.insert(std::pair<std::string, Variable>(key, type));
    };
    void addMethod(std::string key, Method type) // borde
    {
        Methods.insert(std::pair<std::string, Method>(key, type));
    };
    void lookupVariable(){};
    void lookupMethod(){};
};

class Scope
{
public:
    int next = 0; // next child to visit
    Scope *parentScope;
    std::list<Scope *> childrenScopes;
    std::map<std::string, Record> records;
    std::string scopeName;

    void putRecord(std::string key, Record item)
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
            std::cout << itr->second.type << ": " << itr->first << std::endl;
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
    Record lookup(std::string key)
    {
        if (records.count(key)) // does it exist in the current scope?
        {
            return records[key];
        }
        else
        {
            if (parentScope == NULL)
            {
                std::cout << "IN ROOT SCOPE" << std::endl; // Identifier not in the symbol table
            }
            else
            {
                return parentScope->lookup(key); // Delegate the request to the parent
            }
        }
    }
};

class SymbolTable
{
public:
    Scope *root;
    Scope *current;
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
    void put(std::string key, Record item)
    {
        current->putRecord(key, item); // I current scope, ska den använda records, som är en map med string,record par och använda functionen add variabeln på det record med motsvarande key;
    }
    Record lookup(std::string key)
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
