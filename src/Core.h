#pragma once
#ifndef CPP_04_CROSSROAD_CORE_H
//#define CPP_04_CROSSROAD_CORE_H

#include "Stores/ResourcesStore.h"
#include "GameState.h"
#include "Game/UI/UI.h"
#include "utils.h"
#include "Engine/Entity/EntityBase.h"
#include "Engine/Systems/Systems.h"
#include <deque>
#include <functional>
#include <memory>
#include <vector>


#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 800




namespace Game {

    class Core {
        Core();
        double lastTime = GetTime();      // Последнее время
        double deltaTime = 0.0;           // Разница во времени с предыдущим игровым циклом
        std::vector<std::unique_ptr<::Engine::Systems::System>> systems;
        std::deque<std::shared_ptr<::Engine::Entities::EntityBase>> entities;
        static inline std::shared_ptr<Core> _instance;
    public:
        ResourcesStore *resources;
        GameState *state;
        //Core(const Core& ) = delete;
        static std::shared_ptr<Core> GetInstance();
        void InitGame();
        void RunGame();
        void FinishGame();
        double GetDeltaTime();

        void AddSystem(std::unique_ptr<::Engine::Systems::System> system);
        std::deque<std::shared_ptr<::Engine::Entities::EntityBase>> &GetEntities();
    };

} // Game

#endif //CPP_04_CROSSROAD_CORE_H
