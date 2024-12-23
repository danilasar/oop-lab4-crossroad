//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_ILOADSYSTEM_H
#define CPP_04_CROSSROAD_ILOADSYSTEM_H

#include "System.h"

namespace Engine {
    namespace Systems {

        class ILoadSystem : public System {
        public:
            virtual void Load();
            void system() override {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_ILOADSYSTEM_H
