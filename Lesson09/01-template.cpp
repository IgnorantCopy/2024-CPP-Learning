//
// Created by Ignorant on 2024/5/30.
//

#include <iostream>
using namespace std;

/*
 * function template
 *  template <typename list> <return type> function_name(parameter list) {
 *      // code
 *  }
 */
template <class T1, class T2> void sort(T1 arr[], unsigned int n, T2 cmp) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!cmp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <class T, int size> void printArray(T (&arr)[size]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
 * class template
 *  template <typename list> class <class name> {
 *      // code
 *  }
 */
template <class T, int size> class Stack {
    T buffer[size];
    int top = -1;
public:
    void push(const T &x) {
        if (top == size - 1) {
            cout << "Stack overflow" << endl;
        } else {
            buffer[++top] = x;
        }
    }
    
    T pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        } else {
            return buffer[top--];
        }
    }
};

int main() {
    int arr[] = {5, 2, 8, 3, 9, 1};
    sort(arr, 6, [](int a, int b) { return a > b; });
    printArray(arr);
    double darr[] = {5.2, 2.5, 8.1, 3.7, 9.3, 1.4};
    sort(darr, 6, [](double a, double b) { return a > b; });
    printArray(darr);
    Stack<int, 10> stack;
    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << stack.pop() << " ";
    }
    cout << endl;
    return 0;
}
