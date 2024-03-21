//
// Created by Ignorant on 2024/3/20.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int i = 0;
    int process[8] = {n};
    while (n != 495 && i < 7) {
        int num[3] = {n % 10, n % 100 / 10, n / 100};
        if ((num[0] == num[1] && num[1] == num[2]) || num[2] == 0) {
            cout << "NOT" << endl;
            return 0;
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2 - j; k++) {
                if (num[k] < num[k + 1]) {
                    int temp = num[k];
                    num[k] = num[k + 1];
                    num[k + 1] = temp;
                }
            }
        }
        int max = num[0] * 100 + num[1] * 10 + num[2];
        int min = 0;
        if (num[2] == 0) {
            min = num[1] * 100 + num[2] * 10 + num[0];
        } else {
            min = num[2] * 100 + num[1] * 10 + num[0];
        }
        n = max - min;
        i++;
        process[i] = n;
    }
    if (n != 495) {
        cout << "NOT" << endl;
    } else {
        for (int j = 0; j < i; j++) {
            cout << process[j] << '-';
        }
        cout << process[i] << endl;
    }
    return 0;
}
