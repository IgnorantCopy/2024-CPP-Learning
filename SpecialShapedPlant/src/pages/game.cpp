//
// Created by Ignorant on 2024/5/26.
//

#include "pages/game.h"
#include <random>

Ore ores[ROWS][COLS];
Device devices[ROWS][COLS];

void initGame() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(0, 15);
            int randNum = dis(gen);
            if (randNum == 0) {
                ores[i][j] = Ore::DIAMOND;
            } else if (randNum == 1 || randNum == 2) {
                ores[i][j] = Ore::EMERALD;
            } else {
                ores[i][j] = Ore::NORMAL;
            }
            devices[i][j] = Device::NONE;
        }
    }
}

Status drawGame() {
    int width = WINDOW_WIDTH / COLS;
    int height = WINDOW_HEIGHT / ROWS;
    Jpeg oreImages[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            oreImages[i][j].setWidth(width);
            oreImages[i][j].setHeight(height);
            oreImages[i][j].setX(width * j);
            oreImages[i][j].setY(height * i);
            switch (ores[i][j]) {
                case Ore::NORMAL:
                    oreImages[i][j].setFilename("image/commonRock");
                    break;
                case Ore::DIAMOND:
                    oreImages[i][j].setFilename("image/diamond");
                    break;
                case Ore::EMERALD:
                    oreImages[i][j].setFilename("image/emerald");
                    break;
                default:
                    oreImages[i][j].setFilename("image/commonRock");
                    break;
            }
            oreImages[i][j].draw();
        }
    }
    return Status::CONTINUE;
}

Status doGameLogic() {
    if (Keyboard::getInstance().getKey(VK_ESCAPE)) {
        return Status::EXIT;
    }
    
    BeginBatchDraw();
    Status status = drawGame();
    FlushBatchDraw();
    return status;
}


