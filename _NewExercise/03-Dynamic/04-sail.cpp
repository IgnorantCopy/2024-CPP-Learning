//
// Created by Ignorant on 2024/9/24.
//

#include <iostream>
#include <vector>
#define N 16
using namespace std;

int dp[1 << N][N] = {0};

int main() {
    int n = 0;
    cin >> n;
    int **times = new int *[n];
    for (int i = 0; i < n; i++) {
        times[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> times[i][j];
        }
    }
    int island = 1 << n;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < island; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i >> k) & 1) {
                        dp[i][j] = min(dp[i & ~(1 << j)][k] + times[k][j], dp[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[island - 1][n - 1] << endl;
    
    for (int i = 0; i < n; i++) {
        delete[] times[i];
    }
    delete[] times;
    return 0;
}
