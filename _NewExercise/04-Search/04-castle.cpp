//
// Created by Ignorant on 2024/10/9.
//

#include <iostream>
#include <queue>
using namespace std;

int walls[50][50][4] = {0};     // west, north, east, south
bool isVisited[50][50] = {0};
int vectors[4][2] = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0}
};
int ROW = 0;
int COL = 0;

int bfs(int row, int col) {
    if (isVisited[row][col]) {
        return 0;
    }
    queue<pair<int, int>> q;
    q.emplace(row, col);
    isVisited[row][col] = true;
    int count = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newR = r + vectors[i][0];
            int newC = c + vectors[i][1];
            if (newR < 0 || newR >= ROW || newC < 0 || newC >= COL) {
                continue;
            }
            if (isVisited[newR][newC]) {
                continue;
            }
            if (walls[r][c][i]) {
                continue;
            }
            isVisited[newR][newC] = true;
            q.emplace(newR, newC);
            count++;
        }
    }
    return count;
}

int main() {
    cin >> ROW >> COL;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int temp = 0;
            cin >> temp;
            int index = 0;
            for (int k = temp; k > 0; k /= 2) {
                walls[i][j][index++] = k % 2;
            }
        }
    }
    int numOfRooms = 0;
    int maximum = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int count = bfs(i, j);
            if (count) {
                numOfRooms++;
                maximum = max(maximum, count);
            }
        }
    }
    cout << numOfRooms << endl << maximum << endl;
    return 0;
}
