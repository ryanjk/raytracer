#ifndef IMAGE_H
#define IMAGE_H

#include "RaytracerShapeHeader.h"

class Image {
public:
	Image(int imageWidth, int imageHeight);

	const PixelColour *getImage() const;

	Pixel getPixel(int row, int column) const;

private:
	int m_imageWidth;
	int m_imageHeight;
	PixelColour *m_imagePixels;
	void setPixelValue(int row, int column, RGB rgb, PixelColour value);
};

#endif //IMAGE_H