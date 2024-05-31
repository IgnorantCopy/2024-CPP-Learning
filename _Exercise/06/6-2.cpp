//
// Created by Ignorant on 2024/5/29.
//

#include "6-2.h"
#include <iostream>

Vector Vector::map(map_func f) const {
    // TODO
    vector<int> new_vec;
    new_vec.reserve(vec_.size());
    for (int i : vec_) {
        new_vec.push_back(f(i));
    }
    return {new_vec};
}

Vector Vector::filter(filter_func f) const {
    // TODO
    vector<int> new_vec;
    for (int i : vec_) {
        if (f(i)) {
            new_vec.push_back(i);
        }
    }
    return {new_vec};
}

Vector &Vector::for_each(map_func f) {
    // TODO
    for (int &i : vec_) {
        i = f(i);
    }
    return *this;
}

void Vector::output() const {
    // TODO
    for (int i : vec_) {
        cout << i << " ";
    }
    cout << endl;
}

int neg(int x) { return -x; }

bool is_neg(int x) { return x < 0; }

int main() {
//    Vector foo({-1, 0, 1});
//    foo.map(neg).output();
//    foo.output();
    
//    Vector foo({-1, -2, 0, 1, 3});
//    foo.map(neg).filter(is_neg).output();
//    foo.filter(is_neg).output();
    
    Vector foo({-1, -2, 0, 1, 3});
    foo.for_each(neg).filter(is_neg).output();
    foo.output();
    
    return 0;
}
