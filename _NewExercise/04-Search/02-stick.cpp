//
// Created by Ignorant on 2024/10/8.
//

#include <iostream>
#include <algorithm>
using namespace std;

int sticks[64] = {0};
bool isUsed[64] = {0};
int length = 0;
int n = 0;

bool dfs(int target, int count, int currentLength, int last) {
    if (count == target) {
        return true;
    }
    if (currentLength == length) {
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (!isUsed[i]) {
                index = i;
                break;
            }
        }
        if (dfs(target, count + 1, 0, index)) {
            return true;
        }
        isUsed[index] = false;
        return false;
    }
    int left = last;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (sticks[mid] + currentLength <= length) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    for (int i = left; i < n; i++) {
        if (isUsed[i]) {
            continue;
        }
        isUsed[i] = true;
        if (dfs(target, count, currentLength + sticks[i], i + 1)) {
            return true;
        }
        isUsed[i] = false;
        if (currentLength == 0 || currentLength + sticks[i] == length) {
            return false;
        }
    }
    return false;
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        int sum = 0;
        int len = n;
        for (auto &item: sticks) {
            item = 0;
        }
        for (int i = 0; i < n; i++) {
            int temp = 0;
            cin >> temp;
            if (temp > 50) {
                len--;
                continue;
            }
            sticks[i] = temp;
            sum += sticks[i];
        }
        n = len;
        sort(sticks, sticks + n, [](int a, int b) {
            return a > b;
        });
        for (int s = sticks[0]; s <= sum; s++) {
            if (sum % s != 0) {
                continue;
            }
            for (bool & i : isUsed) {
                i = false;
            }
            int target = sum / s;
            length = s;
            if (dfs(target, 0, 0, 0)) {
                break;
            }
        }
        cout << length << endl;
    }
    return 0;
}
