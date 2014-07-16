class Image {
private:
	int m_imageWidth;
	int m_imageHeight;
	char* imagePixels;
public:
	Image(int imageWidth, int imageHeight);
	char getPixel(int i, int j, int k) const;
	void setPixel(int i, int j, int k, char value);
};