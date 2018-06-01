
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
		cout << "constructor" << endl;
	}

	Test(int i) : Test() {
		cout << "parameterized constructor" << endl;
        for(int it = 0; it < SIZE; it++){
            m_pBuffer[it] = i;
        }
	}

	Test(const Test &other) : Test() {
		cout << "copy constructor" << endl;
        memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));
	}

	Test &operator=(const Test &other) {
		cout << "assignment" << endl;
        memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));
		return *this;
	}

	~Test() {
        delete [] m_pBuffer;
        m_pBuffer = nullptr;
		cout << "destructor" << endl;
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

int main() {

	Test test1 = getTest();

	cout << test1 << endl;

	vector<Test> vec;
	vec.push_back(Test());

    // lvalue reference is a 'normal' reference that we can only bind to lvalues
    Test & rTest1 = test1;
    //We cannot bind an Lvalue reference to an Rvalue (like the return value of a function for xample):
    //Test & rTest2 = getTest();
    // But wecan make it work by making const. Because const lvalue references can in fact bind to Rvalues
    // The lifetime of the rvalue returned by the function in this case gets extended so as long as the reference exists the rvalue aso gets extended and not gets destroyed.
    //It will get destroyed when the reference gets out of scope.
    const Test & rTest3 = getTest();
    // note that copy constructors always have a const T & as input:
    Test test2(Test(3));
    //Test(3) is an Rvalue, its not gonna name, so we cannot take adress of it. We pass it to copy constractor and causes a Lvalue



	return 0;
}