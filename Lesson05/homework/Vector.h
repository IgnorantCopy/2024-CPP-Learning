//
// Created by Ignorant on 2024/5/10.
//

#ifndef INC_2024_CPP_LEARNING_VECTOR_H
#define INC_2024_CPP_LEARNING_VECTOR_H

#include <cstring>

/*
In this assignment, you will need to implement a simplified
version of std::vector, which supports some modifiers
*/
class Vector {
public:
    Vector();
    Vector(size_t count, int value = 0);
    Vector(const Vector &v);
    ~Vector();
    
    Vector &operator=(const Vector &v);
    
    int &operator[](size_t n);
    
    size_t size() const;
    size_t capacity() const;
    
    void push_back(const int &num);
    void pop_back();

private:
    int *arr_ = nullptr;
    size_t sz_ = 0; // the size of vector
    size_t cap_ = 0; // the capacity of vector
};

#endif //INC_2024_CPP_LEARNING_VECTOR_H
