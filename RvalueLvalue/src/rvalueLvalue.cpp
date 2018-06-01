
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

//int val = 7;
//in cpp 11:
//L value (left side of assignment) is anything we can take a reference of. in example above we can do int *pval = & val, val is Lvalue
//R value (right side of assignment) is anything we can NOT take a reference of. in example above we can NOT do int *pval = &7, 7 is Rvalue

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
    // here test1 is an Lvalue so we could do:
    Test *ptest = & test1;
    // but getTest() is an Rvalue. All values that are return from a functions are Rvalues sinse they will be destructed, hence we cannot take their reference.
    // we cannot do Test *ptest = & getTest();

	cout << test1 << ptest<< endl;

    int val = 7;
    int * pval = & val;
    //This will work because first applies ++ in the val and then takes it reference to assign to pval2.
    int * pval2 = &++val;
    cout << val << " "<< *pval << " "<< *pval2 << endl;
    // BUT: doing int * pval3 = &val++; will not work because
    // there is a temporary value in here, because the postfix ++ operator needs to use the value and then afterwards increment it
    // so it needs to create a copy of the value so that it can be used. So when cpp is trying to get the adress of (val++) it 
    // cannot because even though val is Lvalue, val++ is Rvalue (++val is Lvalue)

    //another example:
    //int sum = 7 + val  vla is Lval, but (7 + val) is Rval and you cannot thake its reference.
    //int * pSum = &(7 + val); // will not compile

	//vector<Test> vec;
	//vec.push_back(Test());

	return 0;
}