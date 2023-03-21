#ifndef IR_HH
#define IR_HH
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

class Tac
{
public:
    std::string op, lhs, rhs, result;

    // Getters and setters
    std::string dump()
    {
        std::cout << result << " = " << lhs << " " << op << " " << rhs << std::endl;
        return result+" = "+ lhs + " " + op + " " + rhs ;
    }
};

class Expression : public Tac
{
public:
    Expression(std::string _op, std::string _y, std::string _z, std::string _result)
    {
        op = _op;
        lhs = _y;
        rhs = _z;
        result = _result;
    }
};

class MethodCall : public Tac
{
public:
    MethodCall(std::string _f, std::string _N, std::string _result)
    {
        op = "call";
        lhs = _f;
        rhs = _N;
        result = _result;
    }
};

class Jump : public Tac
{
public:
    Jump(std::string _label)
    {
        op = "goto";
        result = _label;
    }
};
class Condjump : public Tac
{
public:
    Condjump(std::string _op, std::string _x, std::string _label)
    {
        op = _op;
        lhs = _x;
        result = _label;
    }
};

class BBlock
{
public:
    std::string name;
    std::vector<Tac *> tacInstructions;
    Tac condition;
    BBlock *trueExit, *falseExit;
    BBlock()
    {
        trueExit = falseExit = NULL;
    }
};
#endif