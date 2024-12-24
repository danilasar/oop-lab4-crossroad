//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_TRAFFICLIGHTSYSTEM_H
#define CPP_04_CROSSROAD_TRAFFICLIGHTSYSTEM_H

#include "../../../Engine/Systems/Systems.h"
#include "../../../Core.h"
#include "../../TrafficLight/Entities/TrafficLight.h"
#include "../../../utils.h"
#include "raylib.h"
#include <vector>

namespace Game {
    namespace Systems {

        class TrafficLightSystem : public ::Engine::Systems::ILoadSystem, public ::Engine::Systems::ILogicSystem, public ::Engine::Systems::IGraphicSystem {
        private:
            std::shared_ptr<::Game::Core> core;
            std::vector<std::shared_ptr<::Game::Entities::TrafficLight>> lights;
            float GetNextLampDelta(::Game::Components::Rotation r);
        public:
            void Load();
            void Update();
            void Redraw();
            void system() {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_TRAFFICLIGHTSYSTEM_H
