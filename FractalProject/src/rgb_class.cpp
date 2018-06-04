#include "rgb_class.h"

using namespace std;

namespace fractal_project {

RGB_t::RGB_t() {};

RGB_t::RGB_t(const double r, const double g, const double b) :
    red(r),
    green(g),
    blue(b) {
};

RGB_t operator- (const RGB_t & first, const RGB_t & second) {
    auto result = RGB_t(first.red - second.red, first.green - second.green, first.blue - second.blue);
    return result;
};

RGB_t operator+ (const RGB_t & first, const RGB_t & second) {
    auto result = RGB_t(first.red + second.red, first.green + second.green, first.blue + second.blue);
    return result;
};

RGB_t operator* (const RGB_t & first, const double & val) {
    auto result = RGB_t(first.red *val, first.green *val, first.blue *val);
    return result;
};

RGB_t operator* ( const double & val, const RGB_t & first) {
    auto result = RGB_t(first.red *val, first.green *val, first.blue *val);
    return result;
};

};