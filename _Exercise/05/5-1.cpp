//
// Created by Ignorant on 2024/5/15.
//

#include "5-1.h"
#include <iostream>
using namespace std;

int main() {
    Vehicle *car = new Car("My car");
    Vehicle *boat = new Boat("My boat");
    car->drive();
    boat->drive();
    AmphibianCar *amphibianCar = new AmphibianCar("My amphibian car");
    amphibianCar->drive();
    amphibianCar->Car::drive();
    amphibianCar->Boat::drive();
    
    delete car;
    delete boat;
    delete amphibianCar;
    return 0;
}
