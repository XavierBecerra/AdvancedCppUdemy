#include <iostream>
#include <stack>
#include <queue>

    //The std::stack class is a container adapter that gives the programmer the functionality of a stack - specifically, 
    // a FILO (first-in, last-out) data structure. See http://en.cppreference.com/w/cpp/container/stack

    //The std::queue class is a container adapter that gives the programmer the functionality of a queue - specifically,
    // a FIFO (first-in, first-out) data structure. http://en.cppreference.com/w/cpp/container/queue

class Test_t
{
public:
    Test_t() : name("default") {};
    Test_t(const std::string &name) : name(name) {};

    ~Test_t() {
        //std::cout<< " Test object "<< name << " destroyed."<< std::endl;
    };

    void print() const{
        std::cout<< " This is Test object "<< name << std::endl;
    };
private:
    std::string name;
};

int main()
{
    // LIFO (Or FILO)
    std::stack<Test_t> testSuite;

    testSuite.push(Test_t("Test1"));
    testSuite.push(Test_t("Test2"));
    testSuite.push(Test_t("Test3"));
    testSuite.push(Test_t("Test4"));
    testSuite.push(Test_t("Test5"));

    Test_t test1 = testSuite.top();
    test1.print();

    testSuite.emplace();
    test1 = testSuite.top();
    test1.print();

    testSuite.pop();
    test1 = testSuite.top();
    test1.print();

    testSuite.emplace("Emplaced");
    test1 = testSuite.top();
    test1.print();

    std::cout<< " Size of Stack:  "<< testSuite.size() << std::endl;
    //to iterate we need to pop:
    while(!testSuite.empty()){
        testSuite.top().print();
        testSuite.pop();
    }
    
    // better to work with references, but dangerous when popping!!
    /* INVALID CODE:
    Test_t & testRef = testSuite.top();
    testSuite.pop(); // WRONG!!, unreliable code!!! The elemnt testRef is pointing to, is now destory and may be overwritten!!
    testRef.print();
    */

    std::cout<< std::endl<< std::endl;
    // LIFO (Or FILO)
    std::queue<Test_t> testQueue;

    testQueue.push(Test_t("Test1"));
    testQueue.push(Test_t("Test2"));
    testQueue.push(Test_t("Test3"));
    testQueue.push(Test_t("Test4"));
    testQueue.push(Test_t("Test5"));

    Test_t test10 = testQueue.front();
    test10.print();

    testQueue.emplace();
    test10 = testQueue.front();
    test10.print();

    testQueue.pop();
    test10 = testQueue.front();
    test10.print();

    testQueue.emplace("Emplaced");
    test10 = testQueue.front();
    test10.print();

    std::cout<< " Size of Stack:  "<< testQueue.size() << std::endl;
    //to iterate we need to pop:
    while(!testQueue.empty()){
        testQueue.front().print();
        testQueue.pop();
    }


    return 0;
}