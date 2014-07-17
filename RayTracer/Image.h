#ifndef IMAGE_H
#define IMAGE_H

enum RGB {
	RGB_R,
	RGB_G,
	RGB_B,
	RGB_FIRST = RGB_R,
	RGB_LAST = RGB_B
};

class Image {
public:
	Image(int imageWidth, int imageHeight);

	~Image();

	const char *getImage() const;

	char getPixel(int row, int column, RGB rgb) const;
	void setPixel(int row, int column, RGB rgb, char value);

private:
	int m_imageWidth;
	int m_imageHeight;
	char *m_imagePixels;
};

#endif //IMAGE_H