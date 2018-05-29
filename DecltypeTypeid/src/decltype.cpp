
#include <iostream>

//decltype is new cpp 11 keyword
//typeid was already present.

#include <typeinfo> // to be able to use typeid

using namespace std;

struct Test_t{
    int id;
    string name;
    double value;
};

int main()
{
    Test_t value;

    decltype(value) name ;//= "something";

    cout<< "type: "<< typeid(value).name() << endl;
    cout<< "type: "<< typeid(name).name() << endl;//" , value: "<< name<< endl;
    
    return 0;
}