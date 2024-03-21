//
// Created by Ignorant on 2024/2/29.
//
#include <iostream>
using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

// 5.default value
void print(int num = 0) {
    cout << num << endl;
}

// 8.reload
void print(double num) {
    cout << num << endl;
}

int main() {
    // 1.initialize:
    int x = 0;
    int y(0);
    // 2.bool:
    bool flag = true;
    // 3.safe stdio
    cout << x << endl << flag << endl;
    // 4.inline function
    cout << max(x, y) << endl;
    
    print();
    print(5);
    
    // 6. new / delete
    // 7.automatic type inference
    auto *nums = new int[5];    // malloc
    for (int i = 0; i < 5; i++) {
        print(nums[i]);
    }
    delete nums;
    // 9.foreach
    double nums2[] = {1.2, 3.4, 5.5, 556.214, 3.14159};
    for (const auto &i: nums2) {
        print(i);
    }
    return 0;
}
