//
// Created by danilasar on 20.12.2024.
//

#include "TrafficLight.h"
#include "raylib.h"
#include "raygui.h"

namespace Game {
    namespace Entities {
        TrafficLight::TrafficLight(int id, Vector2 pos, ::Game::Components::Rotation rot) {
            this->id = id;
            this->pos = pos;
            this->rot = rot;
        }

        ::Game::Components::TrafficLightStatus TrafficLight::GetStatus() {
            return status;
        }

        void TrafficLight::SetStatus(::Game::Components::TrafficLightStatus status) {
            this->status = status;
        }
    } // Entities
} // Game