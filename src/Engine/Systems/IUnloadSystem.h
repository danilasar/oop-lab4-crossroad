//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_IUNLOADSYSTEM_H
#define CPP_04_CROSSROAD_IUNLOADSYSTEM_H

#include "System.h"

namespace Engine {
    namespace Systems {

        class IUnloadSystem : public virtual System {
        public:
            virtual void Unload();
            void system() override {}
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_IUNLOADSYSTEM_H
