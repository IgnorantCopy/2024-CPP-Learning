//
// Created by Ignorant on 2024/3/21.
//

#include <iostream>
using namespace std;

/*
 * To create a class, we use the keyword "class" followed by the class name.
 * class <name> {
 *     <private members except struct and union(public)>
 * public:
 *     <public members>
 * private:
 *     <private members>
 * }
 */

/*
 * 访问控制修饰符
 *  > public: 公有成员，可以在类的外部访问
 *  > private: 私有成员，只能在本类或者友元中访问
 *  > protected: 受保护成员，可以在本类、友元和派生类中访问
 * 注：
 *  友元类：当希望一个类中的成员函数访问另一个类的私有成员时，可以将另一个类声明为友元类。格式为：
 *  class A {
 *  public:
 *      friend class B;
 *  };
 *  但是
 *  ① 友元关系不能被继承。
 *  ② 友元关系不是传递的，如果类C是类B的友元类，而类B是类A的友元类，则类C不一定是类A的友元类。
 *  ③ 友元关系是单向的，如果类A是类B的友元类，则类A不一定是类B的友元。
 */

class Date {
public:
    // 编译器会编译成：Date(Date *const this, int year = 0, int month = 0, int day = 0)
    explicit Date(int year = 0, int month = 0, int day = 0) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    /*
     * const in function:
     * e.g. const int& getYear() const { return year; }
     * first const: year cannot be modified
     * second const: content members cannot be modified
     */
    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    string toString() const {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
private:
    int year;
    int month;
    int day;
};

class Person {
public:
    // default constructor
    Person() {
        name = "";
        age = 0;
        birthday = Date();
        spouse = nullptr;
    }
    // parameterized constructor
    Person(string const& name, int age, Date birthday) {
        this->name = name;
        this->age = age;
        this->birthday = birthday;
    }
    // initializer list constructor
    Person(string const& name, int age, Date birthday, Person *spouse):name(name), age(age), birthday(birthday), spouse(spouse) {
    }
    // copy constructor
    Person(Person const& other) = default;
    /*
     * conditions of the usage of the copy constructor:
     *  ① Use an existed object to create another object.
     *  ② Use as a parameter or return value in a function.
     */
    /*
     * conditions of the usage of the self-defined copy constructor:
     *  > 字符串常量池导致的字符串浅拷贝(会导致不同变量指向同一地址，那么使用析构函数时会释放两次内存，导致程序崩溃)
     *
     */
    
    // destructor(析构函数，类似于Python中的__del__())
    ~Person() {
        cout << "Person destructor called." << endl;
    }
    string toString() const {
        return "Person{name:" + name + ", age:" + to_string(age) + ", birthday:" + birthday.toString() + "}";
    }
    void sing() const;    // statement
    Person getSpouse() const { return *spouse; }
    Date getBirthday() const { return birthday; }
private:
    string name;
    int age;
    Date birthday;
    Person *spouse;     // Person spouse ==> Error: Person is not defined yet.
};

// implementation
void Person::sing() const {
    cout << name << " is singing." << endl;
}

int main() {
    // create a Person object directly
    Person person1("Alice", 25, Date(2000, 1, 1));
    // create a Person object through a pointer
    auto *person2 = new Person("Bob", 30, Date(1995, 6, 15), &person1);
    cout << person2->toString() << endl;
    person1.sing();
    cout << person2->getSpouse().getBirthday().isLeapYear() << endl;
    delete person2;
    
    return 0;
}
