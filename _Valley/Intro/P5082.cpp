//
// Created by Ignorant on 2024/3/14.
//

#include <iostream>
using namespace std;

int main() {
    double sum1 = 0;
    double sum2 = 0;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double temp = 0;
        scanf("%lf", &temp);
        sum1 += temp;
    }
    for (int i = 0; i < n; i++) {
        double temp = 0;
        scanf("%lf", &temp);
        sum2 += temp;
    }
    printf("%.6f", (sum1 * 3 - sum2 * 2) / (sum1 - sum2));
    return 0;
}
