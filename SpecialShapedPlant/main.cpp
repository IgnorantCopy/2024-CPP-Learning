//
// Created by Ignorant on 2024/5/11.
//

#include "main.h"
#include <iostream>
#include "../../../Import/easyx4mingw_20240225/include/graphics.h"
#include "../../../Import/easyx4mingw_20240225/include/easyx.h"

#define HEIGHT 800
#define WIDTH 1000

using namespace std;

int main() {
    // 初始化窗口
    initgraph(WIDTH, HEIGHT);
    // 设置背景颜色
    setbkcolor(WHITE);
    // 清除窗口
    cleardevice();
    
    // 关闭窗口
    closegraph();
    return 0;
}
