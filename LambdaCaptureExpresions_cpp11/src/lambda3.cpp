
#include <iostream>

using namespace std;

int main()
{
    auto one = 1;
    auto two= 2;
    auto three = 3;

    // basic lambda expresion [capture](arguments){logic} ()call;
    // This wont compile : [](){ cout << one << endl; } ()

    //capture one by value
    [one, two](){ cout << one << endl; } ();

    //capture all local variables by value
    [=](){ cout << one << " , " << two << " , " << three << endl; } ();

    //capture one two local variables by value and three by reference. so doing two =6 wont work because two is captured by value
    [=, &three](){ 
        three = 4;
        cout << one << " , " << two << " , " << three << endl; 
        } ();

    //capture all local variables by reference
    [&](){ 
        one = 4;
        two = 5;
        three = 6;
        cout << one << " , " << two << " , " << three << endl; 
    } ();
    cout << one << " , " << two << " , " << three << endl; 
        one = 1;
        two = 2;
        three = 3;
    //capture all local variables by reference except two by value
    [&, two](){ 
        one = 4;
        cout << one << " , " << two << " , " << three << endl; 
    } ();

    return 0;
}