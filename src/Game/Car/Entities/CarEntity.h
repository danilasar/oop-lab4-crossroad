//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_CARENTITY_H
#define CPP_04_CROSSROAD_CARENTITY_H

#include "../../../Engine/Entity/EntityBase.h"
#include "../../../utils.h"
#include "../Components/Car.h"
#include "../Components/CarState.h"

namespace Game {
    namespace Entities {
        class CarEntity : public ::Engine::Entities::EntityBase {
            float baseSpeed;
            float speed;
        public:
            Vector2 position;
            Game::Components::Road from;
            Game::Components::Road to;
            Game::Components::State state;
            CarEntity(Game::Components::Road from, Game::Components::Road to, float baseSpeed);
            float GetSpeed();
            float GetBaseSpeed();
            void SetSpeed(float newSpeed);
            void SetBaseSpeed(float newSpeed);
            std::string GetEntityName() const { return "CarEntity"; };
        };
    } // Entities
} // Game

#endif //CPP_04_CROSSROAD_CARENTITY_H
