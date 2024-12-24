//
// Created by danilasar on 24.12.2024.
//

#include "TrafficSystem.h"
#include "../../../Core.h"
#include "../../Car/Entities/CarEntity.h"


namespace Game {
    namespace Systems {
        void TrafficSystem::Load() {
            core = Game::Core::GetInstance();
            auto &entities = core->GetEntities();
            auto car = std::make_shared<::Game::Entities::CarEntity>(::Game::Entities::CarEntity(Components::LEFT, Components::TOP, 100.0f));
            car->position = (Vector2){100, 100};
            entities.push_back(car);
        }
        void TrafficSystem::Update() {
            auto &entities = core->GetEntities();
            //auto it = entities->begin();
            for(size_t i = 0; i < entities.size(); ++i) {
                if (auto *(car) = dynamic_cast<::Game::Entities::CarEntity*>(((entities)[i]).get())) {
                    car->position = (Vector2){car->position.x, car->position.y + 5 * core->GetDeltaTime()};
                }
                //++it;
            }
        }
    } // Systems
} // Game