//
// Created by Ignorant on 2024/4/10.
//

#include <iostream>
using namespace std;

int main() {
    double k = 0;
    scanf("%lf", &k);
    double s = 1;
    int n = 1;
    while (s <= k) {
        n++;
        s += 1.0 / n;
    }
    printf("%d\n", n);
    return 0;
}
