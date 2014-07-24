#ifndef SHAPE_DATA_H
#define SHAPE_DATA_H

#include <vector>

typedef unsigned char PixelColour;
typedef std::vector<PixelColour> Colour;
typedef PixelColour* Pixel;

enum RGB {
	RGB_R,
	RGB_G,
	RGB_B,
	RGB_FIRST = RGB_R,
	RGB_LAST = RGB_B
};

#endif