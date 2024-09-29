//
// Created by Ignorant on 2024/9/26.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int money = 0;
    vector<int> index;
};

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
        if (n == 1) {
            cout << money[0] << endl;
            cout << "1" << endl;
            delete[] money;
            continue;
        }
        vector<Node> dp(3);
        dp[0].money = money[0];
        dp[0].index = {1};
        if (money[0] >= money[1]) {
            dp[1].money = money[0];
            dp[1].index = dp[0].index;
        } else {
            dp[1].money = money[1];
            dp[1].index = {2};
        }
        for (int j = 2; j < n; j++) {
            if (dp[1].money > dp[0].money + money[j]) {
                dp[2].money = dp[1].money;
                dp[2].index = dp[1].index;
            } else if (dp[1].money == dp[0].money + money[j]) {
                dp[2].money = dp[1].money;
                vector<int> index1 = dp[0].index;
                index1.push_back(j + 1);
                vector<int> index2 = dp[1].index;
                size_t len = min(index1.size(), index2.size());
                int choose = -1;
                bool flag = false;
                for (int k = 0; k < len; k++) {
                    if (index1[k] > index2[k]) {
                        choose = 1;
                        flag = true;
                        break;
                    } else if (index1[k] < index2[k]) {
                        choose = 0;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    if (index1.size() < index2.size()) {
                        choose = 0;
                    } else if (index1.size() > index2.size()) {
                        choose = 1;
                    }
                }
                if (choose == 0) {
                    dp[2].index = index1;
                } else if (choose == 1) {
                    dp[2].index = index2;
                }
            } else {
                dp[2].index = dp[0].index;
                dp[2].index.push_back(j + 1);
                dp[2].money = dp[0].money + money[j];
            }
            dp.erase(dp.begin());
            dp.emplace_back();
        }
        cout << dp[1].money << endl;
        vector<int> index = dp[1].index;
        for (int j : index) {
            cout << j << " ";
        }
        cout << endl;
        delete[] money;
    }
    return 0;
}
