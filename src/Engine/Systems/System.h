//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_SYSTEM_H
#define CPP_04_CROSSROAD_SYSTEM_H

#include "../Errors/NotImplementedException.h"

namespace Engine {
    namespace Systems {

        class System {
            virtual void system() {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_SYSTEM_H
