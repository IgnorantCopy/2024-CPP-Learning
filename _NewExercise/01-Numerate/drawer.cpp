//
// Created by Ignorant on 2024/9/3.
//

#include <iostream>
using namespace std;

int pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * pow(a, b - 1);
}

bool judge(int **wall, int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (wall[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

string binary(int num, int length) {
    string result;
    while (num > 0) {
        result = (num % 2 == 0 ? "0" : "1") + result;
        num /= 2;
    }
    while (result.length() < length) {
        result = "0" + result;
    }
    return result;
}

void changeWall(int **wall, int n, int x, int y) {
    int vector[5][2] = {
            {x, y},
            {x - 1, y},
            {x + 1, y},
            {x, y - 1},
            {x, y + 1}
    };
    for (auto const &i : vector) {
        int newX = i[0];
        int newY = i[1];
        if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
            wall[newX][newY] = 1 - wall[newX][newY];
        }
    }
}

int solve(int n, int **wall) {
    int times = pow(2, n);
    auto *results = new int[times];
    int length = 0;
    auto **newWall = new int*[n];
    for (int i = 0; i < n; i++) {
        newWall[i] = new int[n];
    }
    for (int i = 0; i < times; i++) {
        string binaryStr = binary(i, n);
        int result = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                newWall[j][k] = wall[j][k];
            }
        }
        for (int j = 0; j < binaryStr.length(); j++) {
            if (binaryStr[j] == '1') {
                changeWall(newWall, n, 0, j);
                result++;
            }
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (newWall[j - 1][k] == 0) {
                    changeWall(newWall, n, j, k);
                    result++;
                }
            }
        }
        if (judge(newWall, n)) {
            results[length++] = result;
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] newWall[i];
    }
    delete[] newWall;
    if (length == 0) {
        delete[] results;
        return -1;
    }
    int minResult = results[0];
    for (int i = 1; i < length; i++) {
        if (results[i] < minResult) {
            minResult = results[i];
        }
    }
    delete[] results;
    return minResult;
}

int main() {
    int n = 0;
    cin >> n;
    auto **wall = new int*[n];
    for (int i = 0; i < n; i++) {
        wall[i] = new int[n];
        for (int j = 0; j < n; j++) {
            char key = 0;
            cin >> key;
            wall[i][j] = (key == 'w') ? 0 : 1;
        }
    }
    int result = solve(n, wall);
    if (result == -1) {
        cout << "inf" << endl;
    } else {
        cout << result << endl;
    }
    for (int i = 0; i < n; i++) {
        delete[] wall[i];
    }
    delete[] wall;
    return 0;
}
