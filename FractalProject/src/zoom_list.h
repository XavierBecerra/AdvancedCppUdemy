#ifndef FRACTAL_ZOOMLIST_H
#define FRACTAL_ZOOMLIST_H

#include <vector>
#include <utility>
#include "fractal_zoom.h"

namespace fractal_project {

class ZoomList
{
public:
    ZoomList();
    ZoomList(const int width, const int height);

    void add(const Zoom & zoom); 
    void remove();

    std::pair<double, double> doZoom(int x, int y);

    virtual ~ZoomList();
    
private:
    double m_xCenter{0.0};
    double m_yCenter{0.0};
    double m_scale{1.0};
    int m_width{0};
    int m_height{0};
    std::vector<Zoom> m_zooms;
};

};

#endif // !FRACTAL_ZOOMLIST_H