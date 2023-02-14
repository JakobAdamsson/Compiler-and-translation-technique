#include "Node.h"
#include <stdio.h>
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <map>
#include <vector>

class SymbolTable;
class Scope;
class Record;
class Class;
class Method;
class Variable;

class SymbolTable
{
public:
    Scope *root;
    Scope *current;

    SymbolTable()
    {
        root = new Scope();
        current = root;
    }
    void enterScope() { current = current->nextChild(); }
    void exitScope() { current = current->parentScope; }
    int put(std::string key, Record item)
    {
        return 0; // I current scope, ska den använda records, som är en map med string,record par och använda functionen add variabeln på det record med motsvarande key;
    };
};
class Scope
{
public:
    int next = 0; // next child to visit
    Scope *parentScope;
    std::list<Scope *> childrenScopes;
    std::map<std::string, Record> records;

    Scope *nextChild()
    {
        Scope *nextChild;
        if (next == childrenScopes.size())
        {
            // create new child scope
            nextChild = new Scope;
            childrenScopes.push_back(nextChild);
        }
        else
        {
            // This code is retrieving a pointer to the next child Scope object from the list of child Scope objects stored in the current Scope object.
            auto l_front = childrenScopes.begin();
            std::advance(l_front, next);
            nextChild = *l_front;
        }
        next++;
        return nextChild;
    }
};

class Record
{
    std::string id;
    std::string type;

    // Getters and Setters
    void printRecord()
    {
        std::cout << "id: " << id << " type: " << type << std::endl;
    };
};
class Class : Record
{
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
class Method : Record
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
class Variable : Record
{
    std::map<std::string, std::string> Variables;
    void addVariable(std::string key, std::string type)
    {
        Variables.insert(std::pair<std::string, std::string>(key, type));
    };
};
