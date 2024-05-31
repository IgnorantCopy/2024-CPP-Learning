//
// Created by Ignorant on 2024/5/17.
//

#include "pages/menu.h"

Status drawMenu() {
    Jpeg background(WINDOW_WIDTH, WINDOW_HEIGHT, "image/mainBackground");
    
    Png startButtonImage(350, 175, "image/play");
    startButtonImage.setX((WINDOW_WIDTH - startButtonImage.getWidth()) / 2);
    startButtonImage.setY((WINDOW_HEIGHT - startButtonImage.getHeight()) / 2);
    Png startText(350, 175, "image/playText");
    startText.setX((WINDOW_WIDTH - startText.getWidth()) / 2);
    startText.setY((WINDOW_HEIGHT - startText.getHeight()) / 2);
    Button startButton(&startButtonImage, &startText);
    
    static Gif load(650, 200, "image/loading/loading", 50);
    load.setX((WINDOW_WIDTH - load.getWidth()) / 2 - 50);
    load.setY((WINDOW_HEIGHT - startText.getHeight()) / 2);
    
    Text title("Ravie", "Special Shaped Plant", 100);
    title.setX((WINDOW_WIDTH - title.getWidth()) / 2);
    title.setY(200);
    
    background.draw();
    title.draw();
    if (load.drawOnce()) {
        startButton.draw();
        if (startButtonImage.isOnclick()) {
            return Status::NEXT_PAGE;
        }
    }
    return Status::CONTINUE;
}

Status doMenuLogic() {
    if (Keyboard::getInstance().getKey(VK_ESCAPE)) {
        return Status::EXIT;
    }
    BeginBatchDraw();
    Status status = drawMenu();
    FlushBatchDraw();
    return status;
}
