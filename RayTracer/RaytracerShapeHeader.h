#ifndef SHAPE_DATA_H
#define SHAPE_DATA_H

#include <vector>
#include "RaytracerMath.h"

typedef unsigned char PixelColour;
typedef gmtl::Vec<PixelColour, 3U> Colour;
typedef PixelColour* Pixel;

enum RGB {
	RGB_R,
	RGB_G,
	RGB_B,
	RGB_FIRST = RGB_R,
	RGB_LAST = RGB_B
};

#endif