#include "Bitmap.h"

void Bitmap::loadFromFile(std::string path)
{
    std::ifstream bitmapFile;

    if(ext(path) != "bmp")
        throw "file is not bmp.";

    bitmapFile.open(path, std::ios_base::binary);

    if(!bitmapFile.is_open()) throw "file is not existed.";
    if(!(bitmapFile.get() == 'B' && bitmapFile.get() == 'M')) throw "file is not bmp.";

    readBitmapInfo();
    RLE8_Compress();
    // bits = 
}

void Bitmap::readBitmapInfo(std::ifstream bitmapFile)
{
    // go to header.data_offset
    bitmapFile.seekg(10);
    unsigned int dataOffset = 0;
    bitmapFile.read((char*)&dataOffset, sizeof(4));

    bitmapFile.seekg(4, std::ios_base::cur);
    bitmapFile.read((char*)&width, sizeof(4));
    bitmapFile.read((char*)&height, sizeof(4));

    bitmapFile.seekg(2, std::ios_base::cur);

    bitmapFile.read((char*)&bits, sizeof(2));

    if (bits == 24)
    {
        padding = width % 4;
        size = (width * 3 + padding) * height;
    }
    else if (bits == 4)
    {
        padding = 8 - (width % 8); // (4 bits)
        size = (width + padding) * height;
    }

    //size = width * height;
    //if(size >= 1024 * 100) throw "Too big";

    bitmapFile.seekg(dataOffset);

    rawData = new unsigned char[size];
    bitmapFile.read((char*)rawData, size);
}

void Bitmap::RLE8_Compress()
{
    if(!rawData) return;

    Vec2 pos = { 0, 0 };
    Pixel* buf = new Pixel[1024*1024];
    RGB recent, color = { 0,0,0 };
    int cnt = 0;
    int j = 0, x;

    for (int y = 0; y < getHeight(); y++, pos.y++)
    {
        x = pos.x = 0;
        getPixel(pos, recent);
        for (; x < getWidth(); x++, pos.x++)
        {
            getPixel(pos, color);

            if(recent == color)
                cnt++;
            else
            {
            store:
                buf[j].len = cnt;
                buf[j++].rgb = recent;
                
                recent = color;
                cnt = 1;
            }
            
            if(cnt == 255) goto store;
        }
        
        buf[j].len = cnt;
        buf[j++].rgb = recent;
        
        recent = color;
        cnt = 0;
    }

    compressedData = new Pixel[j];
    std::memcpy(compressedData, buf, j * sizeof(Pixel));
    delete buf;
    _isCompressed = true;
}

void Bitmap::getPixel(Vec2& pos, RGB& out)
{
    RGB* p = reinterpret_cast<RGB*>(&rawData[(height - pos.y - 1) * (width * 3 + padding) + pos.x * 3]);
    out.R = p->B;
    out.G = p->G;
    out.B = p->R;
}