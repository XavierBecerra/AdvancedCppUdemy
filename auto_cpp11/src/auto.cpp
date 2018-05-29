
#include <iostream>

#include <typeinfo> // to be able to use typeid

using namespace std;

struct Test_t{
    int id;
    string name;
    double value;
};

auto testAuto() -> int {
    return 2;
}
//This is only usefull for template functions
template< class T>
auto templateAuto() -> T {
    T emptyObject;
    return emptyObject;
}


int get(){
    return 666;
}
auto testGet() -> decltype(get()) {
    return get();
}


int main()
{
    auto name = 7;
    auto name2 = decltype(name){3.2};
    
    cout<< "type: "<< typeid(name).name() << " , value: " << name<< endl;
    cout<< "type: "<< typeid(name2).name() << " , value: " << name2<< endl;


    cout<< "test auto 1: "<< testAuto()<< endl;
    cout<< "test auto 1: "<< templateAuto<int>()<< endl;
    cout<< "test auto 1: "<< templateAuto<string>()<< endl;
    cout<< "test nested auto 1: "<< testGet()<< endl;
    
    return 0;
}