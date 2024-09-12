//
// Created by Ignorant on 2024/9/10.
//

#include <iostream>
#include <valarray>
#define N 8
using namespace std;

int values[15][N][N][N][N] = {0};
int sum[N][N] = {0};

int get_sum(int x1, int y1, int x2, int y2) {
    if (x1 == 0 && y1 == 0) {
        return sum[x2][y2];
    } else if (x1 == 0) {
        return sum[x2][y2] - sum[x2][y1 - 1];
    } else if (y1 == 0) {
        return sum[x2][y2] - sum[x1 - 1][y2];
    }
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int square_sum(int n, int x1, int y1, int x2, int y2) {
    int &value = values[n][x1][y1][x2][y2];
    if (value) {
        return value;
    }
    if (n == 1) {
        int temp = get_sum(x1, y1, x2, y2);
        return temp * temp;
    }
    value = 2000000000;
    for (int i = x1; i < x2; i++) {
        value = min(value, square_sum(n - 1, x1, y1, i, y2) + square_sum(1, i + 1, y1, x2, y2));
        value = min(value, square_sum(1, x1, y1, i, y2) + square_sum(n - 1, i + 1, y1, x2, y2));
    }
    for (int i = y1; i < y2; i++) {
        value = min(value, square_sum(n - 1, x1, y1, x2, i) + square_sum(1, x1, i + 1, x2, y2));
        value = min(value, square_sum(1, x1, y1, x2, i) + square_sum(n - 1, x1, i + 1, x2, y2));
    }
    return value;
}

int main() {
    int n = 0;
    cin >> n;
    int chess_sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp = 0;
            cin >> temp;
            chess_sum += temp;
            if (i == 0 && j == 0) {
                sum[i][j] = temp;
            } else if (i == 0) {
                sum[i][j] = sum[i][j - 1] + temp;
            } else if (j == 0) {
                sum[i][j] = sum[i - 1][j] + temp;
            } else {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + temp;
            }
        }
    }
    double average = (double)chess_sum / n;
    int min_square_sum = square_sum(n, 0, 0, N - 1, N - 1);
    double sigma = sqrt((min_square_sum - n * average * average) / n);
    printf("%.3f", sigma);
    return 0;
}
