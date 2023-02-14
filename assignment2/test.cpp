#include <stdio.h>
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <map>
#include <vector>

#include <iostream>

class Person
{
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a)
    {
        name = n;
        age = a;
    }

    void printDetails()
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main()
{
    // Create a Person object using the constructor
    Person p("John Doe", 30);

    // Access the object's public method
    p.printDetails();

    return 0;
}