
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE = 100;
    int *m_pBuffer{nullptr};

public:
	Test() {
        m_pBuffer = new int[SIZE]{};
        // init buffer to zeros with the {} above
        //or:
        //memset(m_pBuffer, 0 , sizeof(int)*SIZE);
		//cout << "constructor" << endl;
	}

	Test(int i) : Test() {
		//cout << "parameterized constructor" << endl;
        for(int it = 0; it < SIZE; it++){
            m_pBuffer[it] = i;
        }
	}

	Test(const Test &other) : Test() {
		//cout << "copy constructor" << endl;
        memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));
	}

	Test &operator=(const Test &other) {
		//cout << "assignment" << endl;
        memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));
		return *this;
	}

	~Test() {
        delete [] m_pBuffer;
        m_pBuffer = nullptr;
		//cout << "destructor" << endl;
	}

	friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
	out << "Hello from test";
	return out;
}

Test getTest() {// Bad practice teturning by value
	return Test();
}

void check(const Test & value) {
    cout << "Lvalue function"<< endl;
};

void check(Test && value) {
    cout << "Rvalue function"<< endl;
};

void show(const int & value) {
    cout << "Lvalue function "<< value << endl;
};

void show(int && value) {
    cout << "Rvalue function "<< value << endl;
};

int main() {

	Test test1 = getTest();

	cout << test1 << endl;

    // if we can identify temporary values (Rvalues) on time we can handle them differently than non-temporary values (Lvalues)
    // for example return values from a function like getTest() here
    // or construction by copy such as:
    Test test2(Test(4));

    //lvalue reference:
    Test &ltest = test1;
    //rvalue reference: has && two &
    //Test &&rtest = test1; // this will not compile bcause is trying to bind rvalue &&rtest, to an lvalue test1.
    Test &&rtest1 = Test();// this is binding rvalue to rvlaue
    Test &&rtest2 = getTest();// this is binding rvalue to rvlaue

    check(Test());
    check(getTest());
    check(test1);

    //This will beused to move constructors, which is much efficient than copy constructors.
    show(8);
    int int1 = 6;
    show(int1);
    show(int1++);
    show(int1);
    show(++int1);

	return 0;
}