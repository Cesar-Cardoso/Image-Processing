//
// Created by cardo on 7/5/2019.
//

#include "Image.h"
#include <fstream>

Image::Image() {
    this->colorMap = nullptr;
}

Image::Image(Header header, Pixel *colorMap) {
    this->header = header;
    this->colorMap = colorMap;
}

Image::Image(Image  &blue, Image  &green, Image  &red) {
    this->header = blue.getHeader();
    int size = getSize();
    this->colorMap = new Pixel[size];
    Pixel *blueMap = blue.getColorMap();
    Pixel *greenMap = green.getColorMap();
    Pixel *redMap = red.getColorMap();
    Pixel temp;

    for (int index = 0; index < size; index++) {
        temp.setBlue(blueMap[index].getBlue());
        temp.setGreen(greenMap[index].getBlue());
        temp.setRed(redMap[index].getBlue());
        colorMap[index] = temp;
    }
}

Image::Image(Image quadrants[4]) {
    header = quadrants[0].header;
    header.width *= 2;
    header.height *= 2;
    short width = header.width, height = header.height;
    colorMap = new Pixel[width * height];
    for (short i = 0; i < width; i++) {
        for (short j = 0; j < height; j++) {
            short index;
            if (i < width / 2) {
                if (j < height / 2) {
                    index = 0;
                } else {
                    index = 1;
                }
            } else {
                if (j < height / 2) {
                    index = 2;
                } else {
                    index = 3;
                }
            }
            Pixel temp = quadrants[index].getXY(i % (width/2), j % (height/2));
            setXY(temp, i, j);
        }
    }
}

Image::Image(Header header, Pixel color) {
    this->header = header;
    int size = getSize();
    colorMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        colorMap[index] = color;
    }
}

Image::Image(Image const &obj) {
    setHeader(obj.header);
    int size = getSize();
    colorMap = new Pixel[size];
    for (int index = 0; index < size; index ++) {
        colorMap[index] = obj.colorMap[index];
    }
}

Image &Image::operator=(Image const &obj) {
    if (this == &obj) {
        return *this;
    }
    setHeader(obj.header);
    int size = getSize();
    colorMap = new Pixel[size];
    for (int index = 0; index < size; index ++) {
        colorMap[index] = obj.colorMap[index];
    }
    return *this;
}

Image::~Image() {
    delete[] colorMap;
}

int Image::getSize() {
    return header.width * header.height;
}

Header Image::getHeader() {
    return header;
}

Pixel *Image::getColorMap() {
    return colorMap;
}

Pixel Image::getXY(short x, short y) {
    return (colorMap[header.width*y + x]);
}

void Image::setHeader(Header header) {
    this->header = header;
}

void Image::setColorMap(Pixel *colorMap) {
    this->colorMap = colorMap;
}

void Image::setXY(Pixel color, short x, short y) {
    colorMap[header.width*y + x] = color;
}

Image Image::operator+(Image &obj) {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *objMap = obj.getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        resultMap[index] = (thisMap[index] + objMap[index]);
    }
    return Image(header, resultMap);
}


Image Image::operator-(Image &obj) {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *objMap = obj.getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        resultMap[index] = (thisMap[index] - objMap[index]);
    }
    return Image(header, resultMap);
}

Image Image::operator*(Image &obj) {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *objMap = obj.getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        resultMap[index] = (thisMap[index] * objMap[index]);
    }
    return Image(header, resultMap);
}

bool Image::operator==(Image &obj) {
    if (!(header == obj.header)) {
        return false;
    }
    int size = getSize();
    for (int index = 0; index < size; index++) {
        if (!(colorMap[index] == obj.colorMap[index])) {
            return false;
        }
    }
    return true;
}

Image Image::screen(Image &obj) {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *objMap = obj.getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        resultMap[index] = thisMap[index].screen(objMap[index]);
    }
    return Image(header, resultMap);
}

Image Image::overlay(Image &obj) {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *objMap = obj.getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        resultMap[index] = thisMap[index].overlay(objMap[index]);
    }
    return Image(header, resultMap);
}

Image Image::multiplyValues(float blue, float green, float red) {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        Pixel temp = thisMap[index];
        temp.multiplyValue(blue, green, red);
        resultMap[index] = temp;
    }
    return Image(header, resultMap);
}

Image Image::getBlue() {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        unsigned char value = thisMap[index].getBlue();
        resultMap[index] = Pixel(value, value, value);
    }
    return Image(header, resultMap);
}

Image Image::getGreen() {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        unsigned char value = thisMap[index].getGreen();
        resultMap[index] = Pixel(value, value, value);
    }
    return Image(header, resultMap);
}

Image Image::getRed() {
    int size = getSize();
    Pixel *thisMap = getColorMap();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        unsigned char value = thisMap[index].getRed();
        resultMap[index] = Pixel(value, value, value);
    }
    return Image(header, resultMap);
}

Image Image::flip() {
    int size = getSize();
    Pixel *resultMap = new Pixel[size];
    for (int index = 0; index < size; index++) {
        resultMap[index] = colorMap[size - index - 1];
    }
    return Image(header, resultMap);
}

