//
// Created by Ignorant on 2024/5/29.
//

#ifndef INC_2024_CPP_LEARNING_6_1_H
#define INC_2024_CPP_LEARNING_6_1_H

#include <iostream>
#include <sstream>
using namespace std;

class BaseCalculator {
protected:
public:
    ostringstream oss;
    virtual void calculate(double, double){}
    friend ostream &operator<<(ostream &, const BaseCalculator*);
};

// 加法计算器类
class AddCalculator : public BaseCalculator {
    void calculate(double, double);
};

// 减法计算器类
class SubCalculator : public BaseCalculator {
    void calculate(double, double);
};


#endif //INC_2024_CPP_LEARNING_6_1_H
