//
// Created by Ignorant on 2024/10/1.
//

#include <iostream>
using namespace std;

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    auto **dp = new int*[len1 + 1];
    for (int i = 0; i <= len1; i++) {
        dp[i] = new int[len2 + 1];
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[len1][len2] << endl;
    
    for (int i = 0; i <= len1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
