#ifndef FRACTAL_MANDELBROT_H
#define FRACTAL_MANDELBROT_H

#include <iostream>
#include <cstdint>
#include <memory>// to use smart pointers
#include <complex>
#include "bitmap_header.h"
#include "bitmap_info_header.h"

namespace fractal_project {

class Mandelbrot
{
public:
    Mandelbrot();
    Mandelbrot(const int max_iter);

    virtual ~Mandelbrot();

    int getIterations(double pX, double pY);
    
public:
    int MAX_ITERATIONS{1000};
private:
//Variables
    double xLimit{1};
    double yLimit{1};
//Methods
};

};

#endif // !FRACTAL_MANDELBROT_H