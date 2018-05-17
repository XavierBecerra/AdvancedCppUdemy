
#include <iostream>

//RULE OF THREE:
// if you implement a copy constuctor, operator= or a destructor, you should implemnt the other two as well !
// for destructor case is because you will most likely define a destructor to clear memory, clear memory from pointer.
// so this means that if you have pointers (reason for implementing destructor), you dont want to do shallow copies,
// meaning you will wants to define operator=, hence copy constructor.

class Test_t
{
public:
    Test_t() : m_id(0), m_name("default") {};
    Test_t(const int id, const std::string &name) : m_id(id), m_name(name) {};
    Test_t(const Test_t & other) {
        std::cout<< "Copy constructor running"<< std::endl;
        m_id = other.m_id;
        m_name = other.m_name;
        //*this= other; 
    };

    ~Test_t() {
    };

    void print() const{
        std::cout << m_id << " : "<< m_name << std::endl;
    };

    const Test_t & operator= (const Test_t & other)
    {
        std::cout<< "running overloaded: " <<std::endl;
        m_id = other.m_id;
        m_name = other.m_name;
        return *this;
    }

private:
    int m_id;
    std::string m_name;
};

int main()
{
    Test_t test1(10, "Messi");
    test1.print();

    Test_t test2(11, "Rivaldo");
    test2.print();

    test2 = test1; // Cpp default implementation. It is a shallow copy. Sometimes you need a deep copy that makes sense. Need for overloading operator =. e.g you dont want to copy id, or you have pointers...
    test2.print();


    Test_t test3;
    test3.operator=(test2);
    test3.print();
    // Copy initialization
    // Here we are calling the copy-constructor. 
    Test_t test4 = test1;
    test4.print();
    
    return 0;
}