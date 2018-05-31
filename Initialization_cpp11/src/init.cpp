
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template<class T>
class Test{

public:
    Test(initializer_list<T> list) {
        for ( auto it : list) {
            cout << it << endl;
        }
    };

    void print(initializer_list<T> list) {
        for ( auto it : list) {
            cout << it << endl;
        }
    };
};

int main()
{
    int val{5};
    string text {"Hi"};
    double num[]{1.0, 1.1, 1.2, 1.3};// this uses  initializer_list
    int *pInt = new int[3]{1, 2, 3};

    cout << val << "  " <<endl;
    cout << text << "  " <<endl;
    cout << num[2] << "  " <<endl;
    cout << pInt[2] << "  " <<endl;


    int *pInt2{};//init to default values for pinters is nullptr
    cout << pInt2 << "  " <<pInt << "  " <<endl;

    vector<string> stri{"one", "two", "three"};//init to default values for pinters is nullptr
    cout << stri[0] << "  " <<stri[2] << "  " <<endl;

    //initialization lists
    vector<int> numbers {1, 2, 3, 4};
    cout << numbers[2]  <<endl;

    Test<int> ts{10, 20, 30};

    ts.print({100, 200, 300});

    delete pInt, pInt2;
    return 0;
}