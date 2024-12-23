//
// Created by danilasar on 24.12.2024.
//

#ifndef CPP_04_CROSSROAD_CARDRAWER_H
#define CPP_04_CROSSROAD_CARDRAWER_H

#include "../../../Engine/Systems/Systems.h"

namespace Game {
    namespace Systems {

        class CarPainter : public ::Engine::Systems::IGraphicSystem {
        public:
            void Redraw();
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_CARDRAWER_H
