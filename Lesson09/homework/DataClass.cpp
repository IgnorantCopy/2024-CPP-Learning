//
// Created by Ignorant on 2024/6/13.
//

#include "DataClass.h"
#include <iostream>

void test1() {
    std::unordered_map<DataClass, int, DataClassHash> data_map;
    DataClass d({"a", "b"});
    data_map[d]++;
    
    DataClass test({"a", "b"});
    std::cout << data_map[test] << std::endl; // 1
}

void test2() {
    std::unordered_map<DataClass, int, DataClassHash> data_map;
    DataClass d({"a", "b"});
    DataClass d2({"a", "b"});
    data_map[d]++;
    data_map[d2]++;
    
    DataClass test({"a", "b"});
    std::cout << data_map[test] << std::endl; // 2
}

void test3() {
    std::unordered_map<DataClass, int, DataClassHash> data_map;
    DataClass d({"a", "b"});
    DataClass d2({"ab"}); // 请注意，d和d2并不相同！
    data_map[d]++;
    data_map[d2]++;
    
    DataClass test({"a", "b"});
    DataClass test2({"ab"});
    std::cout << data_map[test] << std::endl; // 1
    std::cout << data_map[test2] << std::endl; // 1
}

int main() {
    test3();
    return 0;
}
