
#include <iostream>

using namespace std;

void test( void (*pFunc)() ) {
    pFunc();
};

int main()
{
    [](){cout << "Direct call of Lambda expresion" << endl; } ();
    
    auto sayHi = [](){
        cout << "Hello" << endl;
    };

    sayHi();
    test( sayHi );
    test( [](){cout << "Hi again" << endl; });

    return 0;
}