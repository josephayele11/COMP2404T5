#include "TAArray.h"
#include <iostream>

// Constructor: Allocates array and initializes size
TAArray::TAArray()
{
    elements = new TextArea*[MAX_ARR]; // Allocate array of TextArea pointers
    size = 0;

    // Initialize all pointers to nullptr
    for (int i = 0; i < MAX_ARR; i++)
    {
        elements[i] = nullptr;
    }
}

// Destructor: Deletes all dynamically allocated TextAreas and array
TAArray::~TAArray()
{
    for (int i = 0; i < size; i++)
    {
        delete elements[i]; // Free each allocated TextArea
    }
    delete[] elements; // Free the array itself
}

// Add TextArea to the back of the array
bool TAArray::add(TextArea* ta)
{
    if (size >= MAX_ARR)
    {
        return false; // Array is full
    }

    elements[size] = ta; // Add at the back
    size++;
    return true;
}

// Add TextArea at a specific index
bool TAArray::add(TextArea* ta, int index)
{
    if (size >= MAX_ARR || index < 0 || index > size)
    {
        return false; // Invalid index or array is full
    }

    // Shift elements to make room for the new TextArea
    for (int i = size; i > index; i--)
    {
        elements[i] = elements[i - 1];
    }

    elements[index] = ta;
    size++;
    return true;
}

// Get TextArea pointer at index (now marked as const)
TextArea* TAArray::get(int index) const
{
    if (index < 0 || index >= size)
    {
        return nullptr; // Invalid index
    }
    return elements[index];
}

TextArea* TAArray::get(const std::string& name) const
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i]->getId() == name)
        {
            return elements[i];
        }
    }
    return nullptr;
}

// Remove TextArea at index
TextArea* TAArray::remove(int index)
{
    if (index < 0 || index >= size)
    {
        return nullptr; // Invalid index
    }

    TextArea* removed = elements[index];

    // Shift elements down
    for (int i = index; i < size - 1; i++)
    {
        elements[i] = elements[i + 1];
    }

    elements[size - 1] = nullptr; // Nullify last slot
    size--;
    return removed;
}

TextArea* TAArray::remove(const std::string& name)
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i]->getId() == name)
        {
            return remove(i);
        }
    }
    return nullptr;
}

void TAArray::print() const
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i])
        {
            elements[i]->print();
        }
    }
}
