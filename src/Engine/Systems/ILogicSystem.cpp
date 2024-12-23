//
// Created by danilasar on 23.12.2024.
//

#include "ILogicSystem.h"

#include "../Errors/NotImplementedException.h"

namespace Engine {
    namespace Systems {
        void ILogicSystem::Update() {
            throw Engine::Exceptions::NotImplementedException();
        }
    } // Systems
} // Game