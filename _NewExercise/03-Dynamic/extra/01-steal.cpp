//
// Created by Ignorant on 2024/9/24.
//

#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        int *money = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> money[j];
        }
        int *dp = new int[n];
        dp[0] = money[0];
        dp[1] = max(money[0], money[1]);
        for (int j = 2; j < n; j++) {
            dp[j] = max(dp[j - 1], dp[j - 2] + money[j]);
        }
        cout << dp[n - 1] << endl;
        delete[] money;
        delete[] dp;
    }
    return 0;
}
