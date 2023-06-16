#pragma once
#include <fstream>
#include <iostream>
#include "../Utils.h"
#include "./Sprite.h"

class Bitmap : public Sprite
{
private:
    int padding, bits;

protected:
    virtual void loadFromFile(std::string path);

public:
    virtual int getPixel(Vec2& pos);
    Bitmap(std::string filePath)
    {
        loadFromFile(filePath);
    }

    ~Bitmap()
    {
        if(data) delete data;
    }
};