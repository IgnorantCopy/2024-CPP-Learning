//
// Created by Ignorant on 2024/6/12.
//

#include "7-2.h"

void Class::add_function(const Function &f) {
    this->funcs.push_back(f);
}

void Class::inherit(const Class &c) {
    this->parent = &c;
}

void call(CallSite cs) {
    const Class *clazz = &(cs.base);
    bool isFound = false;
    bool isContinue = true;
    while (nullptr != clazz && isContinue) {
        vector<int> matchFunctions;
        for (const Function &f: clazz->funcs) {
            if (f.name == cs.function_name) {
                int temp = cs.arg.is_ancestor(f.arg);
                if (temp >= 0) {
                    matchFunctions.push_back(temp);
                } else {
                    isContinue = false;
                }
            }
        }
        if (matchFunctions.empty()) {
            clazz = clazz->parent;
            continue;
        }
        int min = matchFunctions[0];
        for (const auto &item: matchFunctions) {
            min = min > item ? item : min;
        }
        if (min == 0) {
            cout << clazz->name << "::" << cs.function_name << "(" << cs.arg.name << ")" << endl;
        } else {
            const Class *temp = &(cs.arg);
            for (int i = 0; i < min; i++) {
                temp = temp->parent;
            }
            cout << clazz->name << "::" << cs.function_name << "(" << temp->name << ")" << endl;
        }
        isFound = true;
        break;
    }
    if (!isFound) {
        cout << "Function not found." << endl;
    }
}

int Class::is_ancestor(const Class &c) const {
    if (this == &c) {
        return 0;
    }
    int count = 0;
    bool isFound = false;
    const Class *clazz = this;
    while (nullptr != clazz) {
        clazz = clazz->parent;
        count++;
        if (clazz == &c) {
            isFound = true;
            break;
        }
    }
    return (isFound ? count : -1);
}

void test1() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    X.add_function({"func", A});
    call({X, "func", A});
}

void test2() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    Class D("D");
    X.add_function({"func", A});
    X.add_function({"funcc", A});
    X.add_function({"func", D});
    call({X, "func", D});
    call({X, "func", A});
    call({X, "funcc", A});
}

void test3() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    X.add_function({"func", A});
    X.add_function({"func", B});
    Class Y("Y");
    Y.add_function({"func", A});
    call({X, "func", A});
    call({X, "func", B});
    call({Y, "func", A});
    call({Y, "func", B});
}

void test4() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    X.add_function({"func", A});
    X.add_function({"func", B});
    call({X, "func", C});
}

void test5() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    Class Y("Y");
    Y.inherit(X);
    Class Z("Z");
    Z.inherit(Y);
    X.add_function({"func", C});
    call({Z, "func", C});
}

void test6() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    X.add_function({"func", A});
    X.add_function({"func", C});
    Class Y("Y");
    Y.inherit(X);
    Y.add_function({"funcc", B});
    call({Y, "func", A});
    call({Y, "func", B});
    call({Y, "func", C});
}

void test7() {
    Class A("A");
    Class B("B");
    B.inherit(A);
    Class C("C");
    C.inherit(B);
    Class X("X");
    Class Y("Y");
    Y.inherit(X);
    Class Z("Z");
    Z.inherit(Y);
    X.add_function({"Y", C});
    call({Z, "Y", C});
}

int main() {
    test7();
    return 0;
}
