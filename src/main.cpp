#include <iostream>
#include <fstream>
#include "Pixel.h"
#include "Image.h"

using namespace std;

void loadImage(string name, Image &image);
void saveImage(string name, Image &image);

int main() {
    ///Loading Input Images

    int passed = 0;

    Image car, circles, layer_blue, layer_green, layer_red, layer1, layer2,
    pattern1, pattern2, text, text2;

    loadImage("./input/car.tga", car);
    loadImage("./input/circles.tga", circles);
    loadImage("./input/layer_blue.tga", layer_blue);
    loadImage("./input/layer_green.tga", layer_green);
    loadImage("./input/layer_red.tga", layer_red);
    loadImage("./input/layer1.tga", layer1);
    loadImage("./input/layer2.tga", layer2);
    loadImage("./input/pattern1.tga", pattern1);
    loadImage("./input/pattern2.tga", pattern2);
    loadImage("./input/text.tga", text);
    loadImage("./input/text2.tga", text2);

    ///Loading examples Images

    Image EXAMPLE_extracredit, EXAMPLE_part1, EXAMPLE_part2, EXAMPLE_part3,
    EXAMPLE_part4, EXAMPLE_part5, EXAMPLE_part6, EXAMPLE_part7, EXAMPLE_part8_b,
    EXAMPLE_part8_g, EXAMPLE_part8_r, EXAMPLE_part9, EXAMPLE_part10;

    loadImage("./examples/EXAMPLE_extracredit.tga", EXAMPLE_extracredit);
    loadImage("./examples/EXAMPLE_part1.tga", EXAMPLE_part1);
    loadImage("./examples/EXAMPLE_part2.tga", EXAMPLE_part2);
    loadImage("./examples/EXAMPLE_part3.tga", EXAMPLE_part3);
    loadImage("./examples/EXAMPLE_part4.tga", EXAMPLE_part4);
    loadImage("./examples/EXAMPLE_part5.tga", EXAMPLE_part5);
    loadImage("./examples/EXAMPLE_part6.tga", EXAMPLE_part6);
    loadImage("./examples/EXAMPLE_part7.tga", EXAMPLE_part7);
    loadImage("./examples/EXAMPLE_part8_b.tga", EXAMPLE_part8_b);
    loadImage("./examples/EXAMPLE_part8_g.tga", EXAMPLE_part8_g);
    loadImage("./examples/EXAMPLE_part8_r.tga", EXAMPLE_part8_r);
    loadImage("./examples/EXAMPLE_part9.tga", EXAMPLE_part9);
    loadImage("./examples/EXAMPLE_part10.tga", EXAMPLE_part10);

    ///Test 1
    Image test_1_check, test_1_write = layer1 * pattern1;
    saveImage("./output/part1.tga", test_1_write);
    loadImage("./output/part1.tga", test_1_check);
    if (test_1_check == EXAMPLE_part1) {
        cout << "Test 1 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 1 Failed!" << endl;
    }

    ///Test 2
    Image test_2_check, test_2_write = car - layer2;
    saveImage("./output/part2.tga", test_2_write);
    loadImage("./output/part2.tga", test_2_check);
    if (test_2_check == EXAMPLE_part2) {
        cout << "Test 2 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 2 Failed!" << endl;
    }

    ///Test 3
    Image test_3_check, test_3_write, test_3_temp = layer1 * pattern2;
    test_3_write = text.screen(test_3_temp);
    saveImage("./output/part3.tga", test_3_write);
    loadImage("./output/part3.tga", test_3_check);
    if (test_3_check == EXAMPLE_part3) {
        cout << "Test 3 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 3 Failed!" << endl;
    }

    ///Test 4
    Image test_4_check, test_4_write, test_4_temp = layer2 * circles;
    test_4_write = test_4_temp - pattern2;
    saveImage("./output/part4.tga", test_4_write);
    loadImage("./output/part4.tga", test_4_check);
    if (test_4_check == EXAMPLE_part4) {
        cout << "Test 4 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 4 Failed!" << endl;
    }

    ///Test 5
    Image test_5_check, test_5_write = layer1.overlay(pattern1);
    saveImage("./output/part5.tga", test_5_write);
    loadImage("./output/part5.tga", test_5_check);
    if (test_5_check == EXAMPLE_part5) {
        cout << "Test 5 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 5 Failed!" << endl;
    }

    ///Test 6
    Pixel tempPixel = Pixel(0, 200, 0);
    Header tempHeader = car.getHeader();
    Image tempImage = Image(tempHeader, tempPixel);
    Image test_6_check, test_6_write = car + tempImage;
    saveImage("./output/part6.tga", test_6_write);
    loadImage("./output/part6.tga", test_6_check);
    if (test_6_check == EXAMPLE_part6) {
        cout << "Test 6 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 6 Failed!" << endl;
    }

    ///Test 7

    Image test_7_check, test_7_write = car.multiplyValues(0, 1, 4);
    saveImage("./output/part7.tga", test_7_write);
    loadImage("./output/part7.tga", test_7_check);
    if (test_7_check == EXAMPLE_part7) {
        cout << "Test 7 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 7 Failed!" << endl;
    }

    ///Test 8
    Image test_8_b_check, test_8_b_write = car.getBlue();
    saveImage("./output/part8_b.tga", test_8_b_write);
    loadImage("./output/part8_b.tga", test_8_b_check);

    Image test_8_g_check, test_8_g_write = car.getGreen();
    saveImage("./output/part8_g.tga", test_8_g_write);
    loadImage("./output/part8_g.tga", test_8_g_check);

    Image test_8_r_check, test_8_r_write = car.getRed();
    saveImage("./output/part8_r.tga", test_8_r_write);
    loadImage("./output/part8_r.tga", test_8_r_check);

    if (test_8_b_check == EXAMPLE_part8_b && test_8_g_check == EXAMPLE_part8_g && test_8_r_check == EXAMPLE_part8_r) {
        cout << "Test 8 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 8 Failed!" << endl;
    }

    ///Test 9
    Image test_9_check, test_9_write = Image(layer_blue, layer_green, layer_red);
    saveImage("./output/part9.tga", test_9_write);
    loadImage("./output/part9.tga", test_9_check);
    if (test_9_check == EXAMPLE_part9) {
        cout << "Test 9 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 9 Failed!" << endl;
    }

    ///Test 10
    Image test_10_check, test_10_write = text2.flip();
    saveImage("./output/part10.tga", test_10_write);
    loadImage("./output/part10.tga", test_10_check);
    if (test_10_check == EXAMPLE_part10) {
        cout << "Test 10 Passed!" << endl;
        passed++;
    }
    else {
        cout << "Test 10 Failed!" << endl;
    }

    cout << "Test results: " << passed << " / 10" << endl;

    ///Extracredit
    Image cuadrants[4] = {text, car, pattern1, circles};
    Image test_ec_check, test_ec_write = Image(cuadrants);
    saveImage("./output/extracredit.tga", test_ec_write);
    loadImage("./output/extracredit.tga", test_ec_check);
    if (test_ec_check == EXAMPLE_extracredit) {
        cout << "Test extracredit Passed!" << endl;
    }
    else {
        cout << "Test extracredit Failed!" << endl;
    }

    return 0;
}

