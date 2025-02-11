#ifndef RGB_H
#define RGB_H

#include "defs.h"

using namespace std;

class RGB {
private:
    int r, g, b;

public:
    RGB();
    RGB(int red, int green, int blue);
    RGB(CuColour color);
    int getR() const;
    int getG() const;
    int getB() const;
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    CuColour getColour() const;
    void print() const;
    void setColour(CuColour colour);

    

    // Static functions to return commonly used colors
    static const RGB WHITE();
    static const RGB BLACK();
    static const RGB RED();
    static const RGB GREEN();
    static const RGB BLUE();
};

#endif // RGB_H

