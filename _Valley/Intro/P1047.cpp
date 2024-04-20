//
// Created by Ignorant on 2024/4/10.
//

#include <iostream>
using namespace std;

int main() {
    int l = 0;
    int m = 0;
    scanf("%d%d", &l, &m);
    int *road = new int[l + 1];
    for (int i = 0; i <= l; i++) {
        road[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int left = 0;
        int right = 0;
        scanf("%d%d", &left, &right);
        for (int j = left; j <= right ; j++) {
            road[j] = 0;
        }
    }
    int num = 0;
    for (int i = 0; i <= l; i++) {
        if (road[i] == 1) {
            num++;
        }
    }
    printf("%d\n", num);
    delete[] road;
    return 0;
}
