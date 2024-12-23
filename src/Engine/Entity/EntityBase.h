//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_ENTITYBASE_H
#define CPP_04_CROSSROAD_ENTITYBASE_H

#include <string>

namespace Engine {
    namespace Entities {

        class EntityBase {
        public:
            virtual std::string GetEntityName() const { return "Undefined"; };
        };

    } // Entities
} // Game

#endif //CPP_04_CROSSROAD_ENTITYBASE_H
