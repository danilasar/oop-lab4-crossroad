//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_ILOGICSYSTEM_H
#define CPP_04_CROSSROAD_ILOGICSYSTEM_H

#include "System.h"

namespace Engine {
    namespace Systems {

        class ILogicSystem {
        public:
            virtual void Update();
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_ILOGICSYSTEM_H
