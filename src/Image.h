//
// Created by cardo on 7/5/2019.
//

#ifndef SRC_IMAGE_H
#define SRC_IMAGE_H

#include "Pixel.h"
#include <iostream>

struct Header
{
    char idLength = 0;
    char colorMapType = 0;
    char dataTypeCode = 2;
    short colorMapOrigin = 0;
    short colorMapLength = 0;
    char colorMapDepth = 0;
    short xOrigin = 0;
    short yOrigin = 0;
    short width = 0;
    short height = 0;
    char bitsPerPixel = 0;
    char imageDescriptor = 0;

    bool operator==(Header &obj) {
        return (
                idLength == obj.idLength &&
                colorMapType == obj.colorMapType &&
                dataTypeCode == obj.dataTypeCode &&
                colorMapOrigin == obj.colorMapOrigin &&
                colorMapLength == obj.colorMapLength &&
                colorMapDepth == obj.colorMapDepth &&
                xOrigin == obj.xOrigin &&
                yOrigin == obj.yOrigin &&
                width == obj.width &&
                height == obj.height &&
                bitsPerPixel == obj.bitsPerPixel &&
                imageDescriptor == obj.imageDescriptor
                );
    }
};

class Image {
private:
    Header header;
    Pixel *colorMap;

public:
    Image();
    Image(Header header, Pixel color_map[]);
    Image(Header header, Pixel color);
    Image(Image  &blue, Image  &green, Image  &red);
    Image(Image quadrants[4]);
    Image(Image const &obj);
    Image& operator=(Image const &obj);
    ~Image();

    int getSize();
    Header getHeader();
    Pixel *getColorMap();
    Pixel getXY(short x, short y);

    void setHeader(Header header);
    void setColorMap(Pixel *colorMap);
    void setXY(Pixel color, short x, short y);

    Image operator+(Image &obj);
    Image operator-(Image &obj);
    Image operator*(Image &obj);
    bool operator==(Image &obj);

    Image screen(Image &obj);
    Image overlay(Image &obj);
    Image multiplyValues(float blue, float green, float red);
    Image getBlue();
    Image getGreen();
    Image getRed();
    Image flip();
};



#endif //SRC_IMAGE_H
