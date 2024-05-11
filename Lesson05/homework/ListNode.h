//
// Created by Ignorant on 2024/5/11.
//

#ifndef INC_2024_CPP_LEARNING_LISTNODE_H
#define INC_2024_CPP_LEARNING_LISTNODE_H

struct Element {
    int num;
    bool operator==(const Element& e) const;
};

class ListNode {
    Element e;
    ListNode *next = nullptr;
    ListNode *back = nullptr;
    ListNode();
    ListNode(const Element& e_);
    friend class List;
};

#endif //INC_2024_CPP_LEARNING_LISTNODE_H
