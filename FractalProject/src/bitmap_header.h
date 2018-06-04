#ifndef FRACTAL_BITMAPHEADER_H
#define FRACTAL_BITMAPHEADER_H

#include <cstdint>

namespace fractal_project {
//https://en.wikipedia.org/wiki/BMP_file_format

#pragma pack(push,2) // Align struct in 2 line boundaries, no padding.

struct Bitmapheader_t {
    char fileSignature[2]{'B','M'};// {0x4D42};// 'BM'
    std::int32_t filesize;//We need a 32 bit !!
    std::int32_t reserved{0};
    std::int32_t dataoffset;
};
#pragma pack(pop)
};

#endif // !FRACTAL_BITMAPHEADER_H