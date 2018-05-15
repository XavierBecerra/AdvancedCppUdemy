#include <iostream>
#include <iterator>
#include <list>

//you can insert items in a list at the bigining ormiddle of the lists whereas in vector items can only be added at the end
// this is because of the implementation:
// vector all elements are stacked next to each other continuosly on the computer memory. Thats why it is easy and faster to access via index
// list contains a lot of nodes that are linked to each other via pointers. each node in alist has a pointer to the next and provious elements.
// 

int main()
{
    std::list<int> numbers;

    //adding end of list
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    //adding front of list
    numbers.push_front(4);
    numbers.push_front(5);
    //pointing at the 3rd position
    std::list<int>::iterator third = numbers.begin();;
    std::advance( third , 2);
    std::cout << *third << std::endl;
    //adding element to the 3rd psition
    numbers.insert(third, 6);
    //now, actually the third pointer position is pointing to 4th position:
    std::cout << *third << std::endl;//its value is still 1


    for(std::list<int>::iterator it = numbers.begin() ; it != numbers.end(); it++)
    {
        std::cout << *it << std::flush;
    }
    std::cout << std::endl;

    //delete elements from the list
    //erase element to the 3rd psition
    std::list<int>::iterator eraseThird = numbers.begin();;
    std::advance( eraseThird , 2);
    numbers.erase(eraseThird);


    for(std::list<int>::iterator it = numbers.begin() ; it != numbers.end(); it++)
    {
        std::cout << *it << std::flush;
    }
    std::cout << std::endl;

    return 0;
}