//
// Created by Ignorant on 2024/10/15.
//

#include <iostream>
#include <vector>
using namespace std;

int nodes[26] = {0};

int main() {
    while (true) {
        int n = 0;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int & node : nodes) {
            node = 10000;
        }
        // create graph
        int graph[26][26] = {0};
        for (int i = 0; i < n - 1; i++) {
            char from = 0;
            int m = 0;
            cin >> from >> m;
            for (int j = 0; j < m; j++) {
                char to = 0;
                int cost = 0;
                cin >> to >> cost;
                graph[from - 'A'][to - 'A'] = cost;
                graph[to - 'A'][from - 'A'] = cost;
            }
        }
        // solve
        int result = 0;
        char start = 'A';
        for (int i = 0; i < n - 1; i++) {
            nodes[start - 'A'] = 0;
            int min_cost = 10000;
            char next = 0;
            for (int j = 0; j < n; j++) {
                if (graph[start - 'A'][j] != 0 && nodes[j] != 0) {
                    int cost = graph[start - 'A'][j];
                    nodes[j] = min(nodes[j], cost);
                }
            }
            for (int j = 0; j < n; j++) {
                int cost = nodes[j];
                if (cost != 0 && cost < min_cost) {
                    min_cost = cost;
                    next = j + 'A';
                }
            }
            result += min_cost;
            start = next;
        }
        cout << result << endl;
    }
    return 0;
}
