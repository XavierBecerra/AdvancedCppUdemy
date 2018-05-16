#include <iostream>
#include <map>

int main ()
{
    std::multimap<int , std::string> lookup;

    lookup.insert( std::make_pair(20, "Raj") );
    lookup.insert( std::make_pair(30, "Leonnard") ); 
    lookup.insert( std::make_pair(30, "Sheldon") );//same key as Leonnard
    lookup.insert( std::make_pair(10, "Howard") );

    for (std::multimap<int , std::string>::iterator it = lookup.begin(); it != lookup.end() ; it++)
    {
        std::cout<< it->first << " : " << it->second << std::endl;
    }

    std::cout<<  " Try find "  << std::endl;
    //find, you will find the firstone of the 2 same keys!!!!
    for (std::multimap<int , std::string>::iterator it = lookup.find(20); it != lookup.end() ; it++)
    {
        std::cout<< it->first << " : " << it->second << std::endl;
    }

    std::cout<<  " Try range "  << std::endl;
    //iterate through a range,so only values with same key, here 30.
    std::pair<std::multimap<int , std::string>::iterator, std::multimap<int , std::string>::iterator> its = 
        lookup.equal_range(30);//use auto for cpp 11!
    for (std::multimap<int , std::string>::iterator it = its.first; it != its.second ; it++)
    {
        std::cout<< it->first << " : " << it->second << std::endl;
    }

    return 0;
}