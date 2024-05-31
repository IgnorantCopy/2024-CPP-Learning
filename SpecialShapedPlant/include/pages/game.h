//
// Created by Ignorant on 2024/5/26.
//

#ifndef INC_2024_CPP_LEARNING_GAME_H
#define INC_2024_CPP_LEARNING_GAME_H

#include "common.h"
#include <array>

#define ROWS 18
#define COLS 24

enum class Ore {
    NORMAL,
    DIAMOND,
    EMERALD,
};

enum class Device {
    NONE,
    CENTER,
    MINER,
    CONVEYOR,
    CUTTER,
    DESTROYER,
};

void initGame();

Status drawGame();

Status doGameLogic();


#endif //INC_2024_CPP_LEARNING_GAME_H
