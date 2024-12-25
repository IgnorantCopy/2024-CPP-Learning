//
// Created by Ignorant on 2024/10/15.
//

#include <iostream>
using namespace std;

int main() {
    int k = 0;
    int la = 0;
    int lb = 0;
    int ia = 0;
    int ib = 0;
    int fa = 0;
    int fb = 0;
    cin >> k >> la >> lb >> ia >> ib >> fa >> fb;
    int dis = (lb - la + k) % k;
    int step = 0;
    int isVisited[k];
    for (int i = 0; i < k; i++) {
        isVisited[i] = -1;
    }
    if (k % 2 == 0) {
        if (dis % 2 == 0) {
            dis /= 2;
            step = k / 2;
        } else {
            cout << "no answer" << endl;
            return 0;
        }
    } else {
        if (dis % 2 == 0) {
            dis /= 2;
        } else {
            dis = (dis + k) / 2;
        }
        step = k;
    }
    int iter = 0;
    while (++iter < 1000000) {
        int posA = (dis - fa) % ia;
        int posB = (dis - fb) % ib;
        if (posA == 0 && posB == 0) {
            cout << dis << endl;
            return 0;
        }
        dis += step;
        if (isVisited[posA] == posB) {
            break;
        }
        isVisited[posA] = posB;
    }
    cout << "no answer" << endl;
    return 0;
}
