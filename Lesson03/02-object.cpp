//
// Created by Ignorant on 2024/3/28.
//

#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    static string format; // shared by all objects of the class
    static int numOfObjects;
public:
    Date(int year, int month, int day): year(year), month(month), day(day) {
        numOfObjects++;
    }
    ~Date() {
        numOfObjects--;
    }
    
    // Getter and setter methods
    // const is used to indicate that the method does not modify the object's states.
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    static string getFormat() { return format; }
    static int getNumOfObjects() { return numOfObjects; }
    
    void setYear(int y) { this->year = y; }
    void setMonth(int m) { this->month = m; }
    void setDay(int d) { this->day = d; }
    /*
     * static method:
     *  > can only access static members
     *  > have no concealed 'this'
     */
    static void setFormat(string const& f) { format = f; }
    
    // another function to const
    void print(const Date &date) {
        // cout << date.toString() ==> a const reference object can only use const methods
        cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << endl;
    }
    
    string toString() const {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};

int main() {
    // static members can be accessed without creating an object
    Date::setFormat("%Y-%m-%d");
    return 0;
}
