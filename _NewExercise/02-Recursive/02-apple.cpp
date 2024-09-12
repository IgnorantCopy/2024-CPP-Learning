//
// Created by Ignorant on 2024/9/10.
//

#include <iostream>
using namespace std;

int result(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    }
    if (n > m) {
        return result(m, m);
    }
    return result(m, n - 1) + result(m - n, n);
}

int main() {
    int m = 0;
    int n = 0;
    cin >> m >> n;
    cout << result(m, n) << endl;
    return 0;
}
