//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_GAMESTATE_H
#define CPP_04_CROSSROAD_GAMESTATE_H

#include "raylib.h"

namespace Game {

    class GameState {
    public:
        float roundness = 0.2f;
        float width = 200.0f;
        float height = 100.0f;
        float segments = 0.0f;
        float lineThick = 1.0f;

        bool drawRect = false;
        bool drawRoundedRect = true;
        bool drawRoundedLines = false;

        Rectangle rec;
    };

} // Core

#endif //CPP_04_CROSSROAD_GAMESTATE_H
