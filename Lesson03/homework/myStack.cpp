//
// Created by Ignorant on 2024/3/29.
//

#include "myStack.h"
using namespace std;

// 构造函数
MyStack::MyStack()
{
    // TODO
    top = nullptr;
}

// 析构函数，你需要在这里归还额外申请的资源
MyStack::~MyStack()
{
    // TODO
    Node *ptr = top;
    while (ptr != nullptr) {
        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

// 字符c入栈
void MyStack::push(char c)
{
    // TODO
    Node *ptr = new Node;
    ptr->content = c;
    ptr->next = top;
    top = ptr;
}

// 栈顶元素出栈，返回出栈元素（我们没有定义空栈pop操作，测试用例中不会涉及）
char MyStack::pop()
{
    char result = 0;
    // TODO
    result = top->content;
    Node *temp = top;
    top = top->next;
    delete temp;
    return result;
}

// 返回栈的大小（栈内元素数量）
int MyStack::size()
{
    int result = 0;
    // TODO
    Node *temp = top;
    while (temp != nullptr) {
        temp = temp->next;
        result++;
    }
    return result;
}

int main() {
    MyStack stack;
    stack.push('N');
    stack.push('J');
    stack.push('U');
    cout << stack.size() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.size() << endl;
    return 0;
}
