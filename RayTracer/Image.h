#ifndef IMAGE_H
#define IMAGE_H

#include "RaytracerShapeHeader.h"

typedef char* Pixel;

class Image {
public:
	Image(int imageWidth, int imageHeight);

	~Image();

	const char *getImage() const;

	char getPixelValue(int row, int column, RGB rgb) const;
	void setPixelValue(int row, int column, RGB rgb, char value);

	Pixel getPixel(int row, int column) const;

private:
	int m_imageWidth;
	int m_imageHeight;
	char *m_imagePixels;
};

#endif //IMAGE_H