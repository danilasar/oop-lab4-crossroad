//
// Created by danilasar on 18.12.2024.
//

#include "Core.h"
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir


namespace Game {
    Core &Core::GetInstance() {
        static Core* instance_ptr = nullptr;
        if(instance_ptr == nullptr)  {
            instance_ptr = new Core();
        }
        return *instance_ptr;
    }
    void Core::InitGame() {

        // Tell the window to use vsync and work on high DPI displays
        SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

        // Create the window and OpenGL context
        InitWindow(1280, 800, "Hello Raylib");

        // Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
        SearchAndSetResourceDir("resources");
    }

    void Core::FinishGame() {
        // destroy the window and cleanup the OpenGL context
        CloseWindow();
    }
} // Game