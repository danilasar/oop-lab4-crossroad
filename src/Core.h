#pragma once
#ifndef CPP_04_CROSSROAD_CORE_H
//#define CPP_04_CROSSROAD_CORE_H

#include "Stores/ResourcesStore.h"
#include "GameState.h"
#include "UI/UI.h"
#include "utils.h"

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 800




namespace Game {

    class Core {
        Core()
        { }
        double lastTime = GetTime();      // Прошедшее время
        UI *ui;
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
