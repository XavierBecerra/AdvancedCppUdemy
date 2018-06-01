
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

//The move constructor looks a lot like the copy constructor, except that it uses rvalue references


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
	}

	Test(int i) : Test() {
        for(int it = 0; it < SIZE; it++){
            m_pBuffer[it] = i;
        }
	}

	Test(const Test &other) : Test() {
        memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));
	}

	Test(Test &&other) : Test() { // other can not be const because it has to change it.
    //other is temporary value (rvalue) and we want to steal its information before it gets destroyed.
        m_pBuffer = other.m_pBuffer;
        other.m_pBuffer = nullptr; // so when other gets destructed, it will not deallocate the memory this class is now usig.
        // so we steal the info fom the rvalue before it gets destructed, and then we reference the rvalue pointer  to nullptr
        // so when it gets deallocated we dont have future problems.
	}

	Test &operator=(const Test &other) {
        memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));
		return *this;
	}

	~Test() {
        delete [] m_pBuffer;
        m_pBuffer = nullptr;
	}

	friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
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

	vector<Test> vec;
    vec.push_back(Test());

	return 0;
}