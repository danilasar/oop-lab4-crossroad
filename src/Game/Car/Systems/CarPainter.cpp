//
// Created by danilasar on 24.12.2024.
//

#include "CarPainter.h"
#include "../../Car/Entities/CarEntity.h"

namespace Game {
    namespace Systems {
        void CarPainter::Load() {
            core = Game::Core::GetInstance();
        }
        void CarPainter::Redraw() {
            auto &entities = core->GetEntities();
            //auto it = entities->begin();
            for(size_t i = 0; i < entities.size(); ++i) {
                if (auto *(car) = dynamic_cast<::Game::Entities::CarEntity*>(((entities)[i]).get())) {
                    DrawRectangle(car->position.x, car->position.y, 100, 100 + i, RED);
                }
                //++it;
            }
        }
    } // Systems
} // Game