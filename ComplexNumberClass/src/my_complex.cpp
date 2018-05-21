#include "my_complex.h"
#include <cmath>

namespace cpptutorial {

std::ostream & operator<< (std::ostream& out, const Complex_nr& obj)
{
    out << "(" << obj.getReal() << " + " << obj.getImaginary() << "i)";

    return out;
};

Complex_nr operator+ (const Complex_nr& c1, const Complex_nr& c2)
{
    return Complex_nr(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
};

Complex_nr operator+ (const Complex_nr& c, double d)
{
    return Complex_nr(d + c.getReal(), c.getImaginary());
};

Complex_nr operator+ (double d, const Complex_nr& c)
{
    //return c + d;
    return Complex_nr(d + c.getReal(), c.getImaginary());
};


Complex_nr::Complex_nr() : real(0), img(0) {};
Complex_nr::Complex_nr(double real, double img) : real(real), img(img) {};
Complex_nr::Complex_nr(const Complex_nr & obj){
    *this = obj;
};

double Complex_nr::getModule() {
    return std::sqrt( std::pow(real, 2.0) + std::pow(img, 2.0) );
};

const Complex_nr & Complex_nr::operator= ( const Complex_nr & obj) 
{
    real = obj.real;
    img = obj.img;

    return *this;
};

const Complex_nr & Complex_nr::operator+= ( const Complex_nr & obj) 
{
    real += obj.real;
    img += obj.img;

    return *this;
};

bool Complex_nr::operator== ( const Complex_nr & obj) const
{
    return (real == obj.real) && (img == obj.img);
};

bool Complex_nr::operator!= ( const Complex_nr & obj) const
{
    return !(*this == obj);
    //return (real != obj.real) || (img != obj.img);
};

}; /*namespace cpptutorial*/