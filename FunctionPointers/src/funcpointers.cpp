
#include <iostream>

// we can declare a pointer to a function and passa that around.
//They are used also behind the secne, like when using virtual functions, what is used behind the scene is a table of function pointers.

void test(int value, double in)
{
    std::cout << "Hello World! " << value << " : " << in<<std::endl;
}


int main()
{
    test(2, 2.5);

    //void (*pTest)();//pointer t a function with no parameters

    //pTest = test; // this points pTest to the test function, not calling it. The name of a function is per se the pointer to that function
    void (*pTest)(int ,double) = test;
    //(*pTest)() ; // this is to apply the dereference operator * before.  But not needed in cpp 11
    pTest(1, 1.5);
    
    return 0;
}