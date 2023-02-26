#ifndef NODE_H
#define NODE_H

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
	string type, value;
	list<Node *> children;

	// Identifiers
	std::string mclass = "MainClass";
	std::string classdec = "ClassDeclaration";
	std::string vardec = "VarDeclaration";
	std::string midentify = "MethodDeclaration";
	std::string lrecvarordec = "LRVarOrStatementDec";
	std::string identify = "Identifier";
	std::string sment = "LRStatement";
	std::string ifstate = "If statement";
	std::string methoddec = "MethodDec";
	std::string parameter = "Parameter";
	std::string expression = "Expression";

	// Constructor
	Node(string t, string v, int l) : type(t), value(v), lineno(l) {}
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
		for (auto i = children.begin(); i != children.end(); i++)
		{

			if ((*i)->type == this->mclass)
			{

				Mainclass(symboltable, (*i));
			}

			else if ((*i)->type == this->classdec)
			{
				ClassDec(symboltable, (*i));
			}

			else if ((*i)->type == this->midentify)
			{
				MethDec(symboltable, (*i));
			}

			else if ((*i)->type == this->lrecvarordec)
			{
				// We know for a fact that this will contain more nodes, so we can only call upon create_symboltable again to traverse further.
				(*i)->create_symboltable(symboltable);
			}
			else if ((*i)->type == this->ifstate)
			{
				IfStateMent(symboltable, (*i));
			}
			else if ((*i)->type == this->vardec)
			{
				VarDec(symboltable, (*i));
			}
		}
	}

	void IfStateMent(SymbolTable *symboltable, Node *i)
	{
		IfStatement statement_test;

		// Fill data
		statement_test.id = i->value;
		statement_test.type = i->type;
		// Add the record to the current scope record
		symboltable->put(statement_test.id, statement_test);

		// Enter new scope
		symboltable->enterScope(this->ifstate);

		i->create_symboltable(symboltable);

		// symboltable.printCurrent();

		// std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

		symboltable->exitScope();
	}
	void VarDec(SymbolTable *symboltable, Node *i)
	{
		Variable vardec_test;

		// Assing a variable the current scope
		// Add to current scope

		// Fill data
		vardec_test.id = i->value;
		vardec_test.type = i->type;

		// Add the record to the current scope record
		symboltable->put(vardec_test.id, vardec_test);
	}
	void MethDec(SymbolTable *symboltable, Node *i)
	{
		// Create a new record
		Method methoddec_test;

		// Fill the data
		methoddec_test.id = i->value;
		methoddec_test.type = i->type;

		// Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
		symboltable->put(methoddec_test.id, methoddec_test);

		// Enter new scope
		symboltable->enterScope(this->midentify);

		i->create_symboltable(symboltable);

		// symboltable.printCurrent();

		// std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

		symboltable->exitScope();
	}

	// t as in type :)
	void Mainclass(SymbolTable *symboltable, Node *i)
	{
		// Create a new record
		Class mainclass_test;

		// Fill the data
		mainclass_test.id = i->value;
		mainclass_test.type = i->type;

		// Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
		symboltable->put(mainclass_test.id, mainclass_test);

		// Enter new scope
		symboltable->enterScope(this->mclass);

		i->create_symboltable(symboltable);

		// symboltable.printCurrent();

		// std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

		symboltable->exitScope();
	}

	void getMethodData(Node *i, Method *new_method)
	{
		new_method->id = (i)->value;
		new_method->type = (i)->type;
		// std::cout << "NAMNET PÅ METHOD: " << new_method->id << new_method->type << std::endl;

		for (auto itr = i->children.begin(); itr != i->children.end(); itr++)
		{
			if ((*itr)->type == this->vardec)
			{
				Variable new_variable;
				new_variable.id = (*itr)->value;
				new_variable.type = (*itr)->type;
				new_method->addVariable((*itr)->value, new_variable);
			}
			else if ((*itr)->value == this->ifstate)
			{
			}
			else if ((*itr)->type == this->lrecvarordec)
			{
				// We know for a fact that this will contain more nodes, so we can only call upon create_symboltable again to traverse further.
				(*itr)->getMethodData(*itr, new_method);
			}
		}
	}
	void ClassDec(SymbolTable *symboltable, Node *i)
	{

		// Create a new record
		Class classdec_test;
		printf("NU ÄR VI I CLASSDEC\n");
		// Fill the data
		classdec_test.id = i->value;
		classdec_test.type = i->type;

		for (auto itr = i->children.begin(); itr != i->children.end(); itr++)
		{
			if ((*itr)->type == this->midentify)
			{
				Method new_method;
				getMethodData((*itr), &new_method);
				new_method.printVariables();
				classdec_test.addMethod((*itr)->value, new_method);
				// Make new mehtod that calls itr recursively then returns the new Method instace
			}
			else if ((*itr)->type == this->vardec)
			{
				Variable new_var;
				new_var.id = (*itr)->value;
				new_var.type = (*itr)->type;
				classdec_test.addVariable((*itr)->value, new_var);
			}
		}

		// Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
		symboltable->put(classdec_test.id, classdec_test);

		// Enter new scope
		symboltable->enterScope(this->classdec);

		i->create_symboltable(symboltable);

		// symboltable.printCurrent();

		// std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;

		symboltable->exitScope();
	}
};

#endif