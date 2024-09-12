//
// Created by Ignorant on 2024/4/3.
//

#ifndef INC_2024_CPP_LEARNING_3_2_H
#define INC_2024_CPP_LEARNING_3_2_H

#include <iostream>
#include <vector>
using namespace std;

// ATTENTION: you should not modify any of the following interfaces
class Polynomial {
    friend Polynomial add(const Polynomial &p1, const Polynomial &p2);
    friend Polynomial derivate(const Polynomial &p);

public:
    Polynomial() {}
    
    explicit Polynomial(const vector<int> &coefficients);
    Polynomial(const Polynomial &other);

public:
    void output() const;

private:
    vector<int> coefficients_; // bonus: maybe more efficient index structures?
    // TODO: add any members if you want
};

#endif //INC_2024_CPP_LEARNING_3_2_H
