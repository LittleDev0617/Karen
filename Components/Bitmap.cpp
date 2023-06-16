#include "Bitmap.h"

void Bitmap::loadFromFile(std::string path)
{
    std::fstream bitmapFile;

    if(ext(path) != "bmp")
        throw "file is not bmp.";

    bitmapFile.open(path);

    if(!bitmapFile.is_open()) throw "file is not existed.";
    if(!(bitmapFile.get() == 'B' && bitmapFile.get() == 'M')) throw "file is not bmp.";

    // go to header.data_offset
    bitmapFile.seekg(10);
    unsigned int dataOffset = 0;
    bitmapFile.read((char*)&dataOffset, sizeof(4));

    bitmapFile.seekg(4, std::ios_base::cur);
    bitmapFile.read((char*)&width, sizeof(4));
    bitmapFile.read((char*)&height, sizeof(4));

    // 4bit * 8, 4 byte padding
    padding = 8 - (width % 8); // (4 bits)

    size = (width + padding) * height;
    bitmapFile.seekg(dataOffset);

    data = (unsigned char*) new unsigned char[size];
    bitmapFile.read((char*)data, size);

}

int Bitmap::getPixel(Vec2& pos)
{
    unsigned char d = data[(height - pos.y - 1) * (padding + width) / 2 + pos.x / 2];
    return (pos.x % 2 ? d & 0xF : d >> 4);
}