#include "Image.h"

Image::Image (int imageWidth, int imageHeight) : m_imageWidth(imageWidth), m_imageHeight(imageHeight)
{
	m_imagePixels = new PixelColour[m_imageWidth * m_imageHeight * 3];

	// Initialize pixels to black
	for (int row = 0; row < m_imageHeight; ++row)
	{
		for (int column = 0; column < m_imageWidth; ++column)
		{
			PixelColour value = 0;
			setPixelValue(row, column, RGB_R, value);
			setPixelValue(row, column, RGB_G, value);
			setPixelValue(row, column, RGB_B, value);
		}
	}
}

const PixelColour* Image::getImage() const
{
	return m_imagePixels;
}

void Image::setPixelValue(int row, int column, RGB rgb, PixelColour value)
{
	m_imagePixels[row * m_imageWidth * 3 + column * 3 + rgb] = value;
}

Pixel Image::getPixel(int row, int column) const
{
	return &m_imagePixels[row * m_imageWidth * 3 + column * 3];
}