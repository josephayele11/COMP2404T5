#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "RGB.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>

class TextArea {
private:
    Rectangle dimensions;
    std::string text;
    std::string id;
    RGB fill;
    RGB border;

public:
    // Default constructor (fix for HeapArrays)
    TextArea();

    // Existing constructors
    TextArea(int x, int y, int width, int height, const std::string &id, const std::string &text,
             RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

    TextArea(const Rectangle &rect, const std::string &id, const std::string &text,
             RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

    // Copy constructor
    TextArea(const TextArea &other);

    // Getters
    Rectangle getDimensions() const;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getText() const;
    std::string getId() const;
    RGB getFill() const;
    RGB getBorder() const;

    // Setters
    void setDimensions(const Rectangle &rect);
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setText(const std::string &text);
    void setId(const std::string &id);
    void setFill(const RGB &fill);
    void setBorder(const RGB &border);

    // Drawing function
    void draw(Display *display, Window win, GC gc, int x, int y);

    // Overlaps function
    bool overlaps(const TextArea &ta) const;

    // Print function
    void print() const;
};

#endif // TEXTAREA_H
