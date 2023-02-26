#include <iostream>
#include <map>
#include <string>

using namespace std;

class SecondClass
{
public:
    string name;
};

class FirstClass
{
public:
    map<string, SecondClass> second_map;

    void add_second_class(const SecondClass &second)
    {
        second_map[second.name] = second;
    }

    void recursive_add(int num_levels, const SecondClass &second)
    {
        if (num_levels <= 0)
        {
            return;
        }
        add_second_class(second);
        SecondClass new_second = second;
        new_second.name += "_new";
        recursive_add(num_levels - 1, new_second);
    }
};

int main()
{
    FirstClass first;
    SecondClass second1, second2;
    second1.name = "Second1";
    second2.name = "Second2";
    first.recursive_add(3, second1);
    first.recursive_add(2, second2);

    // print the contents of the map
    for (const auto &item : first.second_map)
    {
        cout << item.first << ": " << item.second.name << endl;
    }

    return 0;
}
