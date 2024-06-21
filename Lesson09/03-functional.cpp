//
// Created by Ignorant on 2024/6/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

/*
 * functional programming
 */

// 1. recursion and tail recursion
string reverse(string s) {
    if (s.length() == 1) {
        return s;
    }
    return reverse(s.substr(1, s.length() - 1)) + s[0];
}

void reverseTest() {
    string s = "hello world";
    cout << reverse(s) << endl;
}

int fibonacci(int n, int a, int b) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        return fibonacci(n - 1, b, a + b);
    }
}

/*
 * benefits of tail recursion:
 *  1. save space on the call stack
 *  2. can be transformed into loops
 */

void fibonacciTest() {
    cout << fibonacci(10, 0, 1) << endl;
}

// 2. filter
void filterTest() {
    vector<int> numbers = {1, -2, 7, 0, 3};
    vector<int> positives;
    copy_if(numbers.begin(), numbers.end(), back_inserter(positives),
            [](int n) { return n > 0; });
    for_each(positives.begin(), positives.end(), [](int n) { cout << n << " "; });
}

// 3. map
void mapTest() {
    vector<int> numbers = {1, -2, 7, 0, 3};
    vector<int> squares;
    transform(numbers.begin(), numbers.end(), back_inserter(squares),
              [](int n) { return n * n; });
    for_each(squares.begin(), squares.end(), [](int n) { cout << n << " "; });
}

// 4. reduce
void reduceTest() {
    vector<int> numbers = {1, -2, 7, 0, 3};
    int sum = accumulate(numbers.begin(), numbers.end(), 0,
                         [](int a, int b) { return a + b; });
    cout << sum << endl;
}

// 5. partial function application
void print(int n, int base) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % base);
        n = n / base;
    }
    for_each(digits.rbegin(), digits.rend(), [](int d) { cout << d; });
    cout << endl;
}

auto print10 = [](int n) { return print(n, 10); };
// or through bind
const auto print10_ = bind(print, placeholders::_1, 10);

void printTest() {
    print10(12345);
    print10_(6789);
}

// 6. currying
int add(int a, int b) { return a + b;}

auto add_cd(int x) {
    return [x](int y) { return add(x, y); };
}

void addTest() {
    cout << add_cd(2)(3) << endl;
    auto add1 = add_cd(1);
    auto add10 = add_cd(10);
    int a = 0;
    cout << add1(a) << endl;
    cout << add10(a) << endl;
}

/*
 * differences between partial function application and currying:
 *  1. partial function application: takes a fixed number of arguments, returns a function that takes the remaining arguments,
 *      and the order of the arguments is flexible.
 *  2. currying: takes a function that takes multiple arguments and returns it to a chain of functions that take one argument at a time,
 *      and the order of the arguments is fixed one by one.
 */

int main() {
    addTest();
    return 0;
}
