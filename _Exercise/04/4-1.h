//
// Created by Ignorant on 2024/4/17.
//

#ifndef INC_2024_CPP_LEARNING_4_1_H
#define INC_2024_CPP_LEARNING_4_1_H

// MyList.h
#include<iostream>

// 单向链表实现的队列
class MyList {
private:
    struct Node
    {
        char content;
        Node *next;
    } *head; // 链表的头节点

public:
    MyList();  // 构造函数
    ~MyList(); // 析构函数
    void add(char c);  // 添加新的节点
    void removeNode(char c); // TODO: 移除所有content为c的节点
    void printList(); // 从表头开始顺序打印元素
};

#endif //INC_2024_CPP_LEARNING_4_1_H
