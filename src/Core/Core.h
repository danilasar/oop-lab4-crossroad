#ifndef CPP_04_CROSSROAD_CORE_H
#define CPP_04_CROSSROAD_CORE_H

#include "ResourcesStore.h"

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 800

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
