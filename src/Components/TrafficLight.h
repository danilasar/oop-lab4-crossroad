//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_TRAFFICLIGHT_H
#define CPP_04_CROSSROAD_TRAFFICLIGHT_H

#include "../utils.h"
#include "raylib.h"
namespace Game {
    namespace Components {

        enum Rotation {
            TL_VERTICAL,
            TL_HORIZONTAL
        };

        enum TrafficLightStatus {
            TL_BLACK,
            TL_YELLOW,
            TL_GREEN
        };

        class TrafficLight {
            ::Game::Components::TrafficLightStatus status;
        public:
            Vector2 pos;
            int id;
            ::Game::Components::Rotation rot;
            TrafficLight(int id, Vector2 pos, ::Game::Components::Rotation rot);
            ::Game::Components::TrafficLightStatus GetStatus();
            void SetStatus(::Game::Components::TrafficLightStatus status);
            void NextStatus();
        };

    } // Components
} // Game

#endif //CPP_04_CROSSROAD_TRAFFICLIGHT_H