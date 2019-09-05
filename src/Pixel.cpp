//
// Created by cardo on 7/5/2019.
//

#include "Pixel.h"

unsigned char Pixel::setInRange(short value) {
    if (value < (short) MINIMUM_VALUE) {
        return MINIMUM_VALUE;
    }
    if (value > (short) MAXIMUM_VALUE) {
        return MAXIMUM_VALUE;
    }
    return (char) value;
}

float Pixel::normalize(unsigned char a) {
    return ((float)(a)/(float)(MAXIMUM_VALUE));
}

unsigned char Pixel::addValues(unsigned char a, unsigned char b) {
    return setInRange((short)a + (short)b);
}

unsigned char Pixel::substractValues(unsigned char a, unsigned char b) {
    return setInRange((short)a - (short)b);
}

unsigned char Pixel::multiplyValues(unsigned char a, unsigned char b) {
    return (unsigned char)((normalize(a) * b) + 0.5f);
}

unsigned char Pixel::screenValues(unsigned char a, unsigned char b) {
    return (unsigned char)((MAXIMUM_VALUE - (1 - normalize(a)) * (MAXIMUM_VALUE - b)) + 0.5f);
}

unsigned char Pixel::overlayValues(unsigned char a, unsigned char b) {
    float normalized_b = normalize(b);
    if (normalized_b > 0.5f) {
        return (unsigned char)((1 - (2 * (1 - normalize(a)) * (1 - normalized_b))) * MAXIMUM_VALUE + 0.5f);
    }
    return (unsigned char)(2 * a * normalized_b + 0.5f);
}

Pixel::Pixel() {
    blue = MINIMUM_VALUE;
    green = MINIMUM_VALUE;
    red = MINIMUM_VALUE;
}

Pixel::Pixel(unsigned char blue, unsigned char green, unsigned char red) {
    this->blue = blue;
    this->green = green;
    this->red = red;
}

Pixel::Pixel(const Pixel &obj) {
    this->blue = obj.blue;
    this->green = obj.green;
    this->red = obj.red;

}

Pixel& Pixel::operator=(Pixel const &obj) {
    if (this == &obj) {
        return *this;
    }
    this->blue = obj.blue;
    this->green = obj.green;
    this->red = obj.red;
    return *this;
}

Pixel::~Pixel() {}

unsigned char Pixel::getBlue() {
    return blue;
}

unsigned char Pixel::getGreen() {
    return green;
}

unsigned char Pixel::getRed() {
    return red;
}

void Pixel::setBlue(unsigned char value) {
    blue = value;
}

void Pixel::setGreen(unsigned char value) {
    green = value;
}

void Pixel::setRed(unsigned char value) {
    red = value;
}

Pixel Pixel::operator+(Pixel &obj) {
    Pixel result;
    result.setBlue(addValues(blue, obj.blue));
    result.setGreen(addValues(green, obj.green));
    result.setRed(addValues(red, obj.red));
    return result;
}


Pixel Pixel::operator-(Pixel &obj) {
    Pixel result;
    result.setBlue(substractValues(blue, obj.blue));
    result.setGreen(substractValues(green, obj.green));
    result.setRed(substractValues(red, obj.red));
    return result;
}

Pixel Pixel::operator*(Pixel &obj) {
    Pixel result;
    result.setBlue(multiplyValues(blue, obj.blue));
    result.setGreen(multiplyValues(green, obj.green));
    result.setRed(multiplyValues(red, obj.red));
    return result;
}

bool Pixel::operator==(Pixel &obj) {
    return (
            blue == obj.blue &&
            green == obj.green &&
            red == obj.red
            );
}

Pixel Pixel::screen(Pixel &obj) {
    Pixel result;
    result.setBlue(screenValues(blue, obj.blue));
    result.setGreen(screenValues(green, obj.green));
    result.setRed(screenValues(red, obj.red));
    return result;
}

Pixel Pixel::overlay(Pixel &obj) {
    Pixel result;
    result.setBlue(overlayValues(blue, obj.blue));
    result.setGreen(overlayValues(green, obj.green));
    result.setRed(overlayValues(red, obj.red));
    return result;
}

void Pixel::multiplyValue(float blue, float green, float red) {
    this->blue = setInRange(this->blue * blue);
    this->green = setInRange(this->green * green);
    this->red = setInRange(this->red * red);
}
