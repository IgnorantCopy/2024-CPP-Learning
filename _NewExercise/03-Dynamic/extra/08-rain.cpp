//
// Created by Ignorant on 2024/10/1.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    auto *ratings = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }
    auto *leftMax = new int[n];
    auto *rightMax = new int[n];
    leftMax[0] = ratings[0];
    rightMax[n - 1] = ratings[n - 1];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], ratings[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], ratings[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(leftMax[i], rightMax[i]) - ratings[i];
    }
    cout << sum << endl;
    delete[] ratings;
    delete[] leftMax;
    delete[] rightMax;
    return 0;
}
