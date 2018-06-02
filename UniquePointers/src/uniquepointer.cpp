
#include <iostream>
#include <memory>// to use smart pointers

using namespace std;

class Test
{
public:
    Test() {
        cout << "Constructed" << endl;
    }

    ~Test() {
        cout << "Destructed" << endl;
    }

    void speak() const {
        cout << "  Hello" << endl;
    }
};

class Temp {
private:
    unique_ptr<Test[]> pTest = nullptr;
public:
    Temp() : pTest(new Test[2]) {

    };
};

int main()
{
    //see http://en.cppreference.com/w/cpp/memory/unique_ptr
    unique_ptr<int> pInt{new int};
    *pInt =8;
    //cout <<  *pInt << endl;
    {
    unique_ptr<Test[]> pTest(new Test[2]);
    //cout << pTest.get() << endl;
    //pTest.reset();
    //cout << pTest.get() << endl;
    pTest[0].speak();
    pTest[1].speak();
    };// uniue pointers will deallocate memory when they go out of scope.
    cout <<  endl;
    {
    Temp temp;
    }
    cout << "Finished" << endl;
    
    return 0;
}