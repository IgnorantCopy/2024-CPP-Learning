//
// Created by Ignorant on 2024/5/15.
//

#include "5-2.h"
#include <iostream>
using namespace std;

int main() {
    AmphibianCar *amphibianCar = new AmphibianCar("My Amphibian Car");
    Car *car = amphibianCar;
    Boat *boat = amphibianCar;
    car->drive();
    boat->drive();
    
    Vehicle *c = new Car("My Car");
    Vehicle *b = new Boat("My Boat");
    c->drive();
    b->drive();
    amphibianCar->driveAsCar();
    amphibianCar->driveAsBoat();
    
    delete c;
    delete b;
    delete amphibianCar;
    return 0;
}
