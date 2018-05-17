
#include <iostream>

//bitshit operator, << is left right associative so cout << word <<endl  is like (cout << word) <<endl
//sum operator + is right associative: 1 + 2 + 3 is like 1 + (2 + 3) 

class Test_t
{
public:
    Test_t() : m_id(0), m_name("default") {};
    Test_t(const int id, const std::string &name) : m_id(id), m_name(name) {};
    Test_t(const Test_t & other) {
        *this= other; 
    };

    ~Test_t() {
    };

    const Test_t & operator= (const Test_t & other)
    {
        m_id = other.m_id;
        m_name = other.m_name;
        return *this;
    }

    friend std::ostream & operator<< (std::ostream& out, const Test_t& obj)
    {
        out << obj.m_id << " : " << obj.m_name ;

        return out;
    };

private:
    int m_id;
    std::string m_name;
};



int main()
{
    Test_t test1(10, "Messi");
    Test_t test2(11, "Rivaldo");
    std::cout << test1 << " and " << test2 << std::endl;
    
    return 0;
}