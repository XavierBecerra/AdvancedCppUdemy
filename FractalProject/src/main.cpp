
#include <iostream>
#include "fractal_viewer.h"

#include <QApplication>
#include <QMainWindow>
#include <stdio.h>

using namespace std;
using namespace fractal_project;

//http://developer.mantidproject.org/ProfilingWithValgrind.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    unique_ptr<QMainWindow> window{ new QMainWindow() };

    std::string filename = "Fractal.bmp";
    FractalViewer fractalViewer(500, 500, 500, filename, window.get());
    fractalViewer.showFractal();

    cout<<endl << "Go Fractals!" <<endl;
    
    return a.exec();
}