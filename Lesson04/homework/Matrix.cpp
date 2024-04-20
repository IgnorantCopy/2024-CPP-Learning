//
// Created by Ignorant on 2024/4/20.
//

#include <iostream>
using namespace std;

class Matrix {
    int rows;
    int cols;
    int **data;
public:
    Matrix() : rows(0), cols(0), data(nullptr) {}
    
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }
    
    Matrix(const Matrix& m) : rows(m.rows), cols(m.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = m.data[i][j];
            }
        }
    }
    
    Matrix& operator=(const Matrix& m) {
        if (this == &m) {
            return *this;
        }
        if (rows != m.rows || cols != m.cols) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            rows = m.rows;
            cols = m.cols;
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = m.data[i][j];
            }
        }
        return *this;
    }
    
    int* operator[](int i) {
        return data[i];
    }
    
    int operator()(int i, int j) const {
        return data[i][j];
    }
    
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    Matrix m1(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1[i][j] = i * 4 + j;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << m1[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Matrix m2;
    m2 = m1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << m2[i][j] << ", ";
            m2[i][j] += 1;
        }
        cout << endl;
    }
    cout << "next" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << m1(i, j) << ", ";
        }
        cout << endl;
    }
    cout << "next" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << m2(i, j) << ", ";
        }
        cout << endl;
    }
    return 0;
}
