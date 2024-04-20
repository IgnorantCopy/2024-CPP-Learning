//
// Created by Ignorant on 2024/4/10.
//

#include <iostream>
#define LEN 7
using namespace std;

int main() {
    int hours[LEN] = {0};
    for (int i = 0; i < LEN; i++) {
        int a = 0;
        int b = 0;
        scanf("%d%d", &a, &b);
        hours[i] = a + b;
    }
    int days[LEN] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < LEN - 1; i++) {
        for (int j = 0; j < LEN - 1 - i; j++) {
            if (hours[j] >= hours[j + 1]) {
                int temp = hours[j];
                hours[j] = hours[j + 1];
                hours[j + 1] = temp;
                temp = days[j];
                days[j] = days[j + 1];
                days[j + 1] = temp;
            }
        }
    }
    if (hours[LEN - 1] > 8) {
        printf("%d\n", days[LEN - 1]);
    } else {
        printf("0\n");
    }
    return 0;
}
