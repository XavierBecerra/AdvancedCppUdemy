#ifndef FRACTAL_CREATOR_H
#define FRACTAL_CREATOR_H

#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "bitmap_class.h"
#include "mandelbrot_fractal.h"
#include "zoom_list.h"
#include "rgb_class.h"

namespace fractal_project {

class FractalCreator: public QGraphicsPixmapItem
{

public: 
    FractalCreator();
    FractalCreator(const int width , const int height, const int max_iterations,const std::string & filename = "default.bmp");
    ~FractalCreator();
//public methods
    void run();
    void addZoom(const Zoom & zoom);
    bool removeZoomAnMAybeRedraw();
    void addColor(const double & iterations_pct, const RGB_t & color);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

//getters
    int getWidth() const;
    int getHeight() const;
//setters
    void setStartColor(const RGB_t & color);
    void setEndColor(const RGB_t & color);

private:
    Bitmap m_bitmap{100, 100};
    Mandelbrot m_fractal{100};
    ZoomList m_zoomlist{100, 100};

    RGB_t m_startColor{0, 0, 0};
    RGB_t m_endColor{255, 255, 255};

    std::vector< std::pair< double, RGB_t> > m_colorRange;
	std::vector<int> m_rangeTotals;

    std::unique_ptr< int[] > m_pHistogram = nullptr; // https://stackoverflow.com/questions/16711697/is-there-any-use-for-unique-ptr-with-array?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
    std::unique_ptr< int[] > m_pIterations = nullptr;
    std::string m_filename;

    bool m_bGotFirstRange{false};

    //methods
    int calculateTotalIterations();
    int calculateTotalIterations(const unsigned int range);
    unsigned int getRange(const int nr_iterations);
    void computeIterations();
    void drawFractal();
    void writeBitmap(const std::string & filename);
    void calculateRangeTotals();
    std::unique_ptr< double[] > calculateColorRatios();
};

};

#endif //!FRACTAL_CREATOR_H