//
// Created by Ignorant on 2024/5/11.
//

#include "List.h"
using namespace std;

List::List()
{
    head.next = &head;
    head.back = &head;
}

bool List::push_front(const Element &e)
{
    ListNode *newNode = new ListNode(e);
    if (nullptr == newNode) {
        return false;
    }
    if (size_ == 0) {
        head.next = newNode;
        newNode->back = &head;
        head.back = newNode;
        newNode->next = &head;
    } else {
        ListNode *temp = head.next;
        head.next = newNode;
        newNode->back = &head;
        newNode->next = temp;
        temp->back = newNode;
    }
    size_++;
    return true;
}

bool List::push_back(const Element &e)
{
    ListNode *newNode = new ListNode(e);
    if (nullptr == newNode) {
        return false;
    }
    if (size_ == 0) {
        head.next = newNode;
        newNode->back = &head;
        head.back = newNode;
        newNode->next = &head;
    } else {
        ListNode *temp = head.back;
        head.back = newNode;
        newNode->next = &head;
        newNode->back = temp;
        temp->next = newNode;
    }
    size_++;
    return true;
}

bool List::pop_front()
{
    if (size_ == 0) {
        return false;
    }
    ListNode *temp = head.next;
    head.next = temp->next;
    temp->next->back = &head;
    delete temp;
    size_--;
    return true;
}

bool List::pop_back()
{
    if (size_ == 0) {
        return false;
    }
    ListNode *temp = head.back;
    head.back = temp->back;
    temp->back->next = &head;
    delete temp;
    size_--;
    return true;
}

bool List::remove(const Element &e) {
    ListNode *current = head.next;
    bool flag = false;
    while (current != &head) {
        if (current->e == e) {
            ListNode *temp = current;
            current = current->next;
            current->back = temp->back;
            temp->back->next = current;
            delete temp;
            size_--;
            flag = true;
        } else {
            current = current->next;
        }
    }
    return flag;
}

bool List::insert(const Element &e, ListNode *ln)
{
    ListNode *newNode = new ListNode(e);
    if (nullptr == newNode) {
        return false;
    }
    if (nullptr == ln) {
        return false;
    }
    if (ln == &head) {
        push_front(e);
        return true;
    }
    ListNode *temp = ln->next;
    ln->next = newNode;
    newNode->back = ln;
    newNode->next = temp;
    temp->back = newNode;
    size_++;
    return true;
}

void List::erase(ListNode *ln)
{
    if (nullptr == ln || ln == &head) {
        return;
    }
    ListNode *temp = ln->next;
    ln->back->next = temp;
    temp->back = ln->back;
    delete ln;
    size_--;
}

ListNode *List::operator[](size_t i)
{
    if (i >= size_) {
        return nullptr;
    }
    ListNode *current = head.next;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    return current;
}

void List::print()
{
    ListNode *current = head.next;
    while (current != &head) {
        cout << current->e.num << " ";
        current = current->next;
    }
    cout << endl;
}

List::List(const List &l_)
{
    if (nullptr == &l_ || l_.size_ == 0) {
        head.next = &head;
        head.back = &head;
        size_ = 0;
    } else {
        ListNode *current = l_.head.next;
        while (current != &l_.head) {
            push_back(current->e);
            current = current->next;
        }
    }
}

List::~List()
{
    ListNode *current = head.next;
    while (current != &head) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}

void List::operator=(const List &l_)
{
    if (this == &l_) {
        return;
    }
    this->~List();
    if (nullptr == &l_ || l_.size_ == 0) {
        head.next = &head;
        head.back = &head;
        size_ = 0;
    } else {
        ListNode *current_ = l_.head.next;
        while (current_ != &l_.head) {
            push_back(current_->e);
            current_ = current_->next;
        }
    }
}

int main() {
    
    return 0;
}
