#ifndef FRACTAL_BITMAPCLASS_H
#define FRACTAL_BITMAPCLASS_H

#include <cstdint>
#include <memory>// to use smart pointers
#include "bitmap_header.h"
#include "bitmap_info_header.h"

namespace fractal_project {

class Bitmap
{
public:
    Bitmap();
    Bitmap(const int width, const int height);

    bool writeToFile(const std::string & filename);
    void setPixel(const int posX, const int posY, const uint8_t red, const uint8_t green, const uint8_t blue);

    //getters
    int getWidth() const {
        return m_width;
    };
    int getHeight() const {
        return m_height;
    };

    virtual ~Bitmap();
    
private:
//Variables
    int m_width{0};
    int m_height{0};
    std::unique_ptr<std::uint8_t[]> m_pPixels;
//Methods
    void defineHeaders(Bitmapheader_t & fileHeader, Bitmapinfoheader_t & infoHeader);
};

};

#endif // !FRACTAL_BITMAPCLASS_H