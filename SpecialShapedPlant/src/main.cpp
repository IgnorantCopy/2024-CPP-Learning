//
// Created by Ignorant on 2024/5/11.
//

#include <iostream>
#include "common.h"
#include "pages/menu.h"
#include "pages/game.h"

using namespace std;

Status doLogic(Page page) {
    ExMessage message;
    processMessage(&message);
    switch (page) {
        case Page::MENU:
            return doMenuLogic();
        case Page::GAME:
            return doGameLogic();
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
    Status status = Status::CONTINUE;
    Page page = Page::MENU;
    int count = 0;
    while (status == Status::CONTINUE) {
        status = doLogic(page);
        page = (Page) (page + (int) status);
        if (status == Status::NEXT_PAGE && count == 0) {
            count = 1;
            initGame();
            status = Status::CONTINUE;
        }
        if (status == Status::LAST_PAGE && count == 1) {
            count = 0;
        }
        Sleep(1000 / FPS);
    }
    
    
    // 关闭窗口
    closegraph();
    return 0;
}
