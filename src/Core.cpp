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
        float t = 0.0f;
        Vector2 p0 = {100, 100}; // Начальная точка
        Vector2 p1 = {150, 50};  // Первая контрольная точка
        Vector2 p2 = {200, 150}; // Вторая контрольная точка
        Vector2 p3 = {250, 100}; // Конечная точка
        Game::Core& core = Game::Core::GetInstance();
        // game loop
        while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
        {
            double newTime = GetTime();
            deltaTime = newTime - lastTime;
            lastTime = newTime;
            // Update
            //----------------------------------------------------------------------------------
            Rectangle rec = { ((float)GetScreenWidth() - core.state->width - 250)/2, (GetScreenHeight() - core.state->height)/2.0f, (float)core.state->width, (float)core.state->height };
            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawLine(560, 0, 560, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
            DrawRectangle(600, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));

            if (core.state->drawRect) DrawRectangleRec(rec, Fade(GOLD, 0.6f));
            if (core.state->drawRoundedRect) DrawRectangleRounded(rec, core.state->roundness, (int)core.state->segments, Fade(MAROON, 0.2f));
            if (core.state->drawRoundedLines) DrawRectangleRoundedLinesEx(rec, core.state->roundness, (int)core.state->segments, core.state->lineThick, Fade(MAROON, 0.4f));


            // Draw GUI controls
            //------------------------------------------------------------------------------
            GuiSliderBar((Rectangle){ 640, 40, 105, 20 }, "Ширина", TextFormat("%.2f", core.state->width), &(core.state->width), 0, (float)GetScreenWidth() - 300);
            GuiSliderBar((Rectangle){ 640, 70, 105, 20 }, "Высота", TextFormat("%.2f", core.state->height), &core.state->height, 0, (float)GetScreenHeight() - 50);
            GuiSliderBar((Rectangle){ 640, 140, 105, 20 }, "Скругление", TextFormat("%.2f", core.state->roundness), &core.state->roundness, 0.0f, 1.0f);
            GuiSliderBar((Rectangle){ 640, 170, 105, 20 }, "Thickness", TextFormat("%.2f", core.state->lineThick), &core.state->lineThick, 0, 20);
            GuiSliderBar((Rectangle){ 640, 240, 105, 20}, "Сегменты", TextFormat("%.2f", core.state->segments), &core.state->segments, 0, 60);

            GuiCheckBox((Rectangle){ 640, 320, 20, 20 }, "DrawRoundedRect", &core.state->drawRoundedRect);
            GuiCheckBox((Rectangle){ 640, 350, 20, 20 }, "DrawRoundedLines", &core.state->drawRoundedLines);
            GuiCheckBox((Rectangle){ 640, 380, 20, 20}, "DrawRectабо", &core.state->drawRect);
            //------------------------------------------------------------------------------

            Vector2 position = bezier({p0, p1, p2, p3}, t);

            // Рисуем прямоугольник на позиции (position.x, position.y)
            DrawRectangle(position.x - 10, position.y - 10, 20, 20, RED);
            DrawRectangle(WORKSPACE_H_MID - 10, WORKSPACE_BOTTOM - 20, 20, 20, RED);
            DrawRectangle(WORKSPACE_H_MID - 10, WORKSPACE_TOP + 20, 20, 20, GREEN);
            DrawRectangle(WORKSPACE_LEFT + 20, WORKSPACE_V_MID - 10, 20, 20, BLUE);
            DrawRectangle(WORKSPACE_RIGHT - 10, WORKSPACE_V_MID - 10, 20, 20, YELLOW);
            DrawRectangle(WORKSPACE_H_MID - 10, WORKSPACE_V_MID - 10, 20, 20, BROWN);

            // Увеличиваем t для следующей итерации
            t += 0.1f * deltaTime; // Шаг можно регулировать для изменения скорости


            //DrawTextEx(myFont, TextFormat("MODE: %s", (segments >= 4)? "MANUAL" : "AUTO"), (Vector2){ 640, 280 }, 24, 10, (segments >= 4)? MAROON : DARKGRAY);

            DrawFPS(10, 10);

            EndDrawing();
            //----------------------------------------------------------------------------------
        }
    }

    void Core::FinishGame() {
        // destroy the window and cleanup the OpenGL context
        CloseWindow();
    }
} // Game