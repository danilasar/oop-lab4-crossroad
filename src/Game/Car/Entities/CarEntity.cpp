//
// Created by danilasar on 20.12.2024.
//

#include "CarEntity.h"

namespace Game {
    namespace Entities {
        CarEntity::CarEntity(Game::Components::Road from, Game::Components::Road to, float baseSpeed) {
            this->from = from;
            this->to = to;
            this->baseSpeed = baseSpeed;
        }
        float CarEntity::GetBaseSpeed() {
            return baseSpeed;
        }

        float CarEntity::GetSpeed() {
            return speed;
        }

        void CarEntity::SetBaseSpeed(float newSpeed) {
            baseSpeed = newSpeed;
        }

        void CarEntity::SetSpeed(float newSpeed) {
            speed = newSpeed;
        }
    } // Entities
} // Game