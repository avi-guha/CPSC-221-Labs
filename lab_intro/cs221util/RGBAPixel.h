#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H

namespace cs221util {

    class RGBAPixel {
    public:
        // RGBA pixel described by unsigned char r, g, b and double a
        unsigned char r, g, b;
        double a;

        // Default constructor (white pixel, alpha = 1.0)
        RGBAPixel();

        // Constructor to set RGB, full opacity
        RGBAPixel(unsigned char r, unsigned char g, unsigned char b);

        // Constructor to set RGB and opacity (alpha)
        RGBAPixel(unsigned char r, unsigned char g, unsigned char b, double alpha);
    };

}

#endif
