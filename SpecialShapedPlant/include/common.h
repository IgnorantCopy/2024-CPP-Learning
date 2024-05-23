//
// Created by Ignorant on 2024/5/17.
//

#ifndef INC_2024_CPP_LEARNING_COMMON_H
#define INC_2024_CPP_LEARNING_COMMON_H

#include "graphics.h"
#include <iostream>
#include <array>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900
#define FPS 60
#define NUM_OF_KEYS 255

using namespace std;

enum class Page {
    MENU,
};

enum class Status {
    LAST_PAGE = -1,
    CONTINUE,
    NEXT_PAGE,
    EXIT,
};

void putTransparentImage(int x, int y, IMAGE *dstImg, IMAGE *srcImg);

class Mouse {
    int x;
    int y;
    bool isDown;
public:
    static Mouse &getInstance();
    
    Mouse(const Mouse &) = delete;
    
    Mouse &operator=(const Mouse &) = delete;
    
    int getX() const { return x; }
    
    int getY() const { return y; }
    
    bool isMouseDown() const { return isDown; }
    
    void setX(int x) { this->x = x; }
    
    void setY(int y) { this->y = y; }
    
    void setMouseDown(bool down) { this->isDown = down; }

private:
    Mouse() = default;
    ~Mouse() = default;
};

class Keyboard {
    array<bool, NUM_OF_KEYS> keyboard{};
public:
    static Keyboard &getInstance();
    
    Keyboard(const Keyboard &) = delete;
    
    Keyboard &operator=(const Keyboard &) = delete;
    
    bool getKey(int key) const { return keyboard[key]; }
    
    void setKey(int key, bool isDown) { keyboard[key] = isDown; }

private:
    Keyboard() = default;
    
    ~Keyboard() = default;
};

class Image {
protected:
    int x = 0;
    int y = 0;
    int width;
    int height;
    string filename;    // 不加后缀名
    Image(int width, int height, string const& filename): width(width), height(height), filename(filename) {}
public:
    int getX() const { return x; }
    
    int getY() const { return y; }
    
    int getWidth() const { return width; }
    
    int getHeight() const { return height; }
    
    void setX(int x) { this->x = x; }
    
    void setY(int y) { this->y = y; }
    
    void setWidth(int width) { this->width = width; }
    
    void setHeight(int height) { this->height = height; }
    
    bool isOnclick() const;
    
    bool isSuspended() const;
    
    virtual void draw() = 0;
};

class Jpeg: public Image {
public:
    Jpeg(int width, int height, const string& filename): Image(width, height, filename) {}
    
    void draw() override;
};

class Png: public Image {
public:
    Png(int width, int height, string const& filename): Image(width, height, filename) {}
    
    void draw() override;
};

class Gif: public Image {
    int currentFrame = 0;
    int totalFrames;
public:
    Gif(int width, int height, const string& filename, int totalFrames):
        Image(width, height, filename), totalFrames(totalFrames) {}
    
    void draw() override;
};

class Text {
    string font;
    string text;
    int x = 0;
    int y = 0;
    int width;
    int height;
    int size;
    COLORREF color;
public:
    Text(const string& font, const string& text, int size, COLORREF color = BLACK);
    
    int getWidth() const { return width; }
    
    int getHeight() const { return height; }
    
    void setX(int x) { this->x = x; }
    
    void setY(int y) { this->y = y; }
    
    void draw() const { outtextxy(x, y, text.c_str()); }
};

void processMessage(ExMessage *message);

#endif //INC_2024_CPP_LEARNING_COMMON_H
