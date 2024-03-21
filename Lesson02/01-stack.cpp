//
// Created by Ignorant on 2024/3/14.
//

#include <iostream>
using namespace std;

class Stack {
public:
    Stack() {
        Node *p = nullptr;
        top = p;
    }
    void push(int element) {
        auto *p = new Node;
        if (p == nullptr) {
            cout << "StackOverflow!" << endl;
            return;
        }
        p->content = element;
        p->next = top;
        top = p;
    }
    void pop(int &element) {
        if (top != nullptr) {
            Node *p = top;
            element = p->content;
            top = top->next;
            delete p;
        }
    }
private:
    struct Node {
        int content;
        Node *next;
    } *top;
};

int main() {
    Stack stack;
    stack.push(12);
    stack.push(6);
    stack.push(4);
    int element = 0;
    stack.pop(element);
    cout << element << endl;
    stack.push(3);
    stack.pop(element);
    cout << element << endl;
    stack.pop(element);
    cout << element << endl;
    stack.pop(element);
    cout << element << endl;
    stack.pop(element);
    cout << element << endl;
    return 0;
}
