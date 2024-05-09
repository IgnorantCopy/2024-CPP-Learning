//
// Created by Ignorant on 2024/4/28.
//

#include <iostream>
using namespace std;

class Animal {
    int age;
    double weight;
public:
    Animal():age(0), weight(0.0) {}
    Animal(int age, double weight): age(age), weight(weight) {}
    
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    void setAge(int age) { this->age = age; }
    void setWeight(double weight) { this->weight = weight; }
    
    /*
     * virtual function
     *  1. functions of virtual function
     *      > indicate dynamic binding
     *      > can be overridden by derived classes
     *  2. when to use virtual function
     *      > to have a default implementation for a function in the base class
     *      > to have a specific implementation for a function in a derived class
     *      > when the specific implementation is not certain in the base class
     */
    virtual void eat() const {
        cout << "Animal is eating." << endl;
    }
    
    virtual void sleep() const {
        cout << "Animal is sleeping." << endl;
    }
    
    virtual ~Animal() = default;
};

class Cat: public Animal {
    string color;
    string name;
public:
    Cat() = default;
    Cat(int age, double weight, string const& color, string const& name):
            Animal(age, weight), color(color), name(name) {}
    
    string getColor() const { return color; }
    void setColor(string const& color) { this->color = color; }
    string getName() const { return name; }
    void setName(string const& name) { this->name = name; }
    
    void eat() const override {
        cout << "The " << color << " " << getName() << " is eating." << endl;
    }
    
    void sleep() const override {
        cout << "The " << color << " " << getName() << " is sleeping." << endl;
    }
    
    void meow() const {
        cout << "The " << color << " " << getName() << " is meowing." << endl;
    }
};

class Dog: public Animal {
    string name;
    string variety;
public:
    Dog() = default;
    Dog(int age, double weight, string const& name, string const& variety):
            Animal(age, weight), name(name), variety(variety) {}
    
    string getName() const { return name; }
    void setName(string const& name) { this->name = name; }
    string getVariety() const { return variety; }
    void setVariety(string const& variety) { this->variety = variety; }
    
    void eat() const override {
        cout << "The " << getName() << " is eating." << endl;
    }
    
    void sleep() const override {
        cout << "The " << getName() << " is sleeping." << endl;
    }
    
    void bark() const {
        cout << "The " << getName() << " is barking." << endl;
    }
};

class Person {
    string name;
    int age;
    Animal *pet;
public:
    Person() = default;
    Person(string const& name, int age, Animal *pet):
            name(name), age(age), pet(pet) {}
    
    string getName() const { return name; }
    void setName(string const& name) { this->name = name; }
    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }
    Animal *getPet() const { return pet; }
    void setPet(Animal *pet) { this->pet = pet; }
    
    void feed() const {
        cout << name << " is feeding the " << pet->getAge() << "-years-old pet." << endl;
        pet->eat();
    }
};

int main() {
    Dog dog(3, 5.0, "Buddy", "Labrador");
    Person person("Jack", 25, &dog);
    person.feed();
    Cat cat(1, 2.0, "white", "Tom");
    person.setPet(&cat);
    person.feed();
    return 0;
}
