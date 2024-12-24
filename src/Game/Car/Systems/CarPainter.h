//
// Created by danilasar on 24.12.2024.
//

#ifndef CPP_04_CROSSROAD_CARDRAWER_H
#define CPP_04_CROSSROAD_CARDRAWER_H

#include "../../../Engine/Systems/Systems.h"
#include "../../../Core.h"

namespace Game {
    namespace Systems {

        class CarPainter : public ::Engine::Systems::ILoadSystem, public ::Engine::Systems::IGraphicSystem {
        private:
            std::shared_ptr<::Game::Core> core;
        public:
            void Load();
            void Redraw();
            void system() {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_CARDRAWER_H
