//
// Created by Ignorant on 2024/5/17.
//

#include "common.h"

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

Mouse &Mouse::getInstance() {
    static Mouse instance;
    return instance;
}

Keyboard &Keyboard::getInstance() {
    static Keyboard instance;
    return instance;
}

bool Image::isOnclick() const {
    int mouseX = Mouse::getInstance().getX();
    int mouseY = Mouse::getInstance().getY();
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height
        && Mouse::getInstance().isMouseDown()) {
        return true;
    }
    return false;
}

bool Image::isSuspended() const {
    int mouseX = Mouse::getInstance().getX();
    int mouseY = Mouse::getInstance().getY();
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height) {
        return true;
    }
    return false;
}

void Jpeg::draw() {
    IMAGE image;
    loadimage(&image, (filename + ".jpg").c_str(), width, height);
    putimage(x, y, &image);
}

void Png::draw() {
    IMAGE image;
    loadimage(&image, (filename + ".png").c_str(), width, height);
    putTransparentImage(x, y, nullptr, &image);
}

void Gif::draw() {
    IMAGE image;
    loadimage(&image, (filename + '-' + to_string(currentFrame + 1) + ".png").c_str(), width, height);
    putTransparentImage(x, y, nullptr, &image);
    currentFrame = (currentFrame + 1) % totalFrames;
}

int Gif::drawOnce() {
    if (currentFrame < totalFrames) {
        IMAGE image;
        loadimage(&image, (filename + '-' + to_string(currentFrame + 1) + ".png").c_str(), width, height);
        putTransparentImage(x, y, nullptr, &image);
        currentFrame++;
        return 0;
    }
    return 1;
}

void Button::draw() {
    image1->draw();
    if (image1->isSuspended()) {
        image2->draw();
        status = 1;
    } else {
        status = 0;
    }
}

Text::Text(const string& font, const string& text, int size, COLORREF color):
        font(font), text(text), size(size), color(color) {
    settextstyle(size, 0, font.c_str());
    settextcolor(color);
    width = textwidth(text.c_str());
    height = textheight(text.c_str());
}

void processMessage(ExMessage *message) {
    while (peekmessage(message, -1)) {
        Mouse::getInstance().setX(message->x);
        Mouse::getInstance().setY(message->y);
        switch (message->message) {
            case WM_LBUTTONDOWN:
                Mouse::getInstance().setMouseDown(true);
                break;
            case WM_LBUTTONUP:
                Mouse::getInstance().setMouseDown(false);
                break;
            case WM_KEYDOWN:
                Keyboard::getInstance().setKey(message->vkcode, true);
                break;
            case WM_KEYUP:
                Keyboard::getInstance().setKey(message->vkcode, false);
                break;
            default:
                break;
        }
    }
}
