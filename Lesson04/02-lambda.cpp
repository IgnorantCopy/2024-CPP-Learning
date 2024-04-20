//
// Created by Ignorant on 2024/4/18.
//

#include <iostream>
using namespace std;

int main() {
    /*
     * the format of lambda function: [capture](parameter)->return_type{function_body}
     *  > capture: optional, often used to help compiler to find the variables in the function body
     *      []: empty capture
     *      [var]: capture a variable by value
     *      [&var]: capture a variable by reference
     *      [=]: capture all variables by value (include this)
     *      [&]: capture all variables by reference (include this)
     *      [=, &]: a blend of the above two
     *      [this]: capture this by value (only for member function)
     *      [&, argument, this]: capture by value except for argument and this (only for member function)
     *  > ->return_type is optional
     */
    cout << [](int x){return x * x;}(5) << endl;
    
    return 0;
}
