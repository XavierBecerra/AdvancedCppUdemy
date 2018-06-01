
#include <iostream>

using namespace std;

int main()
{
    int cats = 3;

    // cats is captured by value, so thelambda expresion is not changing the local variable cats
    // However, because of the key mutable, it can change the copy of cats internally on the lambda expresion
    // 
    [cats]() mutable {
        cout <<cats << endl;
        cats = 6;
        cout <<cats << endl;
    } ();
    cout <<cats << endl;
    
    return 0;
}