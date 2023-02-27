#include <iostream>
#include <vector>
#include <list>
#include "symboltable.hh"
class Node
{
public:
    std::string type;
    std::string value;
    std::list<Node *> children;

    Node(std::string t, std::string v)
    {
        type = t;
        value = v;
    }

    void add_child(Node *child)
    {
        this->children.push_back(child);
    }
    
    void see_children()
    {
        for (auto i = children.begin(); i != children.end(); i++)
            std::cout << (*i)->type << std::endl;
    }

    void print_tree(int depth = 0)
    {
    	for (int i = 0; i < depth; i++)
			std::cout << "  ";    
        std::cout << this->value<< std::endl;

        for(auto i = children.begin();i!=children.end();i++)
        {
            // std::cout << (*i)->type << std::endl;
            (*i)->print_tree(depth+1);
        }
        

    }
};

int main()
{
    SymbolTable root;
    


    return 0;
}
