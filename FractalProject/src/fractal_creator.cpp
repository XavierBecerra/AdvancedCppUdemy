#include "fractal_creator.h"
#include <math.h>
#include <assert.h>
#include <QPointF>

using namespace std;

namespace fractal_project {

FractalCreator::FractalCreator() : 
    m_pHistogram(new int[100]{0}), 
    m_pIterations(new int[100* 100]{0} ) {

        auto zoom = Zoom(100/2., 100/2., 4./100 );
        addZoom(zoom );
};

FractalCreator::FractalCreator(const int width , const int height, const int max_iterations, const std::string & filename): 
    m_bitmap( width , height ),
    m_fractal( max_iterations ), 
    m_zoomlist( width , height ),
    m_pHistogram(new int[max_iterations]{0}), 
    m_pIterations(new int[width * height]{0} ),
    m_filename(filename) {

        auto zoom = Zoom(width/2., height/2., 4./width );
        addZoom(zoom );
};

FractalCreator::~FractalCreator(){

};

void FractalCreator::run() {
    computeIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(m_filename);
    
    setPixmap(QPixmap(m_filename.data()));
};

int FractalCreator::calculateTotalIterations(){
    int total = 0;
    for(int i = 0 ; i < m_fractal.MAX_ITERATIONS ; i++) {
        total += m_pHistogram[i];
    }
    return total;
};
//for a given range 0-based
int FractalCreator::calculateTotalIterations(const unsigned int range){
    int total = 0;
    assert( (range + 1) < m_colorRange.size() );

    for(int i = m_colorRange[range].first ; i < m_colorRange[range + 1].first ; i++) {
        total += m_pHistogram[i];
    }

    return total;
};

unsigned int FractalCreator::getRange(const int nr_iterations){
    unsigned int range = 0;

    for(unsigned int i = 0; i < m_colorRange.size() ; i++) {

        if(    ( m_colorRange[i].first <= nr_iterations )
            && ( m_colorRange[i+1].first > nr_iterations ) )
            {
                range = i; 
                break;
            }
    }

    assert( (range + 1) < m_colorRange.size() );
    return range;
};

void FractalCreator::calculateRangeTotals() {

	int rangeIndex = 0;

	for (int i = 0; i <m_fractal.MAX_ITERATIONS; i++) {
		int pixels = m_pHistogram[i];

		if (i >= m_colorRange[rangeIndex].first) {
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
}

void FractalCreator::computeIterations(){

    for(auto x = 0 ; x < m_bitmap.getWidth() ; x++) {
        for(auto y = 0 ; y < m_bitmap.getHeight() ; y++) {

            //double pX = x * 3.5 / bitmap.getWidth() - 2.5; 
            //double pY = y * 2. / bitmap.getHeight() - 1.;
            auto coord = m_zoomlist.doZoom(x, y);

            auto iterations = m_fractal.getIterations(coord.first, coord.second);

            m_pIterations[x + y * m_bitmap.getWidth()] = iterations;
            if(iterations < m_fractal.MAX_ITERATIONS) {
                m_pHistogram[iterations] ++;
                // So that the iner area of fractal (which reaches max iterations) is painted black
            } 
        }
    }
};

void FractalCreator::drawFractal(){
    auto pColorRatios = calculateColorRatios();

    for(auto x = 0 ; x < m_bitmap.getWidth() ; x++) {
        for(auto y = 0 ; y < m_bitmap.getHeight() ; y++) {

            int iterations = m_pIterations[x + y * m_bitmap.getWidth()];
            
            RGB_t color(0,0,0);
            // when iterations is maximum number, then we paint the pixel black. Internal pixels on the fractal
            if (iterations < m_fractal.MAX_ITERATIONS) {

                auto range = getRange(iterations);

                RGB_t startColor = m_colorRange.at(range).second;
                RGB_t endColor = m_colorRange.at(range + 1).second;
                RGB_t diffColor = endColor - startColor;

				//int accPixels = 0;
                //for(int i = m_colorRange.at(range).first ; i < iterations ; i++) {
                //    accPixels += m_pHistogram[i];
                //} // read mandelbot coloring histogram in google
                color = startColor + diffColor * pColorRatios[iterations];//pow(255, hue*hue);
            }

            m_bitmap.setPixel(x, y, color.red, color.green, color.blue);    
        }
    }
};

std::unique_ptr< double[] > FractalCreator::calculateColorRatios() {
    std::unique_ptr< double[] > pAccPixels(new double[m_fractal.MAX_ITERATIONS]{0});

    for (int iter = 0; iter < m_fractal.MAX_ITERATIONS; iter ++) {
        auto range = getRange(iter);
        auto total = calculateTotalIterations(range);

        double accPixels = 0.0;
        for(int i = m_colorRange.at(range).first ; i < iter ; i++) {
            accPixels += static_cast<double>(m_pHistogram[i]);
        } 
        pAccPixels[iter] = accPixels / total;
    }

    return pAccPixels;
};

void FractalCreator::writeBitmap(const std::string & filename){
    m_bitmap.writeToFile( filename );
};

void FractalCreator::addZoom(const Zoom & zoom){
    m_zoomlist.add(zoom);
};

bool FractalCreator::removeZoomAnMAybeRedraw(){
    bool redrawNedded = m_zoomlist.remove();
    return redrawNedded;
};

void FractalCreator::addColor(const double & iterations_pct, const RGB_t & color) {
    auto checkPoint = std::pair<double, RGB_t>( iterations_pct * m_fractal.MAX_ITERATIONS , color );
    m_colorRange.push_back( checkPoint );

	m_rangeTotals.push_back(0);
}

void FractalCreator::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QPointF mousePos = event->pos();

    if(event->button() == Qt::RightButton) {
        if( removeZoomAnMAybeRedraw() ){
            run();
        };
    }
    else {
        addZoom(Zoom(mousePos.x() , getHeight() - mousePos.y() , 0.1) );
        run();
    }

};

//getters
int FractalCreator::getWidth() const {
    return m_bitmap.getWidth();
};
int FractalCreator::getHeight() const {
    return m_bitmap.getHeight();
};
//setters
void FractalCreator::setStartColor(const RGB_t & color){
    m_startColor = color;
};
void FractalCreator::setEndColor(const RGB_t & color){
    m_endColor = color;
};

}; // !namespace fractal_project