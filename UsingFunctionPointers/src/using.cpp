
#include <iostream>
#include <vector>
#include <algorithm>

bool matchCriteria(const std::string & string)
{
    //return (string.size() == 3);
    return (string == "three");
};

int dummyCounter(std::vector<std::string> vect, bool (*func)(const std::string &) ) {
    int count = 0;
    for(auto i : vect) {
        if(func(i)){
            count++;
        }
    }
    return count;
};

int main()
{
    std::vector<std::string> vect;
    vect.push_back("one");
    vect.push_back("two");
    vect.push_back("three");
    vect.push_back("two");
    vect.push_back("four");
    vect.push_back("three");
    vect.push_back("two");
    vect.push_back("five");
    vect.push_back("four");
    vect.push_back("three");
    vect.push_back("two");

    bool (*critearia)(const std::string &) = matchCriteria;// not needed, passing name of function will work

    int num_items = std::count_if(vect.begin(), vect.end(), matchCriteria);
    std::cout << "Number matching criteria: " << num_items << std::endl;


    int num_items2 = dummyCounter(vect, matchCriteria);
    std::cout << "Number matching criteria: " << num_items2 << std::endl;
    
    return 0;
}