//
// Created by Ignorant on 2024/6/12.
//

#ifndef INC_2024_CPP_LEARNING_7_1_H
#define INC_2024_CPP_LEARNING_7_1_H

template<int n> struct fibnacci {
    static constexpr int value = fibnacci<n - 1>::value + fibnacci<n - 2>::value;
};

template<> struct fibnacci<0> {
    static constexpr int value = 0;
};

template<> struct fibnacci<1> {
    static constexpr int value = 1;
};

#endif //INC_2024_CPP_LEARNING_7_1_H
