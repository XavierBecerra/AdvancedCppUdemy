#include <iostream>
#include <set>

//The balancing of the tree is not perfect, but it is good enough to allow it to guarantee searching in O(log n) time
//see https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

int main ()
{
    std::set<int> numbers;

    auto item1 = numbers.insert(1);
    auto item2 = numbers.insert(5);
    auto item3 = numbers.insert(3);
    auto item4 = numbers.insert(1);//item not added because already exists.

    std::cout<< *item1.first << " : " << item1.second << std::endl;
    std::cout<< *item2.first << " : " << item2.second << std::endl;
    std::cout<< *item3.first << " : " << item3.second << std::endl;
    std::cout<< *item4.first << " : " << item4.second << std::endl;

    for(std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        std::cout<< *it << std::endl;
    }

    //find an object in a set
    std::cout<< " Let's find stuff:" << std::endl;
    std::set<int>::iterator found = numbers.find(5);
    if(found != numbers.end()) {
        std::cout<< " Looking for 5, got:  " << *found << std::endl;
    }
    std::set<int>::iterator notfound = numbers.find(4);
    if(notfound != numbers.end()) {
        std::cout<< " Looking for 4, got:  " << *found << std::endl;
    }
    else{
        std::cout<< "Value not found, return .end() of the set  " << *notfound << std::endl;
    }

     std::cout<< " Let's count stuff:" << std::endl;
     //since elements in set are unique, cout() will return 1 or 0. But will loop through all set, whereas find will stop whn found.
     //Do not use count for finding!
     std::cout<< numbers.count(5) << std::endl;
     std::cout<< numbers.count(4) << std::endl;

    return 0;
}