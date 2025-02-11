#include "RGB.h"
#include <iostream>

RGB::RGB(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
}
RGB::RGB(CuColour colour){
    r = (colour & 0xFF0000) >> 16;
    g = (colour & 0x00FF00) >> 8;
    b = (colour & 0x0000FF);
}
RGB::RGB(){
    r = 0;
    g = 0;
    b = 0;
}

CuColour RGB::getColour() const {
    return (r << 16) | (g << 8) | b;
}

int RGB::getR() const {
    return r;
}

int RGB::getG() const {
    return g;
}

int RGB::getB() const {
    return b;
}

void RGB::setR(int red){
    r = red;
}

void RGB::setG(int green){
    g = green;
}

void RGB::setB(int blue){
    b = blue;
}

void RGB::setColour(CuColour colour){
    r = (colour & 0xFF0000) >> 16;
    g = (colour & 0x00FF00) >> 8;
    b = (colour & 0x0000FF);
}

void RGB::print() const {
    std::cout<<"RGB: "<<r<<", "<<g<<", "<<b<<std::endl;
}

const RGB RGB::WHITE() {
    return RGB(255, 255, 255);
}

const RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}

const RGB RGB::RED() {
    return RGB(255, 0, 0);
}

const RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}

const RGB RGB::BLUE() {
    return RGB(0, 0, 255);
}