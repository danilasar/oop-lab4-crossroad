//
// Created by danilasar on 18.12.2024.
//

#include "Core.h"
#include "raylib.h"
#include "raygui.h"
#include "Font.h"
#include "utils.h"

#include "resource_dir.h"    // utility header for SearchAndSetResourceDir

namespace Game {
    Core &Core::GetInstance() {
        static Core* instance_ptr = nullptr;
        if(instance_ptr == nullptr)  {
            instance_ptr = new Core();
        }
        return *instance_ptr;
    }
    void Core::InitGame() {
        state = new GameState();
        // Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
        SearchAndSetResourceDir("resources");
        resources = new ResourcesStore();
        ui = new UI();
        ui->InitUI();

        // Tell the window to use vsync and work on high DPI displays
        SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

        // Create the window and OpenGL context
        InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Симулятор перекрёстка");

        //Texture wabbit = LoadTexture("wabbit_alpha.png");
        //resources->AddTexture("wabbit", wabbit);
        resources->AddFont("default", "Nunito-Bold.ttf");
        Font *defaultFont = resources->GetFont("default");
        ::Font font = defaultFont->GetFont(FONT_SIZE_MEDIUM);

        GuiSetFont(font);
        GuiSetStyle(DEFAULT, TEXT_SIZE, FONT_SIZE_DEFAULT);
    }

    void Core::RunGame() {
        Game::Core& core = Game::Core::GetInstance();
        // game loop
        while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
        {
            double newTime = GetTime();
            deltaTime = newTime - lastTime;
            lastTime = newTime;
            // Update
            //----------------------------------------------------------------------------------
            
            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ui->RedrawUI();

            EndDrawing();
            //----------------------------------------------------------------------------------
        }
    }

    void Core::FinishGame() {
        // destroy the window and cleanup the OpenGL context
        CloseWindow();
    }
} // Game