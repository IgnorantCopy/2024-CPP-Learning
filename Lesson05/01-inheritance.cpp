//
// Created by Ignorant on 2024/4/25.
//

#include <iostream>
using namespace std;

/*
 * Inheritance:
 *  1. related concepts:
 *      > base class: the class from which the new class is derived
 *      > derived class: the new class that inherits from the base class
 *  2. categories of inheritance:
 *      > multiple inheritance: a derived class inheriting from more than one base class
 *      > single inheritance: a derived class inheriting from only one base class
 *  3. syntax:
 *      class <ClassName>:[<inheritance limit>]<name of base class> {
 *          <members>
 *      };
 *      <inheritance limit> can be "public", "private", or "protected". (private if default)
 *      _____________________________________________________________
 *      | inheritance limit \ members   public  protected   private |
 *      | public                        public  protected      ×    |
 *      | protected                   protected protected      ×    |
 *      | private                      private   private       ×    |
 *      -------------------------------------------------------------
 */

// single inheritance
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
    
    void eat() const {
        cout << "Animal is eating." << endl;
    }
    
    virtual void sleep() const {
        cout << "Animal is sleeping." << endl;
    }
    
    virtual ~Animal() = default;
protected:
    int id; // protected member: can be accessed by derived classes, but not by the object of the base class
};

class Person: public Animal {
    string name;
    string gender;
public:
    Person() = default;
    Person(string const& name, string const& gender, int age, double weight):
        Animal(age, weight), name(name), gender(gender) {}
        
    string getName() const { return name; }
    string getGender() const { return gender; }
    void setName(string const& name) { this->name = name; }
    void setGender(string const& gender) { this->gender = gender; }
};

class Pet: public Animal {
    string name;
    Person owner;
public:
    Pet() = default;
    Pet(string const& name, Person const& owner, int age, double weight):
        Animal(age, weight), name(name), owner(owner) {}
        
    string getName() const { return name; }
    Person const& getOwner() const { return owner; }
    void setName(string const& name) { this->name = name; }
    void setOwner(Person const& owner) { this->owner = owner; }
    
    void walk() const {
        cout << name << " is walking by " << owner.getName() << endl;
    }
};

class Cat: public Pet {
    string color;
public:
    Cat() = default;
    Cat(string const& name, Person const& owner, int age, double weight, string const& color):
        Pet(name, owner, age, weight), color(color) {}
        
    string getColor() const { return color; }
    void setColor(string const& color) { this->color = color; }
    
    void meow() const {
        cout << "The " << color << " " << getName() << " is meowing." << endl;
    }
    
    // eat() in Animal is hidden by eat() in Cat
    void eat() const {
        cout << "The " << color << " " << getName() << " is eating." << endl;
    }
    
    // use virtual to override sleep() in Animal
    void sleep() const override {
        cout << "The " << color << " " << getName() << " is sleeping." << endl;
    }
};

/*
 * multiple inheritance:
 * It is allowed in C++ but not recommended. Because it will cause several problems:
 *  1. name conflicts: if two base classes have members with the same name, the derived class will must
 *      explicitly specify which base class's member to use.
 *  2. repeat inheritance: the base classes inheriting from the same base class will cause the derived
 *      class to inherit the same member multiple times, which can cause ambiguity and confusion. So,
 *      we should add a virtual keyword to the member function to avoid this problem, which is called
 *      virtual base class.
 *
 */

int main() {
    
    return 0;
}
