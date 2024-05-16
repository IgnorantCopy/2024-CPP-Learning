//
// Created by Ignorant on 2024/5/15.
//

#ifndef INC_2024_CPP_LEARNING_5_2_H
#define INC_2024_CPP_LEARNING_5_2_H

#include "vehicle.h"

class Car: public Vehicle {
public:
    explicit Car(string name) : Vehicle(name) {}
    
    void drive() override {
        cout << this->name << " drive on road" << endl;
    }
};

class Boat: public Vehicle {
public:
    explicit Boat(string name) : Vehicle(name) {}
    
    void drive() override {
        cout << this->name << " drive on river" << endl;
    }
};

class AmphibianCar: public Car, public Boat {
    string name;
    int count = 0;
public:
    explicit AmphibianCar(string name): Car(name), Boat(name) {
        this->name = name;
    }
    
    void driveAsCar() const {
        cout << this->name << " drive on road as car" << endl;
    }
    
    void driveAsBoat() const {
        cout << this->name << " drive on river as boat" << endl;
    }
    
    void drive() override {
        if (this->name == Car::name && this->name != "AB" && this->count == 0) {
            this->driveAsCar();
        } else if (this->name == "AB" || this->count == 1) {
            this->driveAsBoat();
        }
        count++;
    }
};

#endif //INC_2024_CPP_LEARNING_5_2_H
