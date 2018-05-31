
#include <iostream>

using namespace std;

class Test_t
{
public:
    Test_t() = default; //important to keep default constructor that will set initialization as defined below for each member. Specially when other constructors are addeed like the one overwritting id.
    Test_t(int init) : age(init) {};// when defining this constructor you lose the defualtconstructo. Thats why adding line above!!
    Test_t(const Test_t & other) = default; // copy constructor by defaut
    //Test_t(const Test_t & other) = delete; // this would delete the copy constructor, so not available!
    Test_t & operator= (const Test_t & other) = default; // copy constructor by defaut
   // Test_t & operator= (const Test_t & other) = delete; // assignemtn could not be done. so person1 = person2 would not compile

    void print() const {
        cout << name << " age: " << age <<endl;
    };

private:
    string name{"Someone"};
    int age{45};
};

int main()
{
    Test_t person1;
    person1.print();

    Test_t person2(77);
    person2.print();

    Test_t person3(person2);
    person3.print();

    Test_t person4 = person3;
    person3.print();
    return 0;
}