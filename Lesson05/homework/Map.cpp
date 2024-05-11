//
// Created by Ignorant on 2024/5/11.
//

#include "Map.h"
#include <iostream>
using namespace std;

Map::Map() = default;

Map::~Map() = default;

bool Map::insert(const string &key, int value) {
    size_t index = hashFunc(key);
    list<pair<string, int>> &bucket = buckets[index];
    for (auto const &i: bucket) {
        if (i.first == key) {
            return false;
        }
    }
    bucket.emplace_back(key, value);
    return true;
}

bool Map::erase(const string &key) {
    size_t index = hashFunc(key);
    list<pair<string, int>> &bucket = buckets[index];
    for (auto i = bucket.begin(); i != bucket.end(); i++) {
        if (i->first == key) {
            bucket.erase(i);
            return true;
        }
    }
    return false;
}

bool Map::find(const string &key) {
    size_t index = hashFunc(key);
    list<pair<string, int>> const &bucket = buckets[index];
    for (auto const &it: bucket) {
        if (it.first == key) {
            return true;
        }
    }
    return false;
}

int &Map::operator[](const string &key) {
    size_t index = hashFunc(key);
    list<pair<string, int>> &bucket = buckets[index];
    for (auto &it: bucket) {
        if (it.first == key) {
            return it.second;
        }
    }
    bucket.emplace_back(key, 0);
    return bucket.back().second;
}

int Map::size() const {
    size_t size = 0;
    for (auto const &bucket: buckets) {
        size += bucket.size();
    }
    return (int)size;
}

int main() {
    Map id2grade;
    id2grade.insert("202200001", 99);
    id2grade.insert("202200002", 98);
    cout << id2grade.size() << endl; // 2
    cout << id2grade.erase("202200002") << endl; // 1(true)
    cout << id2grade.find("202200002") << endl; // 0(false)
    cout << id2grade.erase("202200000") << endl; // 0(false)
    cout << id2grade.size() << endl; // 1
    cout << id2grade["202200001"] << endl; // 99
    cout << id2grade["202200002"] << endl; // 0
    cout << id2grade.find("202200002") << endl; // 1(true)
    cout << id2grade.size() << endl; // 2
    cout << id2grade.insert("202200002", 100) << endl; // 0(false)
    cout << id2grade["202200002"] << endl; // 0
    cout << id2grade.size() << endl; // 2
    id2grade["202200002"] = 95;
    id2grade["DZ00001"] = 100;
    cout << id2grade["202200002"] << endl; // 95
    cout << id2grade["DZ00001"] << endl; // 100
    cout << id2grade.size() << endl; // 3
    return 0;
}
