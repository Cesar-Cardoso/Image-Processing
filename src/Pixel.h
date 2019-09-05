//
// Created by cardo on 7/5/2019.
//

#ifndef SRC_PIXEL_H
#define SRC_PIXEL_H

#include <algorithm>

using namespace std;


class Pixel {
private:
    unsigned char blue, green, red;
    const unsigned char MINIMUM_VALUE = 0;
    const unsigned char MAXIMUM_VALUE = 255;

    unsigned char setInRange(short value);
    float normalize(unsigned char a);
    unsigned char addValues(unsigned char a, unsigned char b);
    unsigned char substractValues(unsigned char a, unsigned char b);
    unsigned char multiplyValues(unsigned char a, unsigned char b);
    unsigned char screenValues(unsigned char a, unsigned char b);
    unsigned char overlayValues(unsigned char a, unsigned char b);

public:
    Pixel();
    Pixel(unsigned char blue, unsigned char green, unsigned char red);
    Pixel(const Pixel &obj);
    Pixel& operator=(Pixel const &obj);
    ~Pixel();

    unsigned char getBlue();
    unsigned char getGreen();
    unsigned char getRed();

    void setBlue(unsigned char value);
    void setGreen(unsigned char value);
    void setRed(unsigned char value);

    Pixel operator+(Pixel &obj);
    Pixel operator-(Pixel &obj);
    Pixel operator*(Pixel &obj);
    bool operator==(Pixel &obj);

    Pixel screen(Pixel &obj);
    Pixel overlay(Pixel &obj);
    void multiplyValue(float blue, float green, float red);
};


#endif //SRC_PIXEL_H
