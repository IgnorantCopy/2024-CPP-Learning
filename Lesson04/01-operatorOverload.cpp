//
// Created by Ignorant on 2024/4/11.
//

#include <iostream>
#include <cstring>
using namespace std;

class Complex {
    double real;
    double imag;
public:
    Complex():real(0), imag(0){}
    
    Complex(double real, double imag):real(real), imag(imag){}
    
    double getReal() const {
        return this->real;
    }
    
    void setReal(double r) {
        this->real = r;
    }
    
    double getImag() const {
        return this->imag;
    }
    
    void setImag(double image) {
        this->imag = image;
    }
    
    string toString() const {
        if (this->real == 0 && this->imag == 0) {
            return "zero";
        } else if (this->real == 0) {
            return to_string(this->imag) + "i";
        } else if (this->imag == 0) {
            return to_string(this->real);
        } else if (this->imag < 0) {
            return to_string(this->real) + " - " + to_string(-this->imag) + 'i';
        }
        return to_string(this->real) + " + " + to_string(this->imag) + 'i';
    }
    
    /*
     * operator overloading:
     *  1.function
     *      ① a non-static field function
     *      ② a global function(friend function)
     *  2.format: operator <operator>
     *  3.rules
     *      ① the operator must be existed
     *      ② exclude . .* ?: :: sizeof operators
     *      ③ follow the existing grammar
     */
    Complex operator + (const Complex &complex) const {
        return {this->real + complex.getReal(), this->imag + complex.getImag()};
    }
    
    Complex operator + (double r) const {
        return {this->real + r, this->imag};
    }
    
    Complex operator * (const Complex &complex) const {
        double r = this->real * complex.getReal() - this->imag * complex.getImag();
        double image = this->real * complex.getImag() + this->imag * complex.getReal();
        return {r, image};
    }
    
    Complex operator * (double r) const {
        return {this->real * r, this->imag * r};
    }
    
    Complex operator -() const {
        return {-this->real, -this->imag};
    }
    
    bool operator == (const Complex &complex) const {
        return this->real == complex.getReal() && this->imag == complex.getImag();
    }
    
    bool operator != (const Complex &complex) const {
        return !(*this == complex);
    }
    
    bool operator !() const {
        return this->real == 0 && this->imag == 0;
    }
    
    Complex& operator ++() {
        this->real++;
        this->imag++;
        return *this;
    }
    
    Complex operator ++(int) {
        Complex temp = *this;
        this->real++;
        this->imag++;
        return temp;
    }
};

class String {
    int len;
    char *str;
public:
    String (const char *s) {
        this->len = strlen(s);
        this->str = new char[len + 1];
        strcpy(str, s);
    }
    ~String() {
        delete[] str;
        str = nullptr;
    }
    String& operator = (const String &s) {
        if (&s == this) {
            return *this;
        }
        delete []str;
        this->len = s.len;
        this->str = new char[len + 1];
        strcpy(str, s.str);
        return *this;
    }
    /*
     * compare assignment operator and copy constructor:
     *  A<class> b = a ==> copy constructor
     *  b = a ==> assignment operator
     */
    char* getStr() const {
        return this->str;
    }
    
    int getLen() const {
        return this->len;
    }
};

class Vector {
    int size;
    int *arr;
public:
    Vector() {}
    explicit Vector(int size):size(size), arr(new int[size]) {}
    
    int getSize() const {
        return this->size;
    }
    
    int& operator [] (int index) {
        return arr[index];
    }
};

class Matrix {
    Vector *rows;
    int colSize;
public:
    explicit Matrix(int colSize):rows(new Vector[colSize]), colSize(colSize) {}
    
    ~Matrix() {
        delete[] rows;
    }
    
    int getColSize() const {
        return this->colSize;
    }
    
    Vector& operator [] (int index) {
        return rows[index];
    }
};

// functor
class Random {
    unsigned int seed;
public:
    explicit Random(unsigned int seed):seed(seed) {}
    unsigned int operator () () {
        seed = (seed * 1103515245 + 12345) % (1 << 31);
        return seed;
    }
};

int main() {
    auto complex1 = Complex(1, 1);
    auto complex2 = Complex(4, 3);
    cout << (complex1 + complex2).toString() << endl;
    cout << (complex1 * complex2).toString() << endl;
    cout << (-complex1).toString() << endl;
    cout << (complex1 == complex2) << endl;
    cout << (complex1!= complex2) << endl;
    cout << !complex2 << endl;
    cout << complex1++.toString() << endl;
    cout << (++complex1).toString() << endl;
    
    String str1("abc");
    String str2("def");
    str1 = str2;
    cout << str1.getStr() << endl;
    
    Vector vector1(3);
    Vector vector2(3);
    Vector vector3(3);
    Vector vector4(3);
    Random random(114514);
    vector3[2] = (int)(random() % 100);
    Matrix matrix(4);
    matrix[0] = vector1;
    matrix[1] = vector2;
    matrix[2] = vector3;
    matrix[3] = vector4;
    cout << matrix[2][2] << endl;
    
    return 0;
}
