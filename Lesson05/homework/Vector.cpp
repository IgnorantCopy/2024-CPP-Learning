//
// Created by Ignorant on 2024/5/10.
//

#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() = default;

Vector::Vector(size_t count, int value): sz_(count), cap_(count) {
    if (count == 0) {
        this->arr_ = nullptr;
    } else {
        this->arr_ = new int[cap_];
        for (int i = 0; i < cap_; i++) {
            this->arr_[i] = value;
        }
    }
}

Vector::Vector(const Vector &v) {
    if (nullptr == &v) {
        this->arr_ = nullptr;
        this->sz_ = 0;
        this->cap_ = 0;
        return;
    }
    this->sz_ = v.sz_;
    this->cap_ = v.cap_;
    if (nullptr == v.arr_) {
        this->arr_ = nullptr;
    } else {
        this->arr_ = new int[cap_];
        for (int i = 0; i < cap_; i++) {
            this->arr_[i] = v.arr_[i];
        }
    }
}

Vector::~Vector() {
    delete[] arr_;
    arr_ = nullptr;
    sz_ = 0;
    cap_ = 0;
}

Vector &Vector::operator=(const Vector &v) {
    if (nullptr == &v) {
        delete[] arr_;
        arr_ = nullptr;
        sz_ = 0;
        cap_ = 0;
        return *this;
    }
    if (this == &v) {
        return *this;
    }
    delete[] arr_;
    this->sz_ = v.sz_;
    this->cap_ = v.cap_;
    if (nullptr == v.arr_) {
        this->arr_ = nullptr;
    } else {
        this->arr_ = new int[cap_];
        for (int i = 0; i < cap_; i++) {
            this->arr_[i] = v.arr_[i];
        }
    }
    return *this;
}

int &Vector::operator[](size_t n) {
    if (n < cap_) {
        return arr_[n];
    }
}

size_t Vector::size() const {
    return sz_;
}

size_t Vector::capacity() const {
    return cap_;
}

void Vector::push_back(const int &num) {
    if (sz_ == cap_) {
        if (arr_ == nullptr) {
            arr_ = new int[1];
            sz_ = 0;
            cap_ = 1;
        } else {
            int *new_arr = new int[cap_ * 2];
            for (int i = 0; i < sz_; i++) {
                new_arr[i] = arr_[i];
            }
            delete[] arr_;
            arr_ = new_arr;
            cap_ *= 2;
        }
    }
    arr_[sz_++] = num;
}

void Vector::pop_back() {
    if (sz_ > 0) {
        sz_--;
        arr_[sz_] = 0;
    }
}

int main() {
//    Vector v;
//    cout << v.size() << ' ' << v.capacity() << endl;
//    v.push_back(1);
//    cout << v.size() << ' ' << v.capacity() << endl;
    
//    Vector v(2, 0);
//    cout << v.size() << ' ' << v.capacity() << endl;
//    v.push_back(1);
//    cout << v.size() << ' ' << v.capacity() << endl;
    
    Vector v1(3, 2);
    cout << v1.size() << ' ' << v1.capacity() << endl;
    Vector v2 = v1;
    cout << v2.size() << ' ' << v2.capacity() << endl;
    v1[0] = 1;
    cout << v1[0] << ' ' << v2[0] << endl;
    return 0;
}
