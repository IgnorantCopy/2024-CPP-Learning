//
// Created by Ignorant on 2024/9/24.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str1;
        string str2;
        cin >> str1 >> str2;
        size_t len1 = str1.length();
        size_t len2 = str2.length();
        int **distance = new int*[len1 + 1];
        for (int j = 0; j < len1 + 1; j++) {
            distance[j] = new int[len2 + 1];
        }
        for (int j = 0; j < len1 + 1; j++) {
            for (int k = 0; k < len2 + 1; k++) {
                if (j == 0) {
                    distance[j][k] = k;
                } else if (k == 0) {
                    distance[j][k] = j;
                } else if (str1[j - 1] == str2[k - 1]) {
                    distance[j][k] = min(min(distance[j - 1][k] + 1, distance[j][k - 1] + 1), distance[j - 1][k - 1]);
                } else{
                    distance[j][k] = 1 + min(min(distance[j - 1][k], distance[j][k - 1]), distance[j - 1][k - 1]);
                }
            }
        }
        cout << distance[len1][len2] << endl;
        for (int j = 0; j < len1 + 1; j++) {
            delete[] distance[j];
        }
        delete[] distance;
    }
    
    return 0;
}
