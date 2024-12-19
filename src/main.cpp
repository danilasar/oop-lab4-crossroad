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

#include "Core/Core.h"

int main ()
{
    Game::Core &core = Game::Core::GetInstance();
    core.InitGame();

    float roundness = 0.2f;
    float width = 200.0f;
    float height = 100.0f;
    float segments = 0.0f;
    float lineThick = 1.0f;

    bool drawRect = false;
    bool drawRoundedRect = true;
    bool drawRoundedLines = false;

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
    int codepoints[480];
    for (int i = 0; i < 480; i++) {
        int value = i + 32; // Начинаем с 32
        codepoints[i] = (value > 127) ? (0x380 + i) : value;
    }
    Font myFont = LoadFontEx("Nunito-Bold.ttf", 24, codepoints, 480);

    GuiSetFont(myFont);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
        // Update
        //----------------------------------------------------------------------------------
        Rectangle rec = { ((float)GetScreenWidth() - width - 250)/2, (GetScreenHeight() - height)/2.0f, (float)width, (float)height };
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawLine(560, 0, 560, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(600, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));

        if (drawRect) DrawRectangleRec(rec, Fade(GOLD, 0.6f));
        if (drawRoundedRect) DrawRectangleRounded(rec, roundness, (int)segments, Fade(MAROON, 0.2f));
        if (drawRoundedLines) DrawRectangleRoundedLinesEx(rec, roundness, (int)segments, lineThick, Fade(MAROON, 0.4f));


        // Draw GUI controls
        //------------------------------------------------------------------------------
        GuiSliderBar((Rectangle){ 640, 40, 105, 20 }, "Ширина", TextFormat("%.2f", width), &width, 0, (float)GetScreenWidth() - 300);
        GuiSliderBar((Rectangle){ 640, 70, 105, 20 }, "Высота", TextFormat("%.2f", height), &height, 0, (float)GetScreenHeight() - 50);
        GuiSliderBar((Rectangle){ 640, 140, 105, 20 }, "Скругление", TextFormat("%.2f", roundness), &roundness, 0.0f, 1.0f);
        GuiSliderBar((Rectangle){ 640, 170, 105, 20 }, "Thickness", TextFormat("%.2f", lineThick), &lineThick, 0, 20);
        GuiSliderBar((Rectangle){ 640, 240, 105, 20}, "Сегменты", TextFormat("%.2f", segments), &segments, 0, 60);

        GuiCheckBox((Rectangle){ 640, 320, 20, 20 }, "DrawRoundedRect", &drawRoundedRect);
        GuiCheckBox((Rectangle){ 640, 350, 20, 20 }, "DrawRoundedLines", &drawRoundedLines);
        GuiCheckBox((Rectangle){ 640, 380, 20, 20}, "DrawRectабо", &drawRect);
        //------------------------------------------------------------------------------


        DrawTextEx(myFont, TextFormat("MODE: %s", (segments >= 4)? "MANUAL" : "AUTO"), (Vector2){ 640, 280 }, 24, 10, (segments >= 4)? MAROON : DARKGRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

    core.FinishGame();
	return 0;
}
