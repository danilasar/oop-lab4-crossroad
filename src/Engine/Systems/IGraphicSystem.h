//
// Created by danilasar on 23.12.2024.
//

#ifndef CPP_04_CROSSROAD_IGRAPHICSYSTEM_H
#define CPP_04_CROSSROAD_IGRAPHICSYSTEM_H

#include "System.h"
#include "../Errors/NotImplementedException.h"

namespace Engine {
    namespace Systems {

        class IGraphicSystem : public System {
        public:
            virtual void Redraw();
        };

    } // Systems
} // Game

#endif //CPP_04_CROSSROAD_IGRAPHICSYSTEM_H
