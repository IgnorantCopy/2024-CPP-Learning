//
// Created by Ignorant on 2024/9/3.
//

#include <iostream>
using namespace std;

int pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * pow(a, b - 1);
}

int main() {
    int n = 0;
    cin >> n;
    if (n == 2) {
        cout << 7 << endl;
    } else {
        cout << pow(n, n) - (n - 1) << endl;
    }
    return 0;
}
