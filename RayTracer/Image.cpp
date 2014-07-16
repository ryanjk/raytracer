#include "Image.h"

Image::Image (int imageWidth, int imageHeight) : m_imageWidth(imageWidth), m_imageHeight(imageHeight)
{
	imagePixels = new char[m_imageWidth * m_imageHeight * 3];
}

char Image::getPixel(int i, int j, int k) const
{
	return imagePixels[i * m_imageHeight + j * m_imageWidth + k];
};

void Image::setPixel(int i, int j, int k, char value)
{
	imagePixels[i * m_imageWidth * 3 + j * 3 + k] = value;
}