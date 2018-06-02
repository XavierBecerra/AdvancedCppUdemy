
#include <iostream>
#include <functional> // needed to use bind

//Bind allows ou to create aliases to functions, like functions pointer. Worth knowing what it is, not used very commonly

using namespace std;

class Test {
public:
    int add2 (const int a, const int b, const int c){
        cout << a << " "<< b << " "<< c << endl;
        return a + b + c;
    };
};

int add (const int a, const int b, const int c){
    cout << a << " "<< b << " "<< c << endl;
    return a + b + c;
};

int run (function<int(int, int)> func){
    return func(7,3);
};

int main()
{
    cout << add(1, 2, 3) << endl;

    int myint = 10;
 
    // See: http://en.cppreference.com/w/cpp/utility/functional/bind
    auto calculator = std::bind( add , 2, 3, 4);
    cout<< calculator() << endl;

    auto calculator2 = std::bind( add , myint, 3, 4);
    cout<< calculator2() << endl;

    myint = 20;

    cout<< calculator2() << endl;

    // see http://en.cppreference.com/w/cpp/utility/functional/placeholders
    //you can change order of placeholders
    auto calculator3 = std::bind( add , placeholders::_1, placeholders::_2, placeholders::_3);
    cout<< calculator3(10, 20, 30) << endl;

    auto calculator4 = std::bind( add , placeholders::_1, 100, placeholders::_2);
    cout<< calculator4(10, 20) << endl;

    cout<< run(calculator4) << endl;


    Test test;
    auto calculate = std::bind( &Test::add2 , test,  placeholders::_1, 100, placeholders::_2);
    cout<< calculator4(21, 20) << endl;


    return 0;
}