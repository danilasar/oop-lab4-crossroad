#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "Core.h"
#include "Engine/Systems/IGraphicSystem.h"
#include "Game/Road/Systems/RoadSystem.h"
#include "Game/UI/Systems/BackgroundSystem.h"

#include <memory>
#include <vector>

void LoadSystems(Game::Core &core) {
    std::unique_ptr<Game::Systems::RoadSystem> roadSystem = { std::make_unique<Game::Systems::RoadSystem>(Game::Systems::RoadSystem()) };
    std::unique_ptr<Game::Systems::BackgroundSystem> backgroundSystem = { std::make_unique<Game::Systems::BackgroundSystem>(Game::Systems::BackgroundSystem()) };

    core.AddSystem(std::move(backgroundSystem));
    core.AddSystem(std::move(roadSystem));
}

int main ()
{
    Game::Core &core = Game::Core::GetInstance();
    LoadSystems(core);
    core.InitGame();
    core.RunGame();
    core.FinishGame();
	return 0;
}
