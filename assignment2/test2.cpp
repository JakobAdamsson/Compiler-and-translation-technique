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

class Scope
{
public:
    int x = 5;
};

class SymbolTable
{
public:
    Scope *root;
    Scope *current;
    SymbolTable()
    {
        root = new Scope();
        current = root;
        printf("%d \n", root->x);
    }
};

int main()
{
    SymbolTable table;

    return 0;
}