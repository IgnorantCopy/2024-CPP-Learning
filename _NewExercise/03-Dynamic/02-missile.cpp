//
// Created by Ignorant on 2024/9/24.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int *height = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    vector<vector<int>> subArrays;
    subArrays.push_back(vector<int>{height[0]});
    for (int i = 1; i < n; i++) {
        int current = height[i];
        int len = subArrays.size();
        for (int j = 0; j < len; j++) {
            if (current <= subArrays[j].back()) {
                subArrays[j].push_back(current);
            } else if (current > subArrays[j].front()) {
                    subArrays.push_back(vector<int>{current});
            } else {
                vector<int> temp = {subArrays[j].front()};
                for (int k = 1; k < subArrays[j].size(); k++) {
                    if (current > subArrays[j][k]) {
                        temp.push_back(current);
                        break;
                    } else {
                        temp.push_back(subArrays[j][k]);
                    }
                }
                subArrays.push_back(temp);
            }
        }
    }
    int maxLen = 0;
    for (int i = 0; i < subArrays.size(); i++) {
        if (subArrays[i].size() > maxLen) {
            maxLen = subArrays[i].size();
        }
    }
    cout << maxLen << endl;
    delete[] height;
    return 0;
}
