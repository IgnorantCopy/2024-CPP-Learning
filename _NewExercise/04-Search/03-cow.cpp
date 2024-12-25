//
// Created by Ignorant on 2024/10/9.
//

#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

int main() {
    int n = 0;
    int k = 0;
    cin >> n >> k;
    if (n >= k) {
        cout << n - k << endl;
        return 0;
    }
    queue<int> q;
    q.push(n);
    int layers[MAX + 1] = {0};
    for (auto &item: layers) {
        item = -1;
    }
    layers[n] = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == k) {
            break;
        }
        int directions[3] = {current - 1, current + 1, current * 2};
        for (int direction : directions) {
            if (direction >= 0 && direction <= MAX && layers[direction] == -1) {
                q.push(direction);
                layers[direction] = layers[current] + 1;
            }
        }
    }
    cout << layers[k] << endl;
    return 0;
}
