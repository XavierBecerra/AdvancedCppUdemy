
#include <iostream>

using namespace std;

void testRepeat ( void (*pFunc)(const string &), string say) {
    pFunc(say);
};

void testDevide ( double (*pFunc)(const double a, const double b)) {
   cout <<  pFunc(9., 3.) << endl;
};

int main()
{
    
    auto repeat = [](const string & _this){
        cout << _this << endl;
    };

    repeat("I am me");
    testRepeat( repeat, "I am me" );

    auto pDivide = [](const double a, const double b){
        return a/b;
    };
    cout << pDivide(10.,5.) << endl;

    // with multiple return statements type must be specified. This is done in->
    auto pDivide2 = [](const double a, const double b) -> double {

        if (b == 0.0){
            return 0;
        }

        return a/b;
    };
    cout << pDivide2(10.,5.) << endl;
    testDevide(pDivide2 );

    return 0;
}