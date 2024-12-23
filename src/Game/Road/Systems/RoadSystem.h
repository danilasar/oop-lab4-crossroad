//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_ROADSYSTEM_H
#define CPP_04_CROSSROAD_ROADSYSTEM_H

#include "../../../Engine/Systems/Systems.h"

namespace Game {
    namespace Systems {
        class RoadSystem : public ::Engine::Systems::IGraphicSystem {
        public:
            void Redraw();
        };
    }
}


#endif //CPP_04_CROSSROAD_ROADSYSTEM_H
