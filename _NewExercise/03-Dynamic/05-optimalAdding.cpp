//
// Created by Ignorant on 2024/9/26.
//

#include <iostream>
#include <string>
using namespace std;

string add(string str1, string str2) {
    if (str1 == "INF" || str2 == "INF") {
        return "INF";
    }
    string result;
    int carry = 0;
    auto len1 = (int)(str1.length() - 1);
    auto len2 = (int)(str2.length() - 1);
    while (len1 >= 0 || len2 >= 0) {
        int sum = carry;
        if (len1 >= 0) {
            sum += str1[len1] - '0';
            len1--;
        }
        if (len2 >= 0) {
            sum += str2[len2] - '0';
            len2--;
        }
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }
    if (carry) {
        result = to_string(carry) + result;
    }
    return result;
}

string minStr(string str1, string str2) {
    if (str1 == "INF" && str2 == "INF") {
        return "INF";
    }
    if (str1 == "INF") {
        return str2;
    }
    if (str2 == "INF") {
        return str1;
    }
    auto len1 = (int)(str1.length());
    auto len2 = (int)(str2.length());
    if (len1 < len2) {
        return str1;
    }
    if (len2 < len1) {
        return str2;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] < str2[i]) {
            return str1;
        }
        if (str1[i] > str2[i]) {
            return str2;
        }
    }
    return str1;
}

void optimalAdding() {
    int m = 0;
    cin >> m;
    string numbers;
    cin >> numbers;
    size_t len = numbers.length();
    auto **dp = new string*[m + 1];
    for (int i = 0; i < m + 1; i++) {
        dp[i] = new string[len + 1];
    }
    for (int i = 1; i < len + 1; i++) {
        dp[0][i] = numbers.substr(0, i);
    }
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < len + 1; j++) {
            if (j < i + 1) {
                dp[i][j] = "INF";
            } else {
                string minimum = add(dp[i - 1][i], numbers.substr(i, j - i));
                for (int k = i + 1; k < j; k++) {
                    minimum = minStr(minimum, add(dp[i - 1][k], numbers.substr(k, j - k)));
                }
                dp[i][j] = minimum;
            }
        }
    }
    string result = dp[m][len];
    cout << result << endl;
    for (int i = 0; i < m + 1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
}

int main() {
    while (true) {
        optimalAdding();
        if (cin.get() == EOF) {
            break;
        }
    }
    return 0;
}
