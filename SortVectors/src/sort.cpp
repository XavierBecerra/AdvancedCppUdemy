#include <iostream>
#include <vector>
#include <algorithm>

class Test_t
{
public:
    Test_t() : m_id(0), m_name("default") {};
    Test_t(const int id, const std::string &name) : m_id(id), m_name(name) {};

    ~Test_t() {
        //std::cout<< " Test object "<< name << " destroyed."<< std::endl;
    };

    void print() const{
        std::cout << m_id << " : "<< m_name << std::endl;
    };

    bool operator<(const Test_t &other) const {
        return m_name < other.m_name;
    };

    bool operator>(const Test_t &other) const {
        return m_id < other.m_id;
    };

    // by stating friend, it means that the function with this prototype, can access private members of this class.
    friend bool comp (const Test_t &a, const Test_t &b);

private:
    int m_id;
    std::string m_name;
};

bool comp (const Test_t &a, const Test_t &b) {
    return a.m_id > b.m_id;
}

int main()
{
    std::vector <Test_t> vect;
    
    vect.push_back(Test_t(10, "Messi"));
    vect.push_back(Test_t(14, "Coutinho"));
    vect.push_back(Test_t(9, "Suarez"));
    vect.push_back(Test_t(21, "L.Enrique"));
    vect.push_back(Test_t(6, "Xavi"));
    vect.push_back(Test_t(1, "Ter Stegen"));
    vect.push_back(Test_t(8, "Iniesta"));

    //uses overloaded operator<
    std::sort(vect.begin(), vect.end());
    for(auto it : vect){
        it.print();
    }

    //use a lambda expresion
    std::cout << std::endl;
    std::sort(vect.begin(), vect.end(), [](Test_t a, Test_t b){return a>b;} );
    for(auto it : vect){
        it.print();
    }

    //use a function pointer
    std::cout << std::endl;
    std::sort(vect.begin(), vect.end(), comp );
    for(auto it : vect){
        it.print();
    }

    //uses overloaded operator< only sorts the first 3 elements
    std::cout << std::endl;
    std::sort(vect.begin(), vect.begin() + 3);
    for(auto it : vect){
        it.print();
    }

    //Note: Sorting vectors is computationall expensive, so if you need to be sorting your vector
    // continuously, probably you want to use std::set instead.

    return 0;
}