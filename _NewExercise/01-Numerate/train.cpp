//
// Created by Ignorant on 2024/9/3.
//

#include <iostream>
using namespace std;

int peoples(int a, int x, int y) {
    if (x == 1 || x == 2) {
        return a;
    }
    int result = a;
    int bonus = a;
    int old_bonus = a;
    for (int i = 0; i < x - 2; i++) {
        result += bonus;
        if (i == 0) {
            bonus = y;
        } else {
            int temp = bonus;
            bonus = bonus + old_bonus;
            old_bonus = temp;
        }
    }
    return result;
}

int solve(int a, int n, int m, int x) {
    if (x == 1 || x == 2) {
        return a;
    }
    int y = 0;
    while (1) {
        if (peoples(a, n - 1, y) == m) {
            break;
        }
        y++;
    }
    return peoples(a, x, y);
}

int main() {
    int a = 0;
    int n = 0;
    int m = 0;
    int x = 0;
    cin >> a >> n >> m >> x;
    cout << solve(a, n, m, x) << endl;
    return 0;
}
