#include <iostream>
#include <vector>

int main ()
{
    std::vector<std::string> myStrings(6);//presizing the vector

    //accessing here myStrings[6] will segfault. Overload of [] Not protected, ust at().
    std::cout << "Size is " << myStrings.size() << std::endl;
    //adding anew entry
    myStrings.push_back("Addition");
    std::cout << myStrings[6] << std::endl;
    std::cout << "Size is " << myStrings.size() << std::endl;

    myStrings[3] = "overloaded";
    std::cout << myStrings[3] << std::endl;

    //more work
    std::vector<std::string> someStrings;//presizing the vector
    someStrings.push_back("one");
    someStrings.push_back("two");
    someStrings.push_back("three");
    
    for(std::vector<std::string>::iterator it = someStrings.begin(); it != someStrings.end(); it++)
    {
         std::cout << *it << std::endl;
    }
    //use of auto
    for(auto it = someStrings.begin(); it != someStrings.end(); it++)
    {
         std::cout << *it << std::endl;
    }
    //use of range based for loop
    for(auto it : someStrings)
    {
         std::cout << it << std::endl;
    }

    return 0;
}