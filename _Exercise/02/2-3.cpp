//
// Created by Ignorant on 2024/3/20.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int k = 0;
    cin >> k;
    auto *nums = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > k) {
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << n << endl;
    }
    delete[] nums;
    return 0;
}
