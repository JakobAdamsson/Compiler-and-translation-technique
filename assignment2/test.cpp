#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    
    // Using auto to declare the iterator type
    for (auto it = myVector.begin(); it != myVector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using auto to declare the variable type
    auto x = 1 + 2.5;
    std::cout << "x = " << x << std::endl;

    return 0;
}
