//
// Created by Ignorant on 2024/5/11.
//

#include <iostream>
#include <conio.h>
#include "../../../Import/easyx4mingw_20240225/include/graphics.h"
#include "../../../Import/easyx4mingw_20240225/include/easyx.h"

#define HEIGHT 800
#define WIDTH 1000

using namespace std;

void putTransparentImage(int x, int y, const IMAGE *mask, const IMAGE *image) {
    putimage(x, y, mask, SRCAND);
    putimage(x, y, image, SRCPAINT);
}

int main() {
    // 初始化窗口
    initgraph(WIDTH, HEIGHT);
    // 设置背景颜色
    setbkcolor(WHITE);
    // 清除窗口
    cleardevice();
    /*
     * 图形绘制：
     *  1. 画圆
     *      > circle(x, y, radius)  无填充
     *      > fillcircle(x, y, radius)  有边框填充
     *      > solidcircle(x, y, radius) 无边框填充
     *  2. 椭圆：ellipse(left, top, right, bottom)
     *  3. 扇形：pie(left, top, right, bottom, startangle, endangle)
     *  4. 矩形：rectangle(left, top, right, bottom)
     *  5. 圆角矩形：roundrect(left, top, right, bottom, ellipsewidth, ellipseheight)
     *  6. 多边形：polyline(x1, y1, x2, y2, ..., xn, yn)
     *  7. 直线：line(x1, y1, x2, y2)
     *  8. 画点：putpixel(x, y, color)
     */
    /*
     * 颜色：
     *  1. 填充颜色：setfillcolor(color)
     *  2. 画笔颜色：setlinecolor(color)
     */
    setlinestyle(PS_SOLID, 5);
    setfillcolor(RED);
    setlinecolor(BLUE);
    fillcircle(400, 400, 50);
    /*
     * 绘制文字：
     *  1. outtextxy(x, y, text)
     *  2. settextcolor(color)
     *  3. settextstyle(height, width, font)    width=0, 字体大小自适应
     *  4. textheight(text)  获取文字高度
     *  5. textwidth(text)   获取文字宽度
     *  6. setbkmode(mode)   设置背景模式，mode=TRANSPARENT, OPAQUE
     */
    settextstyle(30, 0, "Arial");
    settextcolor(RGB(0, 255, 255));
    setbkmode(TRANSPARENT);  // 设置背景模式为透明
    outtextxy(WIDTH / 2 - textwidth("Hello, world!") / 2, 50, "Hello, world!");
    /*
     * 渲染图片：
     *  1. loadimage(playImg, filename, width = 0, height = 0, resize = false)  加载图片
     *  2. putimage(x, y, playImg, playImg, dwRop = SRCCOPY)  绘制图片
     */
    IMAGE playImg;
    loadimage(&playImg, "../image/play.png");
    IMAGE playMask;
    loadimage(&playMask, "../image/playMask.png");
    putTransparentImage(WIDTH / 2 - playImg.getwidth() / 2, HEIGHT / 2 - playImg.getheight() / 2, &playMask, &playImg);
    IMAGE playTextImg;
    loadimage(&playTextImg, "../image/playText.png");
    IMAGE playTextMask;
    loadimage(&playTextMask, "../image/playTextMask.png");
    /*
     * 事件：
     */
    ExMessage message;
    bool flag = true;
    while (flag) {
        if (peekmessage(&message, EM_MOUSE)) {
            switch (message.message) {
                case WM_LBUTTONDOWN:
                    if (message.x >= WIDTH / 2 - playImg.getwidth() / 2
                        && message.x <= WIDTH / 2 + playImg.getwidth() / 2
                        && message.y >= HEIGHT / 2 - playImg.getheight() / 2
                        && message.y <= HEIGHT / 2 + playImg.getheight() / 2) {
                        putTransparentImage(WIDTH / 2 - playImg.getwidth() / 2, HEIGHT / 2 - playImg.getheight() / 2, &playTextMask, &playTextImg);
                    }
                    break;
                case WM_LBUTTONUP:
                    if (message.x >= WIDTH / 2 - playImg.getwidth() / 2
                        && message.x <= WIDTH / 2 + playImg.getwidth() / 2
                        && message.y >= HEIGHT / 2 - playImg.getheight() / 2
                        && message.y <= HEIGHT / 2 + playImg.getheight() / 2) {
                        putTransparentImage(WIDTH / 2 - playImg.getwidth() / 2, HEIGHT / 2 - playImg.getheight() / 2, &playMask, &playImg);
                    }
                    break;
                default:
                    break;
            }
        } else if (peekmessage(&message, EM_KEY)) {
            switch (message.message) {
                case WM_KEYDOWN:
                    if (message.vkcode == VK_ESCAPE) {
                        flag = false;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    // 关闭窗口
    closegraph();
    return 0;
}
