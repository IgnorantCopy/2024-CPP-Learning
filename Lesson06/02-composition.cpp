//
// Created by Ignorant on 2024/5/9.
//

#include <iostream>
using namespace std;

/*
 * 组合关系:
 *  > 在组合关系中，被包含的对象随包含它的对象创建和消亡，被包含的对象不能脱离包含它的对象独立存在。
 *  > 实现上，组合类的成员对象一般直接是对象，有时也可以采用对象指针表示，但不管是什么表示形式，成员对象一定是在组合类对象内部
 *          创建并随着组合类对象的消亡而消亡。
 */

class Node {
public:
    int index;
    Node* next = nullptr;
    
    explicit Node(int d) : index(d) {}
};

class LinearList {
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    ~LinearList() {
        Node* current = head;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    virtual int size() const {
        int count = 0;
        Node* current = head;
        while (current!= nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    
    void add(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void remove(int index) {
        Node *current = head;
        Node *previous = nullptr;
        int count = 0;
        while (current!= nullptr && count < index) {
            previous = current;
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Index out of range." << endl;
            return;
        }
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }
    
    int getElement(int index) const {
        Node* current = head;
        int count = 0;
        while (current!= nullptr && count < index) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Index out of range." << endl;
            return -1;
        }
        return current->index;
    }
    
    void setElement(int data, int index) {
        Node* current = head;
        int count = 0;
        while (current!= nullptr && count < index) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Index out of range." << endl;
            return;
        }
        current->index = data;
    }
    
    void insert(int data, int index) {
        int length = size();
        if (index > length) {
            cout << "Index out of range." << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else if (index == length) {
            tail->next = newNode;
            tail = newNode;
        } else {
            Node* current = head->next;
            Node* previous = head;
            int count = 1;
            while (count < index) {
                previous = current;
                current = current->next;
                count++;
            }
            previous->next = newNode;
            newNode->next = current;
        }
    }
};

class Queue: private LinearList {
public:
    void enqueue(int data) {
        add(data);
    }
    
    int dequeue() {
        int data = getElement(0);
        remove(0);
        return data;
    }
    
    int front() const {
        return getElement(0);
    }
    
    bool empty() const {
        return LinearList::size() == 0;
    }
    
    int size() const override {
        return LinearList::size();
    }
};

int main() {
    
    return 0;
}
