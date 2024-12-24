//
// Created by danilasar on 24.12.2024.
//

#ifndef CPP_04_CROSSROAD_TRAFFICSETTINGS_H
#define CPP_04_CROSSROAD_TRAFFICSETTINGS_H

#include "../../../Engine/Entity/EntityBase.h"
#include "../../TrafficLight/Entities/TrafficLight.h"

namespace Game {
    namespace Entities {
        class TrafficSettings : public ::Engine::Entities::EntityBase {
        private:
            ::Game::Components::TrafficLightStatus mainColor;
            ::Game::Components::TrafficLightStatus previousColor;
        public:
            float signalPeriod = 2.f; // длительность сигнала в секундах
            ::Game::Components::TrafficLightStatus GetMainColor();
            ::Game::Components::TrafficLightStatus GetSecondaryColor();
            void SetMainColor(::Game::Components::TrafficLightStatus status);
            void NextColor();
        };
    } // Entities
} // Game

#endif //CPP_04_CROSSROAD_TRAFFICSETTINGS_H
