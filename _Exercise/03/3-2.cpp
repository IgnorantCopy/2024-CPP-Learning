//
// Created by Ignorant on 2024/4/3.
//

#include "3-2.h"

Polynomial::Polynomial(const vector<int> &coefficients) {
    coefficients_ = coefficients;
}

Polynomial::Polynomial(const Polynomial &other) {
    this->coefficients_ = other.coefficients_;
}

Polynomial add(const Polynomial &p1, const Polynomial &p2) {
    // TODO
    size_t max = p1.coefficients_.size() < p2.coefficients_.size() ? p2.coefficients_.size() : p1.coefficients_.size();
    vector<int> newCoefficients(max, 0);
    size_t len1 = p1.coefficients_.size();
    size_t len2 = p2.coefficients_.size();
    for (size_t i = 0; i < len1; i++) {
        newCoefficients[max - 1 - i] += p1.coefficients_[len1 - 1 - i];
    }
    for (size_t i = 0; i < len2; i++) {
        newCoefficients[max - 1 - i] += p2.coefficients_[len2 - 1 - i];
    }
    return Polynomial(newCoefficients);
}

Polynomial derivate(const Polynomial &p) {
    // TODO
    size_t len = p.coefficients_.size();
    if (len == 1) {
        return Polynomial({0});
    }
    vector<int> newCoefficient(len - 1);
    for (int i = 0; i < len - 1; i++) {
        newCoefficient[len - 2 - i] = p.coefficients_[len - 2 - i] * (i + 1);
    }
    return Polynomial(newCoefficient);
}

void Polynomial::output() const {
    // TODO
    size_t len = this->coefficients_.size();
    for (int i = 0; i < len; i++) {
        int temp = this->coefficients_[i];
        if (temp != 0) {
            cout << temp << '(' << len - 1 - i << ')' << ' ';
        }
    }
    cout << endl;
}

int main() {
//    Polynomial t({-3, 0});
//    t.output();

//    Polynomial t({9, 8, 7, 6, 5, 4, 3, 2, -9});
//    Polynomial t2({-9, -8, -7, -6, -5, -4, -3, -2, 0});
//    add(t, t2).output();

//    Polynomial t({25, 0, 0, 0, 0, 0, 0, 1});
//    derivate(t).output();
    
    return 0;
};
