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

class SymbolTable{
public:
    Scope *root;
    Scope *current; 

    SymbolTable() 
    {
        root = new Scope(NULL); 
        current = root;
    }
    void enterScope(){current = current.nextChild();}

    
};

class Scope{
public:
    int next = 0; // next child to visit
    Scope *parentScope;
    std::list<Scope*> childrenScopes; 
    std::map<std::string, Record> records;

    Scope nextChild(){
        Scope *nextChild;
        if(next == childrenScopes.size())
        {
            // create new child scope
            nextChild = new Scope;
            childrenScopes.push_back(nextChild);

        }
        else
        {
            auto l_front = childrenScopes.begin();
            std::advance(l_front, next);
        }
        next++;
        return nextChild;
    }



};

class Record{



};

class Class: Record{



};

class Method: Record{



};

class Variable: Record{



};
