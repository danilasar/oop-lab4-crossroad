#ifndef CPP_04_CROSSROAD_CORE_H
#define CPP_04_CROSSROAD_CORE_H

#include "ResourcesStore.h"

namespace Core {

    class Core {
        Core()
        { }
    public:
        ResourcesStore *resources;
        Core(const Core& ) = delete;
        static Core& GetInstance();
        void InitGame();
        void FinishGame();
    };

} // Game

#endif //CPP_04_CROSSROAD_CORE_H
