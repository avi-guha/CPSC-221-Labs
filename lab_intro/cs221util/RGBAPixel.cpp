#include <iostream>
#include "RGBAPixel.h"

namespace cs221util{
    RGBAPixel::RGBAPixel() {
        this -> r = 255;
        this -> g = 255;
        this -> b = 255;
        this -> a = 1.0;
    }
    
    RGBAPixel::RGBAPixel(unsigned char r, unsigned char g, unsigned char b){
        this -> r = r;
        this -> g = g; 
        this -> b = b; 
        this -> a = 1; 
    }

    RGBAPixel::RGBAPixel(unsigned char r, unsigned char g, unsigned char b, double alpha){
        this -> r = r;
        this -> g = g; 
        this -> b = b; 
        this -> a = alpha; 
    }


}