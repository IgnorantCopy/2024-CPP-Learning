//
// Created by Ignorant on 2024/5/15.
//

#ifndef INC_2024_CPP_LEARNING_VEHICLE_H
#define INC_2024_CPP_LEARNING_VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string name;
public:
    Vehicle(string name): name(name) {};
    virtual void drive() = 0;
};

#endif //INC_2024_CPP_LEARNING_VEHICLE_H
