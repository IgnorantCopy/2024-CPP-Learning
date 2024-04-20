//
// Created by Ignorant on 2024/3/29.
//

#include "myQueue.h"
#include <iostream>
using namespace std;

MyQueue::MyQueue()
{
    // TODO
    head = nullptr;
    tail = nullptr;
}

MyQueue::~MyQueue()
{
    // TODO
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// 元素从队尾入队
void MyQueue::push(char c)
{
    // TODO
    Node *ptr = new Node;
    ptr->content = c;
    ptr->next = nullptr;
    if (head == nullptr) {
        head = ptr;
    } else {
        tail->next = ptr;
    }
    tail = ptr;
}

// 队首元素出队，返回出队的元素（我们没有定义空队列pop操作，测试用例中不会涉及）
char MyQueue::pop()
{
    char result;
    // TODO
    result = head->content;
    Node *temp = head;
    head = head->next;
    delete temp;
    return result;
}

// 返回队列的大小（队列内元素的个数）
int MyQueue::size()
{
    int result = 0;
    // TODO
    Node *temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        result++;
    }
    return result;
}

int main() {
    MyQueue queue;
    queue.push('N');
    queue.push('J');
    queue.push('U');
    cout << queue.size() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.size() << endl;
    return 0;
}
