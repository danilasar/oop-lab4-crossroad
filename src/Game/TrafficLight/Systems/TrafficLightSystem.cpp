//
// Created by danilasar on 20.12.2024.
//

#include "TrafficLightSystem.h"

namespace Game {
    namespace Systems {
        void TrafficLightSystem::Load() {
            core = Game::Core::GetInstance();
            auto &entities = core->GetEntities();
            auto light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){10, 69}, ::Game::Components::TL_LEFT));
            entities.push_back(light);
            lights.push_back(light);
        }
        void TrafficLightSystem::Update() {

        }
        void TrafficLightSystem::Redraw() {
            for(auto light : lights) {
                DrawRectangle(light->pos.x, light->pos.y, 100, 100, GREEN);
                break;
            }
        }
    } // Systems
} // Game