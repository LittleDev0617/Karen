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
    virtual void RLE8_Compress();

public:
    virtual void getPixel(Vec2& pos, RGB& out);

    Bitmap(std::string filePath)
    {
        try
        {
            loadFromFile(filePath);
        }
        catch (const char* msg)
        {
            std::cerr << msg << '\n';
        }
    }
};