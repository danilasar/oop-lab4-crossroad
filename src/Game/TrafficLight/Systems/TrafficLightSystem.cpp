//
// Created by danilasar on 20.12.2024.
//

#include "TrafficLightSystem.h"

namespace Game {
    namespace Systems {
        void TrafficLightSystem::Load() {
            core = Game::Core::GetInstance();
            auto &entities = core->GetEntities();
            settings = std::make_shared<::Game::Entities::TrafficSettings>(::Game::Entities::TrafficSettings());
            entities.push_back(settings);
            auto light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){TRAFFIC_LIGHT_LEFT_X, TRAFFIC_LIGHT_LEFT_Y}, ::Game::Components::TL_LEFT));
            entities.push_back(light);
            lights.push_back(light);
            light = std::make_shared<::Game::Entities::TrafficLight>(::Game::Entities::TrafficLight(0, (Vector2){TRAFFIC_LIGHT_TOP_X, TRAFFIC_LIGHT_TOP_Y}, ::Game::Components::TL_TOP));
            light->SetStatus(Components::TL_RED);
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
            timer += core->GetDeltaTime();
            if(timer > settings->signalPeriod) {
                settings->NextColor();
                timer = 0;
            }
        }
        void TrafficLightSystem::Redraw() {
            int i = 0;
            for(auto light : lights) {
                float deltaX = 0;
                float deltaY = 0;
                Color c;
                ::Game::Components::TrafficLightStatus color;
                if(i % 2 == 0) {
                    color = settings->GetMainColor();
                } else {
                    color = settings->GetSecondaryColor();
                }
                DrawRectanglePro({light->pos.x, light->pos.y,
                                  TRAFFIC_SINGLE_LIGHT_SIZE, 3 * TRAFFIC_SINGLE_LIGHT_SIZE}, {0,0},
                                 GetNextLampDelta(light->rot),
                                 color == Components::TL_GREEN ?  (Color){  10, 255,  10, 255 } : (Color){  10, 100, 10, 255 });
                DrawRectanglePro({light->pos.x, light->pos.y,
                                  TRAFFIC_SINGLE_LIGHT_SIZE, 2 * TRAFFIC_SINGLE_LIGHT_SIZE}, {0,0},
                                 GetNextLampDelta(light->rot),
                                 color == Components::TL_YELLOW ? (Color){ 255, 255,  10, 255 } : (Color){ 100, 100, 10, 255 });
                DrawRectanglePro({light->pos.x, light->pos.y,
                                  TRAFFIC_SINGLE_LIGHT_SIZE, 1 * TRAFFIC_SINGLE_LIGHT_SIZE}, {0,0},
                                 GetNextLampDelta(light->rot),
                                 color == Components::TL_RED ?    (Color){ 255,  10,  10, 255 } : (Color){ 100,  10, 10, 255 });
                ++i;
            }
        }

        float TrafficLightSystem::GetNextLampDelta(::Game::Components::Rotation r) {
            switch(r) {
                case Components::TL_LEFT:
                    return 90;
                case Components::TL_TOP:
                    return 180;
                case Components::TL_RIGHT:
                    return -90;
                case Components::TL_BOTTOM:
                    return 0;
            }
        }

    } // Systems
} // Game