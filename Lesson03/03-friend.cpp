//
// Created by Ignorant on 2024/3/28.
//

#include <iostream>
using namespace std;

class Vector;

class Matrix {
private:
    int row = 1;
    int col = 1;
    int **data = nullptr;
public:
    Matrix(int row, int col, int **data) {
        if (row <= 0 || col <= 0) {
            cout << "Invalid input!" << endl;
            return;
        }
        this->row = row;
        this->col = col;
        this->data = new int *[row];
        for (int i = 0; i < row; i++) {
            this->data[i] = new int[col];
            for (int j = 0; j < col; j++) {
                this->data[i][j] = data[i][j];
            }
        }
    }
    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    
    int getElement(int i, int j) const {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            cout << "Invalid input!" << endl;
            exit(-1);
        }
        return data[i][j];
    }
    int getRow() const {
        return row;
    }
    int getCol() const {
        return col;
    }
    
    void setElement(int i, int j, int value) const {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            cout << "Invalid input!" << endl;
            exit(-1);
        }
        data[i][j] = value;
    }
    
    void print() const {
        for (int i = 0; i < row; i++) {
            cout << '|';
            for (int j = 0; j < col; j++) {
                cout << '\t' << data[i][j];
            }
            cout << "\t|" << endl;
        }
    }
    
    friend Matrix multiply(const Matrix &matrix, const Vector &vector);
};

class Vector {
private:
    int size = 1;
    int *data = nullptr;
public:
    Vector(int size, int const *data) {
        if (size <= 0) {
            cout << "Invalid input!" << endl;
            return;
        }
        this->size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++) {
            this->data[i] = data[i];
        }
    }
    ~Vector() {
        delete[] data;
    }
    
    int getElement(int i) const {
        if (i < 0 || i >= size) {
            cout << "Invalid input!" << endl;
            exit(-1);
        }
        return data[i];
    }
    int getSize() const {
        return size;
    }
    
    void setElement(int i, int value) {
        if (i < 0 || i >= size) {
            cout << "Invalid input!" << endl;
            exit(-1);
        }
        data[i] = value;
    }
    
    void print() const {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << '\t' << data[i];
        }
        cout << "\t]" << endl;
    }
    
    friend Matrix multiply(const Matrix &matrix, const Vector &vector);
};

Matrix multiply(const Matrix &matrix, const Vector &vector) {
    if (matrix.col != vector.size) {
        cerr << "Invalid input!" << endl;
        exit(-1);
    }
    auto **result = new int *[matrix.row];
    for (int i = 0; i < matrix.row; i++) {
        result[i] = new int[1];
        int temp = 0;
        for (int j = 0; j < matrix.col; j++) {
            temp += matrix.data[i][j] * vector.data[j];
        }
        result[i][0] = temp;
    }
    return {matrix.row, 1, result};
}

int main() {
    auto **data1 = new int *[3];
    for (int i = 0; i < 3; i++) {
        data1[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            data1[i][j] = i * 3 + j + 1;
        }
    }
    Matrix matrix(3, 3, data1);
    matrix.print();
    
    auto *data2 = new int[3];
    for (int i = 0; i < 3; i++) {
        data2[i] = i + 1;
    }
    Vector vector(3, data2);
    vector.print();
    
    multiply(matrix, vector).print();
    
    delete[] data2;
    for (int i = 0; i < 3; i++) {
        delete[] data1[i];
    }
    delete[] data1;
    return 0;
}
