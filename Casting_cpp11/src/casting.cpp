
#include <iostream>
using namespace std;

class Parent {
public:
	virtual void speak() {
		cout << "parent!" << endl;
	}
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {

	Parent parent;
	Brother brother;
//Static Cast
	Parent *ppb = &brother; // Pointing to subclass from superclass type pointer works without casting because of polymorphism

	Brother *pbb = static_cast<Brother *>(ppb); // However, trying to point to a superclass needs casting 
    //Very unsafe, if we call methods from parent not existing in brother.
    //STATIC CAST is a compile time thing, carefull it can be dangerous when running the program.

	cout << pbb << endl;

	Parent &&p = static_cast<Parent &&>(parent);
	p.speak();

//Dynamic Cast: Will detect at runtime if the casting makes sense
    Parent *pPB = &parent; // Pointing to subclass from superclass type pointer works without casting because of polymorphism
    Parent *pPB2 = &brother; 
	Brother *pBB = dynamic_cast<Brother *>(pPB); 
	Brother *pBB2 = dynamic_cast<Brother *>(pPB2); 

    if(pBB == nullptr){
        cout<<"Invalid casting "<<pBB<<endl;
    }
    else {
        cout<<"Valid casting "<<pBB<<endl;
    }
    if(pBB2 == nullptr){
        cout<<"Invalid casting "<<pBB2<<endl;
    }
    else {
        cout<<"Valid casting "<<pBB2<<endl;
    }

//Reinterpret cast: Crazy type of casting.
    Sister sister;
    //does not make sense to cast brother to sister of viceversa
    Parent *pParentBrother = &brother; 
    Parent *pSister = reinterpret_cast<Sister *>(pParentBrother); // evenless chacking than static cast.
    //we can cast anything to anything. Dangerous.
    if(pSister == nullptr){
        cout<<"Invalid casting "<<pBB2<<endl;
    }
    else {
        cout<<"Valid casting "<<pBB2<<endl;
    }

	return 0;
}