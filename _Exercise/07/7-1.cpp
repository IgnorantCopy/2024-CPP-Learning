//
// Created by Ignorant on 2024/6/12.
//

#include "7-1.h"
#include <iostream>
using namespace std;

int main() {
    static constexpr int fib = fibnacci<10>::value;
    cout << fib << endl;
    return 0;
}
