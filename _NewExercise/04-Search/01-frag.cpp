//
// Created by Ignorant on 2024/10/8.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[5000][5000] = {0};

class Position {
public:
    int r;
    int c;
    
    Position(int r, int c): r(r), c(c) {}
    
    bool operator<(const Position& other) const {
        if (r != other.r) {
            return r < other.r;
        } else {
            return c < other.c;
        }
    }
};

int main() {
    int row = 0;
    int col = 0;
    cin >> row >> col;
    int n = 0;
    cin >> n;
    vector<Position> position(n, Position(0, 0));
    for (int i = 0; i < n; i++) {
        int r = 0;
        int c = 0;
        cin >> r >> c;
        position[i].r = r - 1;
        position[i].c = c - 1;
        arr[r - 1][c - 1] = 1;
    }
    int maximum = 2;
    sort(position.begin(), position.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int gapR = position[j].r - position[i].r;
            int gapC = position[j].c - position[i].c;
            if (gapR == 0 && gapC == 0) {
                continue;
            }
            if (position[i].r - gapR >= 0 && position[i].c - gapC >= 0 &&
                position[i].r - gapR < row && position[i].c - gapC < col) {
                continue;
            }
            if (position[i].r + (maximum - 1) * gapR >= row || position[i].c + (maximum - 1) * gapC >= col ||
                position[i].r + (maximum - 1) * gapR < 0 || position[i].c + (maximum - 1) * gapC < 0) {
                continue;
            }
            int count = 2;
            int r = position[j].r + gapR;
            int c = position[j].c + gapC;
            while (r >= 0 && c >= 0 && r < row && c < col) {
                if (arr[r][c] == 1) {
                    count++;
                    r += gapR;
                    c += gapC;
                } else {
                    count = 2;
                    break;
                }
            }
            if (count > 2) {
                maximum = max(maximum, count);
            }
        }
    }
    if (maximum == 2) {
        cout << 0 << endl;
    } else {
        cout << maximum << endl;
    }
    return 0;
}
