#include "TextArea.h"

// Default constructor (fix for HeapArrays)
TextArea::TextArea()
    : dimensions{0, 0, 0, 0}, text(""), id(""), fill(RGB::WHITE()), border(RGB::BLACK()) 
{
}

// Constructor using individual values
TextArea::TextArea(int x, int y, int width, int height, const std::string &id, const std::string &text,
                   RGB fill, RGB border)
    : dimensions{x, y, width, height}, id(id), text(text), fill(fill), border(border) 
{
}

// Constructor using a Rectangle object
TextArea::TextArea(const Rectangle &rect, const std::string &id, const std::string &text,
                   RGB fill, RGB border)
    : dimensions(rect), id(id), text(text), fill(fill), border(border) 
{
}

// Copy constructor
TextArea::TextArea(const TextArea &other)
    : dimensions(other.dimensions), id(other.id), fill(other.fill), border(other.border) 
{
    text = "DUPLICATE"; // Special behavior for testing
}

// Print function
void TextArea::print() const
{
    std::cout << "TextArea id: " << id << std::endl;
    std::cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size: " << dimensions.width << "x" << dimensions.height << std::endl;
    std::cout << "Text: " << text << std::endl;
}

// Set Fill Color
void TextArea::setFill(const RGB &fill)
{
    this->fill = fill;
}

// Set Border Color
void TextArea::setBorder(const RGB &border)
{
    this->border = border;
}

std::string TextArea::getId() const
{
    return id;
}

// Check Overlapping
bool TextArea::overlaps(const TextArea &ta) const
{
    return dimensions.overlaps(ta.dimensions);
}
