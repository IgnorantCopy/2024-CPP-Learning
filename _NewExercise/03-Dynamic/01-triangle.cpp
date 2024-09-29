//
// Created by Ignorant on 2024/9/24.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int **numbers = new int *[n];
    for (int i = 0; i < n; i++) {
        numbers[i] = new int[i + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> numbers[i][j];
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            numbers[n - 1][j] = numbers[i - 1][j] + max(numbers[n - 1][j], numbers[n - 1][j + 1]);
        }
    }
    cout << numbers[n - 1][0] << endl;
    for (int i = 0; i < n; i++) {
        delete[] numbers[i];
    }
    delete[] numbers;
    return 0;
}
