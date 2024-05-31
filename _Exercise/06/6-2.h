//
// Created by Ignorant on 2024/5/29.
//

#ifndef INC_2024_CPP_LEARNING_6_2_H
#define INC_2024_CPP_LEARNING_6_2_H

#include <vector>
using namespace std;

typedef int (*map_func)(int);
typedef bool (*filter_func)(int);

class Vector {
public:
    Vector(const vector<int> &vec) : vec_(vec) {}
    
    Vector filter(filter_func f) const;
    Vector map(map_func f) const;
    Vector &for_each(map_func f);
    
    void output() const;

private:
    vector<int> vec_;
};

#endif //INC_2024_CPP_LEARNING_6_2_H
