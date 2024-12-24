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
            entities.push_back(std::make_shared<::Game::Entities::CarEntity>(::Game::Entities::CarEntity(Components::LEFT, Components::TOP, 100.0f)));
        }
        void TrafficSystem::Update() {
            auto &entities = core->GetEntities();
            //auto it = entities->begin();
            for(size_t i = 0; i < entities.size(); ++i) {
                if (auto *(val) = dynamic_cast<::Game::Entities::CarEntity*>(((entities)[i]).get())) {
                    DrawRectangle(100, 100, 100, 100 + i, RED);
                }
                //++it;
            }
        }
    } // Systems
} // Game