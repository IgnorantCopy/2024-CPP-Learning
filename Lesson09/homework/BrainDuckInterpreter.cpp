//
// Created by Ignorant on 2024/6/13.
//

#include "BrainDuckInterpreter.h"
using namespace std;

// +
int IncrementInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    char key = vm.getCurrentTape();
    key++;
    vm.setCurrentTape(key);
    return 1;
}

// -
int DecrementInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    char key = vm.getCurrentTape();
    key--;
    vm.setCurrentTape(key);
    return 1;
}

// <
int MoveLeftInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    vm.decreaseTapeIndex();
    return 1;
}

// >
int MoveRightInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    vm.increaseTapeIndex();
    return 1;
}

// [
int LoopBeginInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    if (vm.getCurrentTape() != 0) {
        return 1;
    }
    stack<char> loopStack;
    string program = vm.getProgram();
    size_t programCount = vm.getProgramCount();
    size_t record = programCount;
    loopStack.push(program[programCount]);
    while (!loopStack.empty()) {
        programCount++;
        switch (program[programCount]) {
            case '[':
                loopStack.push(program[programCount]);
                break;
            case ']':
                loopStack.pop();
                break;
            default:
                break;
        }
    }
    return (int)(programCount - record + 1);
}

// ]
int LoopEndInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    if (vm.getCurrentTape() == 0) {
        return 1;
    }
    stack<char> loopStack;
    string program = vm.getProgram();
    size_t programCount = vm.getProgramCount();
    size_t record = programCount;
    loopStack.push(program[programCount]);
    while (!loopStack.empty()) {
        programCount--;
        switch (program[programCount]) {
            case '[':
                loopStack.pop();
                break;
            case ']':
                loopStack.push(program[programCount]);
                break;
            default:
                break;
        }
    }
    return (int)(programCount - record + 1);
}

// ,
int InputInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    char key;
    ss >> key;
    vm.setCurrentTape(key);
    return 1;
}

// .
int OutputInstruction::execute(std::istream &ss, BrainDuckVM &vm) {
    // Your code here
    char key = vm.getCurrentTape();
    cout << key;
    return 1;
}

void test1() {
    BrainDuckVM vm;
    vm.init(",.,.,."); // 读取一个字符到当前tape_index位置，输出当前tape_index位置元素
    std::stringstream test("NJU");
    vm.executeProgram(test);
    // 输出：NJU
}

void test2() {
    BrainDuckVM vm;
    vm.init(",>,>,.<.<."); // 输入两个元素到tape数组的前两个位置，并逆序打印这两个字符
    std::stringstream test("UJN");
    vm.executeProgram(test);
    // 输出：NJU
}

void test3() {
    BrainDuckVM vm;
    vm.init("+,++-.-."); // 输入一个字符，输出该字符增1之后的字符以及原本的字符
    std::stringstream test("S");
    vm.executeProgram(test);
    // 输出：TS
}

void test4() {
    BrainDuckVM vm;
    vm.init(",[.,]"); // 不断输入并输出，直至输入\0
    std::stringstream test("BrainDuck\0");
    vm.executeProgram(test);
    // 输出：BrainDuck
}

void test5() {
    BrainDuckVM vm;
    vm.init(",[.,>[.,]<]"); // 不断输入并输出，直至输入\0,内部的循环应该永远不会被执行
    std::stringstream test("QuarkQuark\0");
    vm.executeProgram(test);
    // 输出：QuarkQuark
}

void test6() {
    BrainDuckVM vm;
    vm.init(",.,[.>+[<.>-],]"); // 不断输入并输出,输出第一个字符一次，其后的每个字符两次，直至输入\0
    std::stringstream test("C+\0");
    vm.executeProgram(test);
    // 输出：C++
}

void test7() {
    BrainDuckVM vm;
    vm.init("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    std::stringstream test("");
    vm.executeProgram(test);
    // 输出Hello World!
}

int main() {
    test7();
    return 0;
}
