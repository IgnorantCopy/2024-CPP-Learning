//
// Created by Ignorant on 2024/5/11.
//

#include <iostream>
#include "common.h"
#include "pages/menu.h"

using namespace std;

Status doLogic(Page page) {
    ExMessage message;
    processMessage(&message);
    switch (page) {
        case Page::MENU:
            return doMenuLogic();
        default:
            break;
    }
    return Status::CONTINUE;
}

int main() {
    // 初始化窗口
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    // 设置背景颜色
    setbkcolor(WHITE);
    // 设置背景模式
    setbkmode(TRANSPARENT);
    // 清除窗口
    cleardevice();
    
    while (doLogic(Page::MENU) == Status::CONTINUE) {
        Sleep(1000 / FPS);
    }
    
    // 关闭窗口
    closegraph();
    return 0;
}
