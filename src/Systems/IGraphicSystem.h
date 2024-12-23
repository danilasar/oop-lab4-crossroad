//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_IGRAPHICSYSTEM_H
#define CPP_04_CROSSROAD_IGRAPHICSYSTEM_H

#include "System.h"

namespace Game {
    namespace Systems {

        class IGraphicSystem {
        public:
            virtual void Redraw();
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_IGRAPHICSYSTEM_H
