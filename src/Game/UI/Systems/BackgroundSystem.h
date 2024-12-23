//
// Created by danilasar on 24.12.2024.
//

#ifndef CPP_04_CROSSROAD_BACKGROUNDSYSTEM_H
#define CPP_04_CROSSROAD_BACKGROUNDSYSTEM_H

#include "../../../Engine/Systems/IGraphicSystem.h"

namespace Game {
    namespace Systems {
    class BackgroundSystem : public ::Engine::Systems::IGraphicSystem {
            void Redraw();
        };
    }
}


#endif //CPP_04_CROSSROAD_BACKGROUNDSYSTEM_H
