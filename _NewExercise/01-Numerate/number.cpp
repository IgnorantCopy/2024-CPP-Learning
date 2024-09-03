//
// Created by Ignorant on 2024/9/3.
//

#include <iostream>
using namespace std;

int transition(int n, int base = 10) {
    int result = 0;
    while (n > 0) {
        result += n % base;
        n /= base;
        result *= 10;
    }
    return result / 10;
}


int main() {
    for (int i = 50; i < 1000; i++) {
        if (transition(transition(i, 7)) == transition(i, 9)) {
            cout << i << endl;
            cout << transition(i, 9) << endl;
            cout << transition(i, 7) << endl;
            return 0;
        }
    }
    return 0;
}
