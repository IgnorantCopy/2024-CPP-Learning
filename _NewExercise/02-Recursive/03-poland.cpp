//
// Created by Ignorant on 2024/9/10.
//

#include <iostream>
#include <iomanip>
using namespace std;

double poland() {
    string s;
    cin >> s;
    switch (s[0]) {
        case '*':
            return poland() * poland();
        case '+':
            return poland() + poland();
        case '-':
            return poland() - poland();
        case '/':
            return poland() / poland();
        default:
            return stod(s);
    }
}

int main() {
    printf("%.1f", poland());
    return 0;
}
