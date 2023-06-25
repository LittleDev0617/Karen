#pragma once
#include <string>
#include <iostream>
#include "../Resource.h"
#include "../Utils.h"


class Sprite : public Resource
{
protected:
	bool _isCompressed = 0;
    unsigned char* rawData;
	Pixel* compressedData;
	unsigned int width, height, size;
	std::string sourcePath;

	virtual void loadFromFile(std::string path) { };
	virtual void compress() {};

public:
	~Sprite()
	{
		if(rawData) delete rawData;
		if(compressedData) delete compressedData;
	}

	virtual void getPixel(Vec2& pos, RGB& out) {  };
	unsigned int getWidth() { return width; };
	unsigned int getHeight() { return height; };
	unsigned char* geRawData() { return rawData; };
	Pixel* getCompressedData() { return compressedData; };
	unsigned int getSize() { return size; };
	bool isCompressed() { return _isCompressed; };
	void setWidth(unsigned int width) { this->width = width; };
	void setHeight(unsigned int height) { this->height = height; };
};
