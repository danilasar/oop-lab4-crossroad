//
// Created by danilasar on 20.12.2024.
//

#include "Car.h"

namespace Game {
    namespace Components {
        Car::Car(Game::Components::Road from, Game::Components::Road to, float baseSpeed) {
            this->from = from;
            this->to = to;
            this->baseSpeed = baseSpeed;
        }
        float Car::GetBaseSpeed() {
            return baseSpeed;
        }

        float Car::GetSpeed() {
            return speed;
        }

        void Car::SetBaseSpeed(float newSpeed) {
            baseSpeed = newSpeed;
        }

        void Car::SetSpeed(float newSpeed) {
            speed = newSpeed;
        }
    } // Components
} // Game