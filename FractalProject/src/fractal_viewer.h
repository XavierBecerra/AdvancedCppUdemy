#ifndef FRACTAL_VIEWER_H
#define FRACTAL_VIEWER_H

#include <string>
#include <vector>
#include <utility>
#include <memory>
#include "fractal_creator.h"
#include <QGraphicsScene>
#include <QGraphicsView>

namespace fractal_project {

class FractalViewer : QGraphicsScene
{
  Q_OBJECT
  
public: 
    FractalViewer();
    FractalViewer(const int width , const int height, const int max_iterations, 
        std::string filename = "defaultFractal.bmp", QObject *parent = 0);
    ~FractalViewer();

    void showFractal();

private:
    std::string m_filename;
    std::unique_ptr< QGraphicsView > m_pView;
    std::unique_ptr< FractalCreator > m_pFractalCreator;

    //methods
    void createFractal();
};

};

#endif //!FRACTAL_VIEWER_H