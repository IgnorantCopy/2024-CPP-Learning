//
// Created by Ignorant on 2024/5/29.
//

#ifndef INC_2024_CPP_LEARNING_6_3_H
#define INC_2024_CPP_LEARNING_6_3_H

class MyArray{
    int * arr;
    int size;
    int isDeleted = 1;
public:
    class Iterator{
        int *ptr;
        int *isDeleted;
        int size;
        int index;
        bool isOver;
    public:
        Iterator(int *arr, int sz, int i, int *isDeleted): ptr(&(arr[i])), isDeleted(isDeleted), size(sz), index(i){
            if (i >= sz || i < 0) {
                isOver = true;
            } else {
                isOver = false;
            }
            if (arr == nullptr) {
                ptr = nullptr;
            } else {
                ptr = &(arr[i]);
            }
        };
        
        bool get(int & value) const {
            if (isOver || nullptr == ptr || *isDeleted == 0) {
                return false;
            }
            value = *ptr;
            return true;
        }
        
        bool put(int value) {
            if (isOver || nullptr == ptr || *isDeleted == 0) {
                return false;
            }
            *ptr = value;
            return true;
        }
        
        Iterator &operator++() {
            index++;
            if (nullptr != ptr) {
                ptr++;
            }
            if (index >= size || index < 0) {
                isOver = true;
            } else {
                isOver = false;
            }
            return *this;
        }
        
        Iterator operator++(int) {
            Iterator temp = *this;
            index++;
            if (nullptr != ptr) {
                ptr++;
            }
            if (index >= size || index < 0) {
                isOver = true;
            } else {
                isOver = false;
            }
            return temp;
        }
        
        Iterator &operator--() {
            index--;
            if (nullptr != ptr) {
                ptr--;
            }
            if (index >= size || index < 0) {
                isOver = true;
            } else {
                isOver = false;
            }
            return *this;
        }
        
        Iterator operator--(int) {
            Iterator temp = *this;
            index--;
            if (nullptr != ptr) {
                ptr--;
            }
            if (index >= size || index < 0) {
                isOver = true;
            } else {
                isOver = false;
            }
            return temp;
        }
        
        bool operator==(const Iterator & other) const {
            return ptr == other.ptr;
        }
        
        bool operator!=(const Iterator & other) const {
            return ptr != other.ptr;
        }
        
        Iterator operator+(int len) {
            return {ptr - index, size, index + len, isDeleted};
        }
        
        Iterator operator-(int len) {
            return {ptr - index, size, index - len, isDeleted};
        }
        
    };

public:
    MyArray(int sz): size(sz) {
        if (sz <= 0) {
            arr = nullptr;
        } else {
            arr = new int[sz];
            for (int i = 0; i < sz; i++) {
                arr[i] = 0;
            }
        }
    };
    ~MyArray() {
        isDeleted = 0;
        delete[] arr;
        arr = nullptr;
    }
    Iterator begin() {
        if (arr == nullptr) {
            return {nullptr, 0, 0, &isDeleted};
        }
        return {arr, size, 0, &isDeleted};
    }
    Iterator end() {
        if (arr == nullptr) {
            return {nullptr, 0, 0, &isDeleted};
        }
        return {arr, size, size, &isDeleted};
    }
};

#endif //INC_2024_CPP_LEARNING_6_3_H
