#include <iostream>
#include <map>

int main ()
{
    std::map<std::string, int> ages;

    ages["Miquel"] = 40;
    ages["Maria"] = 20;
    ages["Josep"] = 21;

    ages["Maria"] = 70;

    std::cout << ages["Josep"] << std::endl;
    // Accessing a Key that does not exist in the map, will add it to the map. Needd to check if key is existent
    std::cout << ages["Noone"] << std::endl;
    if(ages.find("New") != ages.end()) // if != than the end of the map, means it is already an existing key:
    {
        std::cout << ages["New"] << std::endl;
    }
    if(ages.find("Josep") != ages.end()) // if != than the end of the map, means it is already an existing key:
    {
        std::cout << "Found Josep" << std::endl;
    }


    for (std::map<std::string, int>::iterator it = ages.begin() ; it != ages.end(); it++)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    //another wai of iterating by using std::pair
    std::cout << "Add a pairs" << std::endl;
    std::pair<std::string, int> newPair("Xavi", 21);
    ages.insert(newPair);
    auto newPair2 = std::make_pair("Marina", 21);
    ages.insert(newPair2);

    for (std::map<std::string, int>::iterator it = ages.begin() ; it != ages.end(); it++)
    {
        std::pair<std::string, int> pair = *it;
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}