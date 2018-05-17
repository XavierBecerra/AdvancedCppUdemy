#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <iostream>

namespace cpptutorial {

class Complex_nr
{
public:
    Complex_nr();
    Complex_nr(double real, double img);
    Complex_nr(const Complex_nr & obj);

    double getModule();

    double getReal() const {
        return real;
    };

    double getImaginary() const {
        return img;
    };

    const Complex_nr & operator= ( const Complex_nr & obj);

    const Complex_nr & operator+= ( const Complex_nr & obj) ;

private:
    double real;
    double img;
};

std::ostream & operator<< (std::ostream& out, const Complex_nr& obj);
Complex_nr operator+ (const Complex_nr& c1, const Complex_nr& c2);
Complex_nr operator+ (const Complex_nr& c, double d);
Complex_nr operator+ (double d, const Complex_nr& c);

}; /*namespace cpptutorial*/

#endif //MY_COMPLEX_H