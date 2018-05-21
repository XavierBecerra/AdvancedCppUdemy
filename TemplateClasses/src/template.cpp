
#include <iostream>
#include <map>

//When defining template classes, put them in the same heather file, definition and implementation. do not separate
// the implementation in a cpp file. Behinf scenes cpp will perform this durign compilation.
template<class T, class K>
class Test_t
{
public:
    Test_t(const T & obj, const K & obj2) : obj(obj), obj2(obj2) {};
    Test_t(const Test_t<T,K> & other) 
    {
        *this = other;
    };

    void print() const{
        std::cout << obj << " : " << obj2 << std::endl;
    };

    T getObj() const {
        return obj;
    };

    K getObj2() const {
        return obj2;
    };

private:
    T obj;
    K obj2;
};

int main()
{
    Test_t<std::string, int> messi("Messi" , 10);
    Test_t<int, std::string> xavi(6 , "Xavi");
    Test_t<double, std::string> grade(6.25 , "Grade");

    messi.print();
    xavi.print();
    grade.print();
    
    return 0;
}