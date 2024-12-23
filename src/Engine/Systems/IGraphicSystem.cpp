//
// Created by danilasar on 23.12.2024.
//

#include "IGraphicSystem.h"

#include "../Errors/NotImplementedException.h"

namespace Engine {
    namespace Systems {
        void IGraphicSystem::Redraw() {
            throw Engine::Exceptions::NotImplementedException();
        }
    } // Systems
} // Game