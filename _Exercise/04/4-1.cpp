//
// Created by Ignorant on 2024/4/17.
//

#include "4-1.h"
using namespace std;

// 构造函数
MyList::MyList()
{
    head = NULL;
}

// 析构函数
MyList::~MyList()
{
    while (head != NULL)
    {
        Node *n = head;
        head = head->next;
        delete n;
    }
}

// 添加新的节点
void MyList::add(char c)
{
    Node *n = new Node;
    if (n == NULL)
    {
        cout << "Overflow\n";
        exit(-1);
    }
    else {
        n->content = c;
        n->next = NULL;
        if (head == NULL) {
            head = n;
        }
        else {
            Node *tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = n;
        }
    }
}

/* TODO:
 * 移除所有content等于c的节点，没有则不移除
 * 确保 head 仍是新链表的头部，且未删除节点的顺序保持一致
 * 输出移除的节点数量(number)
 */
void MyList::removeNode(char c)
{
    int number = 0;
    /* TODO */
    while (head != nullptr && head->content == c) {
        number++;
        Node *temp = head->next;
        delete head;
        head = temp;
    }
    Node *ptr = head;
    while (ptr != nullptr && ptr->next != nullptr) {
        if (ptr->next->content == c) {
            number++;
            Node *temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        } else {
            ptr = ptr->next;
        }
    }
    /* TODO END */
    cout << number << endl;
}

// 从表头开始按加入顺序打印元素
void MyList::printList()
{
    Node* n = head;
    while (n != NULL)
    {
        cout << n->content << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    MyList myList;
    myList.add('N');
    myList.add('N');
    myList.add('J');
    myList.add('J');
    myList.add('U');
    myList.add('U');
    myList.removeNode('O');
    myList.printList();
    return 0;
}
