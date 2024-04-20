//
// Created by Ignorant on 2024/4/3.
//

#include "3-1.h"
using namespace std;

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    pointer = sptr.pointer;
    if (sptr.ref_cnt == nullptr) {
        ref_cnt = nullptr;
    } else {
        *(sptr.ref_cnt) = *(sptr.ref_cnt) + 1;
        ref_cnt = sptr.ref_cnt;
    }
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if (sptr.ref_cnt == ref_cnt) {
        return;
    }
    this->~SmartPointer();
    pointer = sptr.pointer;
    if (sptr.ref_cnt == nullptr) {
        ref_cnt = nullptr;
    } else {
        *(sptr.ref_cnt) = *(sptr.ref_cnt) + 1;
        ref_cnt = sptr.ref_cnt;
    }
}

SmartPointer::~SmartPointer()
{
    if (ref_cnt != nullptr) {
        *ref_cnt = *ref_cnt - 1;
        if (*ref_cnt == 0) {
            delete pointer;
            delete ref_cnt;
        }
    }
}

int main() {
//    SmartPointer sp1(new Node(1));
//    SmartPointer *sp2 = new SmartPointer(sp1);

//    SmartPointer sp1(new Node(123));
//    sp1.~SmartPointer();
//    sp1.assign(SmartPointer());
//    sp1.assign(*(new SmartPointer(new Node(456))));

    SmartPointer sp1(new Node(1));
    SmartPointer sp2(sp1);
    sp1.assign(sp2);
    return 0;
}
