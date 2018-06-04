
#include <iostream>

using namespace std;

class Test
{
    public:
    int id{0};
};

template<typename T>
void call (T && arg){
    check(forward<T>(arg));
    //The forward (or also static cast )here will restore the reference collapsing that happens in the input to the function.
};

void check(Test & obj){
    cout << " lvalue " << obj.id << endl;
    obj.id ++;
};

void check(Test && obj){
    cout << " rvalue " << obj.id << endl;
    obj.id ++;
};

int main()
{
    Test test;// lvalue
    auto &&t = Test(); //lvalue because of reference collapsing
    Test &&t2 = Test();
    //Reference collapsing rule in cpp 11
    //t here cannot be rvalue reference because it would not bind to l lvalue
    //the rule is that auto key, when binding to lvalue reference type, the reference will collapse so that we can bind to lvalue reference.

    call(Test());
    cout << test.id << endl;
    call(test);
    cout << test.id << endl;
    cout << t.id << endl;
    call(t);
    cout << t.id << endl;
    cout << t2.id << endl;
    call(t2);
    cout << t2.id << endl;
    
    return 0;
}