#ifndef TAARRAY_H
#define TAARRAY_H

#define MAX_ARR 64  // Same as StudentArray

#include "TextArea.h"

class TAArray
{
  public:
    TAArray();
    ~TAArray();

    // Add to the back of the array
    bool add(TextArea* ta);

    // Add at a specific index
    bool add(TextArea* ta, int index);

    // Getters (marked as const)
    TextArea* get(int index) const;
    TextArea* get(const std::string& name) const;

    // Remove functions (optional)
    TextArea* remove(int index);
    TextArea* remove(const std::string& name);

    bool isFull() const { return size == MAX_ARR; }
    int getSize() const { return size; }
    void print() const;

  private:
    TextArea** elements;
    int size;
};

#endif // TAARRAY_H
