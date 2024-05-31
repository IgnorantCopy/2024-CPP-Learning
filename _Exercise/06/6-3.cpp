//
// Created by Ignorant on 2024/5/29.
//

#include "6-3.h"
#include <iostream>
using namespace std;

int main() {
    MyArray arr1(10);
    auto iterator1 = arr1.begin();
    int v = 0;
    iterator1++;
    iterator1.put(10);
    for (auto iter = arr1.begin(); iter != arr1.end(); iter++) {
        iter.get(v);
        cout << v << " ";
    }
    cout << endl;
    MyArray arr2(10);
    auto iterator2 = arr2.begin();
    iterator2 = arr1.begin() + 1;
    cout << iterator2.get(v) << ", " << v << endl;
    return 0;
}
