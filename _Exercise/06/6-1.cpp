//
// Created by Ignorant on 2024/5/29.
//

#include "6-1.h"
#include <iomanip>
ostream & operator<<(ostream & out, const BaseCalculator* cal) {
    // write your code here......
    out << cal->oss.str();
    return out;
}

void AddCalculator::calculate(double a, double b) {
    double temp = a + b;
    oss << fixed << setprecision(2) << temp << endl;
}

void SubCalculator::calculate(double a, double b) {
    double temp = a - b;
    oss << fixed << setprecision(2) << temp << endl;
}

int main() {
    BaseCalculator* cal1 = new AddCalculator();
    BaseCalculator* cal2 = new SubCalculator();
    cal2->calculate(11.4, 51.4);
    cout << cal2;
    cal1->calculate(23.33, 15.51);
    cal1->calculate(3.14159, 2.71828);
    cout << cal1;
    cal2->calculate(834047409, 510756141);
    cout << cal2;
    delete cal1;
    delete cal2;
    return 0;
}