void loadImage(string name, Image &image) {
    //load header
    Header header;
    ifstream file (name, ios::in | ios::binary);
    if (!file) {
        cout << "There was a problem reading image: " << name << endl;
        return;
    }
    file.read(&header.idLength, 1);
    file.read(&header.colorMapType, 1);
    file.read(&header.dataTypeCode, 1);
    file.read( (char*) &header.colorMapOrigin, 2);
    file.read( (char*) &header.colorMapLength, 2);
    file.read(&header.colorMapDepth, 1);
    file.read( (char*) &header.xOrigin, 2);
    file.read( (char*) &header.yOrigin, 2);
    file.read( (char*) &header.width, 2);
    file.read( (char*) &header.height, 2);
    file.read(&header.bitsPerPixel, 1);
    file.read(&header.imageDescriptor, 1);

    image.setHeader(header);

    //load pixels

    const int SIZE = image.getSize();
    Pixel *colorMap = new Pixel[SIZE];
    for (int index = 0; index < SIZE; index++) {
        char blue, green, red;
        file.read(&blue, 1);
        file.read(&green, 1);
        file.read(&red, 1);
        colorMap[index].setBlue(blue);
        colorMap[index].setGreen(green);
        colorMap[index].setRed(red);
    }

    image.setColorMap(colorMap);
}

void saveImage(string name, Image &image) {
    ofstream file (name, ios::out | ios::binary);
    if (!file) {
        cout << "There was a problem writing image: " << name << endl;
        return;
    }
    Header header = image.getHeader();
    file.write(&(header.idLength), 1);
    file.write(&(header.colorMapType), 1);
    file.write(&(header.dataTypeCode), 1);
    file.write((char*) &header.colorMapOrigin, 2);
    file.write((char*) &header.colorMapLength, 2);
    file.write(&header.colorMapDepth, 1);
    file.write((char*) &header.xOrigin, 2);
    file.write((char*) &header.yOrigin, 2);
    file.write( (char*)&header.width, 2);
    file.write( (char*)&header.height, 2);
    file.write(&header.bitsPerPixel, 1);
    file.write(&header.imageDescriptor, 1);

    int size = image.getSize();
    for (int index = 0; index < size; index++) {
        const unsigned char colors[3] = {
                image.getColorMap()[index].getBlue(),
                image.getColorMap()[index].getGreen(),
                image.getColorMap()[index].getRed()
        };
        file.write((char*) &colors[0], 1);
        file.write((char*) &colors[1], 1);
        file.write((char*) &colors[2], 1);
    }
}