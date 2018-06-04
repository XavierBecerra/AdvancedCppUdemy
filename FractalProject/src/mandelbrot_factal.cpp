#include "mandelbrot_fractal.h"

namespace fractal_project {

Mandelbrot::Mandelbrot() : 
    MAX_ITERATIONS(100){
    
};
Mandelbrot::Mandelbrot(const int max_iter) : 
    MAX_ITERATIONS(max_iter) {
    
};

Mandelbrot::~Mandelbrot() {

};
    
int Mandelbrot::getIterations(double pX, double pY) {
    int iter{0};
    //scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
    //scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
    auto c0 = std::complex<double>(pX, pY);
    std::complex<double> z(0.,0.);
    while ((norm(z) < 4.)//modulues <2
        && iter < MAX_ITERATIONS ) {
            z = z*z + c0;
            iter ++;
    };
    return iter;
};

};
