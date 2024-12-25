//
// Created by Ignorant on 2024/10/15.
//

#include <iostream>
#include <queue>
using namespace std;

int inDegree[26] = {0};
int graph[26][26] = {0};
int result[26] = {0};

int topSort(int n) {
    int flag = 1;   // 1: 有序; -1: 不确定; 0: 有环
    int m = 0;
    int temp[26] = {0};
    for (int & i : result) {
        i = -1;
    }
    for (int i = 0; i < n; i++) {
        temp[i] = inDegree[i];
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        if (q.size() > 1) {
            flag = -1;
        }
        int u = q.front();
        q.pop();
        result[m++] = u;
        for (int i = 0; i < n; i++) {
            if (graph[u][i] == 1) {
                temp[i]--;
                if (temp[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    if (m < n) {
        flag = 0;
    }
    return flag;
}

int main() {
    while (true) {
        int n = 0;
        int m = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                graph[i][j] = 0;
            }
            inDegree[i] = 0;
        }
        bool isFinish = false;
        for (int i = 0; i < m; i++) {
            char left = 0;
            char middle = 0;
            char right = 0;
            cin >> left >> middle >> right;
            if (isFinish) {
                continue;
            }
            graph[left - 'A'][right - 'A'] = 1;
            inDegree[right - 'A']++;
            int flag = topSort(n);
            switch (flag) {
                case 1:
                    cout << "Sorted sequence determined after " << i + 1 << " relations: ";
                    for (int j = 0; j < n; j++) {
                        cout << (char)(result[j] + 'A');
                    }
                    cout << '.' << endl;
                    isFinish = true;
                    break;
                case 0:
                    cout << "Inconsistency found after " << i + 1 << " relations." << endl;
                    isFinish = true;
                    break;
                default:
                    break;
            }
        }
        if (!isFinish) {
            cout << "Sorted sequence cannot be determined." << endl;
        }
    }
    return 0;
}
