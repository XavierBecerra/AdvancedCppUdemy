#include "bitmap_class.h"
#include <fstream>

using namespace std;

namespace fractal_project {

Bitmap::Bitmap() {

};

Bitmap::Bitmap(const int width, const int height) :
    m_width(width),
    m_height(height),
    m_pPixels(new uint8_t[ width*height*3 ]{0} /*initialize to 0*/) {

};

bool Bitmap::writeToFile(const std::string & filename) {
    bool success{true};// succesfull until proben otherwise
    
    Bitmapheader_t fileHeader;
    Bitmapinfoheader_t infoHeader;

    defineHeaders(fileHeader, infoHeader);

    std::ofstream outFile;
    outFile.open(filename, ios::out | ios::binary);

    if(outFile.is_open()){

        outFile.write( (char*)&fileHeader, sizeof(Bitmapheader_t) );
        outFile.write( (char*)&infoHeader, sizeof(Bitmapinfoheader_t) );
        outFile.write( (char*)m_pPixels.get() , m_width * m_height * 3 );

        outFile.close();
    }
    else {
        success=false;
    }

    return success;// still not writing to any file
};

void Bitmap::defineHeaders(Bitmapheader_t & fileHeader, Bitmapinfoheader_t & infoHeader) {

    fileHeader.filesize     = sizeof(Bitmapheader_t) + sizeof(Bitmapinfoheader_t) + (m_width * m_height * 3);//Total file size
    fileHeader.dataoffset   = sizeof(Bitmapheader_t) + sizeof(Bitmapinfoheader_t);//Where bitmap info starts

    infoHeader.biWidth  = m_width;
    infoHeader.biHeight = m_height;
    //infoHeader.biSizeImage = m_width * m_height * 3;

};

void Bitmap::setPixel(const int posX, const int posY, const uint8_t red, const uint8_t green, const uint8_t blue){
    uint8_t *pPixel = m_pPixels.get();//points to begining of image

    pPixel += (posY*3 * m_width) + posX*3 ;// move along y (columns) and then x (widht). y*widht is so that every column we move we move through its whole widht.

    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
    //inverted red green blue because a bitmap is a little endian format
    //for example: 
    //0xFF3322 -> FF is red, 33 is green, 22 is blue. Blue is in the least signinificant bits, red in the most signinficant
    //when this gets into meomnry in bits  010101000111101001
    //              lowes memory adress--->                  <---biggest memory adress
    //  this is where least significant--->                  <---this is most significant bits are is stored
    return;
};

Bitmap::~Bitmap() {
    
};

};