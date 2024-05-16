//
// Created by Ignorant on 2024/5/15.
//

#ifndef INC_2024_CPP_LEARNING_5_1_H
#define INC_2024_CPP_LEARNING_5_1_H

#include "vehicle.h"

class Car: virtual public Vehicle {
public:
    Car(string name) : Vehicle(name) {}
    
    void drive() override {
        cout << this->name << " drive on road" << endl;
    }
};

class Boat: virtual public Vehicle {
public:
    Boat(string name) : Vehicle(name) {}
    
    void drive() override {
        cout << this->name << " drive on river" << endl;
    }
};

class AmphibianCar: public Car, public Boat {
public:
    explicit AmphibianCar(string const &name) : Vehicle(name), Car(name), Boat(name) {}
    
    void drive() override {
        cout << this->name << " drive on road or river" << endl;
    }
};

#endif //INC_2024_CPP_LEARNING_5_1_H
