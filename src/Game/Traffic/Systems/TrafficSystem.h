//
// Created by danilasar on 24.12.2024.
//

#ifndef CPP_04_CROSSROAD_TRAFFICSYSTEM_H
#define CPP_04_CROSSROAD_TRAFFICSYSTEM_H

#include "../../../Engine/Systems/Systems.h"

namespace Game {
    namespace Systems {

        class TrafficSystem : public ::Engine::Systems::ILoadSystem, public ::Engine::Systems::ILogicSystem {
            void Load();
            void Update();
            void system() {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_TRAFFICSYSTEM_H
