
#include <iostream>
#include <memory>// to use smart pointers

//Shared pointers, differ from unique pointers, because they dont delete thevariable associated to them until ALL them
// pointers pointing to it get out of scope or get assigned to another memory.

using namespace std;

class Test
{
public:
    Test() {
        cout << "Constructed" << endl;
    }
    Test(int id) : id(id){
        cout << "Constructed object " << id << endl;
    }

    ~Test() {
        cout << "Destructed object " << id << endl;
    }

    void speak() const {
        cout << "  Hello object "<< id << endl;
    }
private:
    int id{0};
};

int main()
{
    shared_ptr<Test> pTest3(nullptr);
    shared_ptr<Test> pTest1(new Test(1));

    {
    shared_ptr<Test> pTest2 = make_shared<Test>(2);// more efficient than use move constructor with new like above.
    
    pTest3 = pTest2;

    pTest1->speak();
    pTest2->speak();
    pTest3->speak();
    }

    cout << "finished"<< endl;
    return 0;
}