//
// Created by Ignorant on 2024/3/20.
//

#include <iostream>
#include <valarray>
using namespace std;

int isPrime(int n) {
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        int a = 2;
        int b = x - a;
        if (isPrime(b)) {
            cout << x << '=' << a << '+' << b << endl;
            continue;
        }
        for (a = 3; a <= x / 2; a += 2) {
            b = x - a;
            if (isPrime(a) && isPrime(b)) {
                cout << x << '=' << a << '+' << b << endl;
                break;
            }
        }
    }
    return 0;
}
