
#include <iostream>

using namespace std;

int main()
{
    //C++ 98
    int values[3] = {1,2,3};
    cout << values[0] << endl;

    class C
    {
    public:
        string text;
        int id;
    };

    C c1 = {"Hi", 21};
    cout << c1.id << c1.text << endl;

    struct S
    {
        string text;
        int id;
    };

    S s1 = {"Hello", 12};
    cout << s1.id << s1.text << endl;

    struct    {
        string text;
        int id;
    }s2 = {"Bye", 10};
    cout << s2.id << s2.text << endl;

    return 0;
}