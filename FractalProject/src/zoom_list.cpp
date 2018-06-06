#include <iostream>
#include "zoom_list.h"

using namespace std;

namespace fractal_project {

ZoomList::ZoomList() {

};

ZoomList::ZoomList(const int width, const int height) :
    m_width(width),
    m_height(height){

};

void ZoomList::add(const Zoom & zoom){
    m_zooms.push_back(zoom);

    //Lets recalculate the center position to zoom in fractal coordinates
    m_xCenter += (zoom.x - m_width/2.) * m_scale;
    m_yCenter += (zoom.y - m_height/2.) * m_scale;

    m_scale *= zoom.scale;
};

bool ZoomList::remove(){
    bool redrawNedded = false;
    if( m_zooms.size() > 1) {
        auto zoom = m_zooms.back();

        //Lets recalculate the center position to zoom in fractal coordinates
        m_scale = m_scale / zoom.scale;

        m_xCenter -= (zoom.x - m_width/2.) * m_scale;
        m_yCenter -= (zoom.y - m_height/2.) * m_scale;

        m_zooms.pop_back();
        redrawNedded = true;
    };
    return redrawNedded;
};

std::pair<double, double> ZoomList::doZoom(int x, int y) {
    double xFractal = (x - m_width/2.) * m_scale + m_xCenter;
    double yFractal = (y - m_height/2.) * m_scale + m_yCenter;

    return std::pair<double, double> (xFractal, yFractal);
};

ZoomList::~ZoomList() {
    
};

};