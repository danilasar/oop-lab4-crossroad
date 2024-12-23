#pragma once
#ifndef CPP_04_CROSSROAD_CORE_H
//#define CPP_04_CROSSROAD_CORE_H

#include "Stores/ResourcesStore.h"
#include "GameState.h"
#include "Game/UI/UI.h"
#include "utils.h"
#include "Engine/Systems/Systems.h"
#include <deque>
#include <functional>
#include <memory>


#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 800




namespace Game {

    class Core {
        Core()
        { }
        double lastTime = GetTime();      // Прошедшее время
        double deltaTime = 0.0;      // Прошедшее время
        std::deque<std::unique_ptr<::Engine::Systems::System>> systems;
    public:
        ResourcesStore *resources;
        GameState *state;
        Core(const Core& ) = delete;
        static Core& GetInstance();
        void InitGame();
        void AddSystem(std::unique_ptr<::Engine::Systems::System> system);
        void RunGame();
        void FinishGame();
        double GetDeltaTime();
    };

} // Game

#endif //CPP_04_CROSSROAD_CORE_H
