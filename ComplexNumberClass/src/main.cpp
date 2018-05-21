#include <iostream>
#include "my_complex.h"

using namespace cpptutorial;

int main()
{
    Complex_nr c1(2., 2.);
    std::cout << c1 << " with module: "<< c1.getModule() << std::endl;
    std::cout << c1 << " + " << c1 << std::flush;
    c1 += c1;
    std::cout << " = " << c1 << std::endl;

    Complex_nr c2(1., 3.);
    std::cout << c2 << std::endl;

    Complex_nr c3 = c1 + c2;
    std::cout << c1 << " + " << c2 << " = " << c3 << std::endl;

    double d = 2.;
    c3 = c1 + d;
    std::cout << c1 << " + " << d << " = " << c3 << std::endl;
    Complex_nr c4 = d + c1;
    std::cout << d << " + " << c1 << " = " << c4 << std::endl;

    Complex_nr c5 = c1;
    if(c1 == c5)
    {
        std::cout<< c1 << " equal than " << c5<< std::endl;
    }    
    else
    {
        std::cout<< c1 << " not equal than " << c5<< std::endl;
    }  

    if(c1 != c2)
    {
        std::cout<< c1 << " not equal than " << c2<< std::endl;
    }    
    else
    {
        std::cout<< c1 << " equal than " << c2<< std::endl;
    }    

    std::cout<< "The Conjugate of "<< c1 << " is " << *c1<< std::endl;

    Complex_nr c6(1 , 4);
    std::cout<< *c1 << " + " << c6<< " = " << *c1 + c6 << std::endl;

    Complex_nr c7(1 , 0);
    Complex_nr c8(0 , -2);
    bool less_than = c7 < c8;
    std::cout<< c7 << " < " << c8 << " ? " << less_than << std::endl;
    less_than = c8 < c7;
    std::cout<< c8 << " < " << c7 << " ? " << less_than << std::endl;

    return 0;
}