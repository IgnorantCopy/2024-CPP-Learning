//
// Created by Ignorant on 2024/5/10.
//

#include "String.h"
#include <cstring>
#include<iostream>
using namespace std;

String::String() {
    this->len = 0;
    this->str_p = new char[1];
    this->str_p[0] = '\0';
}

String::String(const char *s) {
    len = strlen(s);
    this->str_p = new char[this->len + 1];
    strcpy(this->str_p, s);
}

String::String(const String &s) {
    this->len = nullptr == &s ? 0 : s.len;
    this->str_p = new char[this->len + 1];
    strcpy(this->str_p, s.str_p);
}

String::~String() {
    delete[] this->str_p;
    this->str_p = nullptr;
}

void String::print() {
    cout << this->str_p << endl;
}

String &String::operator=(const String &s) {
    if (nullptr == &s) {
        this->len = 0;
        this->str_p = new char[1];
        this->str_p[0] = '\0';
        return *this;
    }
    if (this == &s) {
        return *this;
    }
    delete[] this->str_p;
    this->len = s.len;
    this->str_p = new char[this->len + 1];
    strcpy(this->str_p, s.str_p);
    return *this;
}

String &String::operator=(const char *s) {
    delete[] this->str_p;
    this->len = strlen(s);
    this->str_p = new char[this->len + 1];
    strcpy(this->str_p, s);
    return *this;
}

char &String::operator[](int index) {
    return this->str_p[index];
}

String String::operator+(const String &s) {
    if (nullptr == &s) {
        return *this;
    }
    char *temp = new char[this->len + s.len + 1];
    strcpy(temp, this->str_p);
    strcat(temp, s.str_p);
    String result(temp);
    delete[] temp;
    return result;
}

bool String::operator==(const String &s) const {
    return strcmp(this->str_p, s.str_p) == 0;
}

bool String::operator!=(const String &s) const {
    if (nullptr == &s) {
        return false;
    }
    return strcmp(this->str_p, s.str_p) != 0;
}

bool String::operator<(const String &s) const {
    if (nullptr == &s) {
        return false;
    }
    return strcmp(this->str_p, s.str_p) < 0;
}

int main() {
    String s0;
    s0.print();
    s0 = "abc";
    s0.print();
    String s1(s0);
    s1.print();
    s1.~String();
    s0.print();
    String s2("d");
    s2.print();
    String s3 = s2;
    s2.~String();
    s3.print();
    String s4 = s3 + s3 + s3;
    s4.print();
    cout << (s4 == s3) << endl;
    cout << (s4 != s3) << endl;
    cout << (s4 < s3) << endl;
    return 0;
}
