
#include <iostream>
using namespace std;

class Parent_t
{
public:
    //Default constructor 
    Parent_t() : name("noone") {};
    Parent_t(const string & name) : name(name) {};
    //Copy constructor 
    Parent_t( const Parent_t & other){
        cout<< "copy parent" << endl;
        *this = other;
    };

    virtual void print() const {
        cout<< "Parent "<< name << endl;
    };

    virtual ~Parent_t(){};

protected:
    string name;
};

class Child_t : public Parent_t
{
public:
    //Default constructor 
    Child_t() : firstName("nobody"), Parent_t("noonez") {};
    Child_t(const string & name) : firstName(name), Parent_t("noonez") {};
    //Copy constructor 
    Child_t( const Child_t & other){
        cout<< "copy child" << endl;
        *this = other;
        //one = other.one;
    };
    virtual void print() const {
        cout<< "Child "<< firstName << " "<< name << endl;
    };
private:
    string firstName;//object slicing. This is a child only part, and commont parent class is name
};

int main()
{
    Child_t obj1("Joan");
    Parent_t &obj2 = obj1;
    Parent_t obj3 = Child_t("Toni");
    Parent_t obj4;

    obj1.print();
    obj2.print();
    obj3.print();
    obj4.print();
    return 0;
}