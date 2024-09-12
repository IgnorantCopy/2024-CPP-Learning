//
// Created by Ignorant on 2024/9/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> output;

string remove_str(const string& s, int i) {
    if (i >= 0 && i < s.size()) {
        return s.substr(0, i) + s.substr(i+1);
    }
    return s;
}

void result(const string& s, int n, int count) {
    if (count == n) {
        output.push_back(s);
        return;
    }
    for (int i = count; i < n; i++) {
        string new_s = remove_str(s, i);
        char key = s[i];
        result(key + new_s, n, count + 1);
    }
}

int main() {
    int n = 0;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        s += to_string(i + 1);
    }
    result(s, n, 0);
    // filter
    vector<string> new_output;
    for (auto str : output) {
        bool flag = false;
        for (int j = 0; j < str.length(); j++) {
            if (j < str.length() - 1 && ((str[j] == '1' && str[j + 1] == '2') || (str[j] == '2' && str[j + 1] == '1'))) {
                flag = true;
                break;
            }
        }
        if (flag) {
            new_output.push_back(str);
        }
    }
    // sort
    sort(new_output.begin(), new_output.end());
    // output
    for (const auto &str: new_output) {
        cout << str << endl;
    }
    return 0;
}
