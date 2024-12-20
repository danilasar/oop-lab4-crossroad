#ifndef CPP_04_CROSSROAD_CORE_H
#define CPP_04_CROSSROAD_CORE_H

#include "ResourcesStore.h"
#include "GameState.h"

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 800



#define WORKSPACE_TOP 0
#define WORKSPACE_LEFT 0
#define WORKSPACE_WIDTH GetScreenWidth() * 0.7
#define WORKSPACE_HEIGHT GetScreenHeight()
#define WORKSPACE_BOTTOM WORKSPACE_TOP + WORKSPACE_HEIGHT
#define WORKSPACE_RIGHT WORKSPACE_LEFT + WORKSPACE_WIDTH
#define WORKSPACE_V_MID (WORKSPACE_BOTTOM - WORKSPACE_TOP) / 2
#define WORKSPACE_H_MID (WORKSPACE_RIGHT - WORKSPACE_LEFT) / 2

#define MENU_TOP 0
#define MENU_LEFT WORKSPACE_RIGHT
#define MENU_RIGHT GetScreenWidth()
#define MENU_BOTTOM GetScreenHeight()
#define MENU_WIDTH GetScreenWidth() - WORKSPACE_WIDTH
#define MENU_HEIGHT GetScreenHeight()
#define MENU_V_MID (MENU_BOTTOM - MENU_TOP) / 2
#define MENU_H_MID (MENU_RIGHT - MENU_LEFT) / 2

namespace Game {

    class Core {
        Core()
        { }
        double lastTime = GetTime();      // Прошедшее время
    public:
        ResourcesStore *resources;
        GameState *state;
        double deltaTime = 0.0;      // Прошедшее время
        Core(const Core& ) = delete;
        static Core& GetInstance();
        void InitGame();
        void RunGame();
        void FinishGame();
    };

} // Game

#endif //CPP_04_CROSSROAD_CORE_H
