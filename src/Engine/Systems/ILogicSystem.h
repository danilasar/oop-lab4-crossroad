//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_ILOGICSYSTEM_H
#define CPP_04_CROSSROAD_ILOGICSYSTEM_H

#include "System.h"

namespace Engine {
    namespace Systems {

        class ILogicSystem : public System {
        public:
            virtual void Update();
            void system() override {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_ILOGICSYSTEM_H
