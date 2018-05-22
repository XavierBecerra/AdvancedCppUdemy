
#include <iostream>
using namespace std;

// An abstract class are classes that contain methods that have no implementation. They are pure virtual functions.
// They dont make sense to intanciate. Usiually instanciate its childs
class Animal_t  //Abstract class
{
public:
    virtual void run() = 0;
    virtual void speak() const = 0;//pure virtual function

};

class Dog_t : public Animal_t //still abstract class becaus virtual function run not implemented Cannot be instanciatted.
{
public:
    void speak() const {
        cout << "Guau Guau!" << endl;
    }

};

class Retriever_t : public Dog_t
{
public:
    Retriever_t() {
        cout << "New Retriever" << endl;
    };
    void run() {
        cout << "Retriever_t Running!" << endl;
    }

};

void test (Animal_t& in)
{
    in.speak();
    in.run();
};

int main()
{
    Retriever_t i[4];
    i[1].speak();
    i[1].run();

    // we cannot create an array of Animal_t but yes an array of pointers to animals.
    Animal_t * animals[3];
    animals[0] = &i[1];
    animals[0]->speak();
    animals[0]->run();

    test (i[2]);
    test (*animals[0]);

    return 0;
}