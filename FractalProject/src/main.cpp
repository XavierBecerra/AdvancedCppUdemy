
#include <iostream>
#include "fractal_creator.h"

using namespace std;
using namespace fractal_project;

//http://developer.mantidproject.org/ProfilingWithValgrind.html

int main()
{
    FractalCreator fractalCreator(500, 500, 1000);

    fractalCreator.setStartColor( RGB_t(0, 0, 0) );
    fractalCreator.setEndColor( RGB_t(0, 255, 255) );
    
	fractalCreator.addColor(0.0, RGB_t(0, 0, 255));
	fractalCreator.addColor(0.05, RGB_t(255, 99, 71));
	fractalCreator.addColor(0.08, RGB_t(255, 215, 0));
	fractalCreator.addColor(1.0, RGB_t(255, 255, 255));

    fractalCreator.addZoom(Zoom(295. ,fractalCreator.getHeight() - 202 , 0.1) );
    fractalCreator.addZoom(Zoom(312. ,fractalCreator.getHeight() - 304 , 0.1) );

    fractalCreator.run("Fractal.bmp");

    cout<<endl << "Go Fractals!" <<endl;
    return 0;
}