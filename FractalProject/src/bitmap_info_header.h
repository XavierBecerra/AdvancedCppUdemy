#ifndef FRACTAL_BITMAPINFOHEADER_H
#define FRACTAL_BITMAPINFOHEADER_H

#include <cstdint>


namespace fractal_project {

#pragma pack(push,2) // Align struct in 2 line boundaries, no padding.

struct Bitmapinfoheader_t {//DIB header
  std::int32_t  biSize{40}; // size in bytes!: if you count size of bytes on this struct: int32 is 4 bytes and appears 9 times, int16 is 2 bytes and appears 2 times
  std::int32_t  biWidth;
  std::int32_t  biHeight;
  std::int16_t  biPlanes{1};// one color plane
  std::int16_t  biBitPerPixel{24};// one byte per color, so RGB image is 3 olors 8*3=24
  std::int32_t  biCompression{0};
  std::int32_t  biSizeImage{0};
  std::int32_t  biXPelsPerMeter{2400};
  std::int32_t  biYPelsPerMeter{2400};
  std::int32_t  biClrUsed{0};
  std::int32_t  biClrImportant{0};
};
#pragma pack(pop)

};

/* //https://en.wikipedia.org/wiki/BMP_file_format
DIB Header
Eh 	4 	28 00 00 00 	40 bytes 	Number of bytes in the DIB header (from this point)
12h 	4 	02 00 00 00 	2 pixels (left to right order) 	Width of the bitmap in pixels
16h 	4 	02 00 00 00 	2 pixels (bottom to top order) 	Height of the bitmap in pixels. Positive for bottom to top pixel order.
1Ah 	2 	01 00 	1 plane 	Number of color planes being used
1Ch 	2 	18 00 	24 bits 	Number of bits per pixel
1Eh 	4 	00 00 00 00 	0 	BI_RGB, no pixel array compression used
22h 	4 	10 00 00 00 	16 bytes 	Size of the raw bitmap data (including padding)
26h 	4 	13 0B 00 00 	2835 pixels/metre horizontal 	Print resolution of the image,
72 DPI × 39.3701 inches per metre yields 2834.6472
2Ah 	4 	13 0B 00 00 	2835 pixels/metre vertical
2Eh 	4 	00 00 00 00 	0 colors 	Number of colors in the palette
32h 	4 	00 00 00 00 	0 important colors 	0 means all colors are important

*/
#endif // !FRACTAL_BITMAPINFOHEADER_H
