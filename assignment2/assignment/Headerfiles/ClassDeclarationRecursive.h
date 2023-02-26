#ifndef CLASSDECLARATIONRECURSIVE_H
#define CLASSDECLARATIONRECURSIVE_H
#include <stdio.h>
#include <iostream>
#include "../Node.h"

Method *getMethodData(Node *itr)
{
    std::cout << "NU KÖR VI I getMethodVariables" << std::endl;

    Method new_method;
    new_method.id = (itr)->value;
    new_method.type = (itr)->type;
}

#endif