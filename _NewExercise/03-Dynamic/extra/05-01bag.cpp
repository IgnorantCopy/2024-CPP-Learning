//
// Created by Ignorant on 2024/10/1.
//

#include <iostream>
using namespace std;

void solve() {
    int n = 0;
    int W = 0;
    cin >> n >> W;
    if (n == 0 || W == 0) {
        return;
    }
    auto *v = new int[n];
    auto *w = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    auto **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[W + 1];
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << dp[n][W] << endl;
    delete[] v;
    delete[] w;
    for (int i = 0; i < n + 1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
}

int main() {
    while (true) {
        solve();
        if (cin.peek() == EOF) {
            break;
        }
    }
    return 0;
}
