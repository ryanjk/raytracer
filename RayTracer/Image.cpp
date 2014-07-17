#include "Image.h"

Image::Image (int imageWidth, int imageHeight) : m_imageWidth(imageWidth), m_imageHeight(imageHeight)
{
	m_imagePixels = new char[m_imageWidth * m_imageHeight * 3];

	// Initialize pixels to black
	for (int row = 0; row < m_imageHeight; ++row)
	{
		for (int column = 0; column < m_imageWidth; ++column)
		{
			char value = 0;
			setPixel(row, column, RGB_R, value);
			setPixel(row, column, RGB_G, value);
			setPixel(row, column, RGB_B, value);
		}
	}
}

Image::~Image()
{
	delete m_imagePixels;
}

char Image::getPixel(int row, int column, RGB rgb) const
{
	return m_imagePixels[row * m_imageHeight + column * m_imageWidth + rgb];
};

const char* Image::getImage() const
{
	return m_imagePixels;
}

void Image::setPixel(int row, int column, RGB rgb, char value)
{
	m_imagePixels[row * m_imageWidth * 3 + column * 3 + rgb] = value;
}