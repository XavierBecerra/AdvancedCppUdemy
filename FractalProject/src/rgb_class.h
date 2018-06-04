#ifndef FRACTAL_RGB_H
#define FRACTAL_RGB_H

#include <cstdint>

namespace fractal_project {

struct RGB_t {
    RGB_t();
    RGB_t(const double r, const double g, const double b);

    double red{0};
    double green{0};
    double blue{0};
};

RGB_t operator- (const RGB_t & first, const RGB_t & second);
RGB_t operator+ (const RGB_t & first, const RGB_t & second);
RGB_t operator* (const RGB_t & first, const double & val);
RGB_t operator* ( const double & val, const RGB_t & first);

};
#endif // ! FRACTAL_RGB_H