//
// Created by danilasar on 20.12.2024.
//

#include "TrafficLightSystem.h"

namespace Game {
    namespace Systems {
        void TrafficLightSystem::Load() {
            core = Game::Core::GetInstance();
            auto &entities = core->GetEntities();
            auto light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){TRAFFIC_LIGHT_LEFT_X, TRAFFIC_LIGHT_LEFT_Y}, ::Game::Components::TL_LEFT));
            entities.push_back(light);
            lights.push_back(light);
            light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){TRAFFIC_LIGHT_TOP_X, TRAFFIC_LIGHT_TOP_Y}, ::Game::Components::TL_TOP));
            entities.push_back(light);
            lights.push_back(light);
            light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){TRAFFIC_LIGHT_RIGHT_X, TRAFFIC_LIGHT_RIGHT_Y}, ::Game::Components::TL_RIGHT));
            entities.push_back(light);
            lights.push_back(light);
            light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){TRAFFIC_LIGHT_BOTTOM_X, TRAFFIC_LIGHT_BOTTOM_Y}, ::Game::Components::TL_BOTTOM));
            entities.push_back(light);
            lights.push_back(light);
        }
        void TrafficLightSystem::Update() {

        }
        void TrafficLightSystem::Redraw() {
            for(auto light : lights) {
                float deltaX = 0;
                float deltaY = 0;
                Color c;
                DrawRectanglePro({light->pos.x, light->pos.y, TRAFFIC_SINGLE_LIGHT_SIZE, 3 * TRAFFIC_SINGLE_LIGHT_SIZE}, {0,0}, GetNextLampDelta(light->rot), GREEN);
                DrawRectanglePro({light->pos.x, light->pos.y, TRAFFIC_SINGLE_LIGHT_SIZE, 2 * TRAFFIC_SINGLE_LIGHT_SIZE}, {0,0}, GetNextLampDelta(light->rot), YELLOW);
                DrawRectanglePro({light->pos.x, light->pos.y, TRAFFIC_SINGLE_LIGHT_SIZE, 1 * TRAFFIC_SINGLE_LIGHT_SIZE}, {0,0}, GetNextLampDelta(light->rot), RED);
            }
        }

        float TrafficLightSystem::GetNextLampDelta(::Game::Components::Rotation r) {
            switch(r) {
                case Components::TL_LEFT:
                    return 90;
                    break;
                case Components::TL_TOP:
                    return 180;
                    break;
                case Components::TL_RIGHT:
                    return -90;
                    break;
                case Components::TL_BOTTOM:
                    return 0;
                    break;
            }
        }
    } // Systems
} // Game