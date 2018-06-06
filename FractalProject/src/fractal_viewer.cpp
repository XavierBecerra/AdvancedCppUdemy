#include "fractal_viewer.h"
#include <assert.h>

using namespace std;

namespace fractal_project {


FractalViewer::FractalViewer() : 
    FractalViewer(500, 500, 100) {

};

FractalViewer::FractalViewer(const int width , const int height, const int max_iterations, std::string filename, QObject *parent ): 
    QGraphicsScene(parent),
    m_filename(filename), 
    m_pView( new QGraphicsView(this) ),
    m_pFractalCreator(new FractalCreator(width, height, max_iterations, filename) ) {
        
        createFractal();
};

void FractalViewer::createFractal() {

	m_pFractalCreator->addColor(0.0, RGB_t(0, 0, 255));
	m_pFractalCreator->addColor(0.05, RGB_t(255, 99, 71));
	m_pFractalCreator->addColor(0.08, RGB_t(255, 215, 0));
	m_pFractalCreator->addColor(0.2, RGB_t(0, 215, 80));
	m_pFractalCreator->addColor(1.0, RGB_t(255, 255, 255));

    m_pFractalCreator->run();
}

void FractalViewer::showFractal(){
    this->addItem( m_pFractalCreator.get() );
    m_pView->show();
};

FractalViewer::~FractalViewer(){

};

}; // !namespace fractal_project