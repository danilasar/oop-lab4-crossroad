#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "Core.h"
#include "Engine/Systems/IGraphicSystem.h"
#include "Game/Road/Systems/RoadSystem.h"
#include "Game/Car/Systems/CarPainter.h"
#include "Game/Traffic/Systems/TrafficSystem.h"
#include "Game/TrafficLight/Systems/TrafficLightSystem.h"
#include "Game/UI/Systems/BackgroundSystem.h"

#include <memory>
#include <vector>

void LoadSystems(std::shared_ptr<Game::Core> core) {
    std::unique_ptr<Game::Systems::RoadSystem> roadSystem = { std::make_unique<Game::Systems::RoadSystem>(Game::Systems::RoadSystem()) };
    std::unique_ptr<Game::Systems::BackgroundSystem> backgroundSystem = { std::make_unique<Game::Systems::BackgroundSystem>(Game::Systems::BackgroundSystem()) };
    std::unique_ptr<Game::Systems::CarPainter> carPainterSystem = { std::make_unique<Game::Systems::CarPainter>(Game::Systems::CarPainter()) };
    std::unique_ptr<Game::Systems::TrafficSystem> trafficSystem = { std::make_unique<Game::Systems::TrafficSystem>(Game::Systems::TrafficSystem()) };
    std::unique_ptr<Game::Systems::TrafficLightSystem> trafficLightSystem = { std::make_unique<Game::Systems::TrafficLightSystem>(Game::Systems::TrafficLightSystem()) };

    core->AddSystem(std::move(backgroundSystem));
    core->AddSystem(std::move(roadSystem));
    core->AddSystem(std::move(carPainterSystem));
    core->AddSystem(std::move(trafficSystem));
    core->AddSystem(std::move(trafficLightSystem));
}

int main ()
{
    std::shared_ptr<Game::Core> core = Game::Core::GetInstance();
    LoadSystems(core);
    core->InitGame();
    core->RunGame();
    core->FinishGame();
	return 0;
}
