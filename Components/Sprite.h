#pragma once
#include <string>
#include "../Resource.h"
#include "../Utils.h"


class Sprite : public Resource
{
protected:
    unsigned char* data;
	unsigned int width, height, size;
	std::string sourcePath;

	virtual void loadFromFile(std::string path) { };

public:
	virtual int getPixel(Vec2& pos) { return 0;  };
	unsigned int getWidth() { return width; };
	unsigned int getHeight() { return height; };
	unsigned char* getData() { return data; };
	unsigned int getSize() { return size; };
	void setWidth(unsigned int width) { this->width = width; };
	void setHeight(unsigned int height) { this->height = height; };
};
