//
// Created by Ignorant on 2024/9/3.
//

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n = 0;
    cin >> n;
    auto *numbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (numbers[i] >= numbers[j]) {
                continue;
            }
            if (gcd(numbers[i], numbers[j]) == 1) {
                count++;
            }
        }
    }
    cout << count << endl;
    delete[] numbers;
    return 0;
}
