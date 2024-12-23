/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script 

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

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
    core.InitGame();
    LoadSystems(core);

    core.RunGame();

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);

    core.FinishGame();
	return 0;
}
