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
    

    return 0;
}