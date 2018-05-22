
#include <iostream>
using namespace std;
//Functors is more a pre cpp 11, in cpp 11 lambda expresions were introduced.
//they also work in cpp 11

//with this you can have internal state using private variables, as in difference from function pointer.

struct Test {//This is a Functor!
    virtual bool operator() (string & text) = 0;
    virtual ~Test() {};
};

struct MatchTest : public Test {//in struct all methods and variables are public by default (private for classes)
    virtual bool operator() (string & text){ // a FUNCTOR is this, overloading this operator. It can have more private methods or variables if needed
        return text=="lion";
    };
};

void check(string text, Test & test){
    if ( test(text) ) { //So test( ) here is not a function but an object! Functor.
        cout<< "Match!"<<endl;
    }
    else {
        cout<< "No Match!"<<endl;
    }
};

int main()
{
    MatchTest pred;

    string value("lion");
    string value2("tiger");

    cout << pred(value) << endl;
    cout << pred(value2) << endl;

    check(value, pred);
    check(value2, pred);
    
    return 0;
}