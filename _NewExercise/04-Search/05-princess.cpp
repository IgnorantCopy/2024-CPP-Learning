//
// Created by Ignorant on 2024/10/9.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ROW = 0;
int COL = 0;
int K = 0;

class Path {
public:
    int r = 0;
    int c = 0;
    int step = 0;
    bool jewel[5] = {0};
    bool isAllowed = false;
    
    Path(int r, int c, int step): r(r), c(c), step(step) {
        for (auto &item: jewel) {
            item = false;
        }
    }
};

int bfs(char **map, vector<pair<int, int>> transits, bool ***isVisited, int sr, int sc) {
    int vectors[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };
    queue<Path> q;
    q.emplace(sr, sc, 0);
    while (!q.empty()) {
        for (auto const &vector : vectors) {
            Path start = q.front();
            start.step++;
            start.r += vector[0];
            start.c += vector[1];
            if (start.r < 0 || start.r >= ROW || start.c < 0 || start.c >= COL) {
                continue;
            }
            if (map[start.r][start.c] == '#') {
                continue;
            }
            if (map[start.r][start.c] >= '0' && map[start.r][start.c] <= '4') {
                start.jewel[map[start.r][start.c] - '0'] = true;
            }
            int jewelType = 0;
            int count = 0;
            for (int j = 0; j < 5; j++) {
                if (start.jewel[j]) {
                    jewelType += 1 << j;
                    count++;
                }
            }
            if (isVisited[start.r][start.c][jewelType]) {
                continue;
            }
            isVisited[start.r][start.c][jewelType] = true;
            if (count >= K) {
                start.isAllowed = true;
            }
            if (map[start.r][start.c] == '$') {
                Path door = start;
                for (const auto &transit: transits) {
                    if (start.r == transit.first && start.c == transit.second) {
                        continue;
                    }
                    door.r = transit.first;
                    door.c = transit.second;
                    q.emplace(door);
                }
            }
            if (map[start.r][start.c] == 'E' && start.isAllowed) {
                return start.step;
            }
            q.emplace(start);
        }
        q.pop();
    }
    return -1;
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        cin >> ROW >> COL >> K;
        int sr = 0;
        int sc = 0;
        auto **map = new char*[ROW];
        vector<pair<int, int>> transits;
        auto ***isVisited = new bool**[ROW];
        for (int i = 0; i < ROW; i++) {
            map[i] = new char[COL];
            isVisited[i] = new bool*[COL];
            for (int j = 0; j < COL; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (map[i][j] == '$') {
                    transits.emplace_back(i, j);
                }
                isVisited[i][j] = new bool[1 << K];
                for (int k = 0; k < 1 << K; k++) {
                    isVisited[i][j][k] = false;
                }
            }
        }
        int result = bfs(map, transits, isVisited, sr, sc);
        if (result == -1) {
            cout << "oop!" << endl;
        } else {
            cout << result << endl;
        }
        for (int i = 0; i < ROW; i++) {
            delete[] map[i];
            for (int j = 0; j < COL; j++) {
                delete[] isVisited[i][j];
            }
            delete[] isVisited[i];
        }
        delete[] map;
        delete[] isVisited;
    }
    return 0;
}
