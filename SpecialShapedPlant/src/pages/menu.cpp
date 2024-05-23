//
// Created by Ignorant on 2024/5/17.
//

#include "pages/menu.h"

void drawMenu() {
    Jpeg background(WINDOW_WIDTH, WINDOW_HEIGHT, "image/mainBackground");
    
    Png startButton(350, 175, "image/play");
    startButton.setX((WINDOW_WIDTH - startButton.getWidth()) / 2);
    startButton.setY((WINDOW_HEIGHT - startButton.getHeight()) / 2);
    
    Png startText(350, 175, "image/playText");
    startText.setX((WINDOW_WIDTH - startText.getWidth()) / 2);
    startText.setY((WINDOW_HEIGHT - startText.getHeight()) / 2);
    
    Text title("Ravie", "Special Shaped Plant", 100);
    title.setX((WINDOW_WIDTH - title.getWidth()) / 2);
    title.setY(200);
    
    background.draw();
    title.draw();
    startButton.draw();
    if (startButton.isOnclick()) {
        startText.draw();
    }
}

Status doMenuLogic() {
    if (Keyboard::getInstance().getKey(VK_ESCAPE)) {
        return Status::EXIT;
    }
    BeginBatchDraw();
    drawMenu();
    FlushBatchDraw();
    return Status::CONTINUE;
}
