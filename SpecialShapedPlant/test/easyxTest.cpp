//
// Created by Ignorant on 2024/5/11.
//

#include <iostream>
#include "graphics.h"
#include "easyx.h"

#define FPS 60
#define HEIGHT 800
#define WIDTH 1000

using namespace std;

void putTransparentImage(int x, int y, IMAGE *dstImg, IMAGE *srcImg) {
    // initialize
    DWORD *dst = GetImageBuffer(dstImg);
    DWORD *src = GetImageBuffer(srcImg);
    int srcWidth = srcImg->getwidth();
    int srcHeight = srcImg->getheight();
    int dstWidth = dstImg == nullptr ? getwidth() : dstImg->getwidth();
    int dstHeight = dstImg == nullptr ? getheight() : dstImg->getheight();
    
    // calculate the real width and height
    int realWidth = (x + srcWidth > dstWidth) ? dstWidth - x : srcWidth;
    int realHeight = (y + srcHeight > dstHeight)? dstHeight - y : srcHeight;
    if (x < 0) {
        src += -x;
        realWidth += x;
        x = 0;
    }
    if (y < 0) {
        src += -y * srcWidth;
        realHeight += y;
        y = 0;
    }
    dst += y * dstWidth + x;
    
    // draw the transparent image
    for (int i = 0; i < realHeight; i++) {
        for (int j = 0; j < realWidth; j++) {
            unsigned long sa = (src[j] & 0xff000000) >> 24;
            unsigned long sr = (src[j] & 0x00ff0000) >> 16;
            unsigned long sg = (src[j] & 0x0000ff00) >> 8;
            unsigned long sb = src[j] & 0x000000ff;
            
            unsigned long dr = (dst[j] & 0x00ff0000) >> 16;
            unsigned long dg = (dst[j] & 0x0000ff00) >> 8;
            unsigned long db = dst[j] & 0x000000ff;
            
            dst[j] = ((sr + dr * (255 - sa) / 255) << 16)
                    | ((sg + dg * (255 - sa) / 255) << 8)
                    | (sb + db * (255 - sa) / 255);
        }
        dst += dstWidth;
        src += srcWidth;
    }
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
    string filename = "../image/play";
    loadimage(&playImg, (filename + ".png").c_str());
    putTransparentImage(WIDTH / 2 - playImg.getwidth() / 2, HEIGHT / 2 - playImg.getheight() / 2, nullptr, &playImg);
    IMAGE playTextImg;
    loadimage(&playTextImg, "../image/playText.png");
    /*
     * 事件：ExMessage
     *  message.message     事件类型
     *  message.x           鼠标位置x坐标
     *  message.y           鼠标位置y坐标
     *  message.vkcode      按键代码
     *  message.ctrl        是否按下了Ctrl键
     *  message.shift       是否按下了Shift键
     *  message.lbutton     鼠标左键是否按下
     *  message.rbutton     鼠标右键是否按下
     *  message.mbutton     鼠标中键是否按下
     *  message.wheel       鼠标滚轮滚动值，为120的整数倍
     *  message.extended    是否为扩展按键(功能键、数字键盘等)
     *  message.prevdown    按键的上一个状态是否为按下
     */
    ExMessage message;
    bool flag = true;
    while (flag) {
        while (peekmessage(&message, -1)) {
            switch (message.message) {
                case WM_LBUTTONDOWN:
                    if (message.x >= WIDTH / 2 - playImg.getwidth() / 2
                        && message.x <= WIDTH / 2 + playImg.getwidth() / 2
                        && message.y >= HEIGHT / 2 - playImg.getheight() / 2
                        && message.y <= HEIGHT / 2 + playImg.getheight() / 2) {
                        cout << "Button clicked on " << message.x << ", " << message.y << endl;
                        putTransparentImage(WIDTH / 2 - playImg.getwidth() / 2, HEIGHT / 2 - playImg.getheight() / 2,
                                            nullptr, &playTextImg);
                    }
                    break;
                case WM_LBUTTONUP:
                    if (message.x >= WIDTH / 2 - playImg.getwidth() / 2
                        && message.x <= WIDTH / 2 + playImg.getwidth() / 2
                        && message.y >= HEIGHT / 2 - playImg.getheight() / 2
                        && message.y <= HEIGHT / 2 + playImg.getheight() / 2) {
                        cout << "Button released on " << message.x << ", " << message.y << endl;
                        putTransparentImage(WIDTH / 2 - playImg.getwidth() / 2, HEIGHT / 2 - playImg.getheight() / 2,
                                            nullptr, &playImg);
                    }
                    break;
                case WM_KEYDOWN:
                    if (message.vkcode == VK_ESCAPE) {
                        flag = false;
                    } else if (message.vkcode == VK_SPACE) {
                        cout << "Space pressed" << endl;
                    }
                    break;
                default:
                    break;
            }
        }
        Sleep(1000 / FPS);
    }
    // 关闭窗口
    closegraph();
    return 0;
}
