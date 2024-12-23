//
// Created by danilasar on 20.12.2024.
//

#include "TrafficLight.h"
#include "../../../../build/external/raylib-master/src/raylib.h"
#include "../../../../build/external/raylib-master/examples/shapes/raygui.h"

namespace Game {
    namespace Components {
        TrafficLight::TrafficLight(int id, Vector2 pos, Game::Components::Rotation rot) {
            this->id = id;
            this->pos = pos;
            this->rot = rot;
        }

        TrafficLightStatus TrafficLight::GetStatus() {
            return status;
        }

        void TrafficLight::SetStatus(Game::Components::TrafficLightStatus status) {
            this->status = status;
        }
    } // Components
} // Game