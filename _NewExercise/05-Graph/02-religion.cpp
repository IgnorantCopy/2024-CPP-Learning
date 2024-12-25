//
// Created by Ignorant on 2024/10/15.
//

#include <iostream>
#include <vector>
using namespace std;

int religion[50000] = {0};

int find(int x) {
    if (religion[x] == x) {
        return religion[x];
    }
    return find(religion[x]);
}

void merge(int x, int y, int &result) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    religion[x] = y;
    result--;
}

int main() {
    int count = 1;
    while (true) {
        int n = 0;
        int m = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < 50000; i++) {
            religion[i] = i;
        }
        int result = n;
        for (int i = 0; i < m; i++) {
            int x = 0;
            int y = 0;
            cin >> x >> y;
            merge(x, y, result);
        }
        cout << "Case " << count++ << ": " << result << endl;
    }
    return 0;
}
