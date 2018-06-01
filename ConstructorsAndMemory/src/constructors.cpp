
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

	return 0;
}