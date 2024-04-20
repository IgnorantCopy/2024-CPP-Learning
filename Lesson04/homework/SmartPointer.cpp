//
// Created by Ignorant on 2024/4/20.
//

#include <iostream>
#include <memory>
using namespace std;

class PtrA;

class A {
    int x;
public:
    A(int i) : x(i) {}
    
    void f() {
        cout << "A::f()" << endl;
    }
    
    void *operator new(size_t size) {
        return (PtrA *) malloc(size);
    }
    
    void operator delete(void *ptr) {
        free(ptr);
    }
};

class PtrA {
    int *counter;
    A *ptr;
public:
    PtrA(A *p) : ptr(p), counter(new int(1)) {}
    
    PtrA &operator=(const PtrA &other) {
        if (this != &other) {
            this->~PtrA();
            if (&other == nullptr) {
                counter = nullptr;
                ptr = nullptr;
            } else {
                ptr = other.ptr;
                counter = other.counter;
                ++(*other.counter);
            }
        }
        return *this;
    }
    
    A *operator->() const {
        return ptr;
    }
    
    ~PtrA() {
        if (counter != nullptr && --(*counter) == 0) {
            delete ptr;
            delete counter;
        }
    }
    
};

int main() {
    PtrA p1 = new A(1);
    p1->f();
    PtrA p2 = new A(2);
    p1 = p2;
    p1 = nullptr;
    p2 = nullptr;
    return 0;
}
