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

	// Global Symboltable
	SymbolTable symboltable;

	// Identifiers
	std::string mclass = "MainClass";
	std::string classdec = "ClassDec";
	std::string vardec = "VarDec";
	std::string methoddec = "MethodDec";
	std::string parameter = "Parameter";
	std::string statement = "Statement";
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

	void create_symboltable()
	{
		// Please keep in mind that it only iteratetes through one level of the tree(e.g root only has mainclass and class dec).
		for (auto i = children.begin(); i != children.end(); i++)
		{
			if ((*i)->type == this->mclass)
			{
				this->Mainclass((*i)->type, (*i)->value);
			}
		}
	}

	// t as in type :)
	void Mainclass(std::string t, std::string identifier)
	{
		// Create a new record
		Class mainclass_test;

		// Fill the data
		mainclass_test.id = identifier;
		mainclass_test.type = t;

		// Add the record to the symboltable. Put uses putRecord and putRecord inserts a pair(key and value) into the defined map.
		symboltable.put(mainclass_test.id, mainclass_test);

		// Enter new scope
		symboltable.enterScope();

		symboltable.printTable();

		std::cout << "Found main class -> " << mainclass_test.id << mainclass_test.type << std::endl;
	}
};

#endif