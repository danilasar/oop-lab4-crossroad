//
// Created by danilasar on 24.12.2024.
//

#include "BackgroundSystem.h"
#include "raylib.h"

namespace Game {
    namespace Systems {
        void BackgroundSystem::Redraw() {
            ClearBackground(RAYWHITE);
        }
    }
}