//
// Created by danilasar on 20.12.2024.
//

#include "UI.h"
#include "raygui.h"
#include "../Core.h"
#include "../utils.h"
namespace Game {
    UI::UI() {
        menu = new Menu();
        workspace = new Workspace();
    }

    void UI::InitUI() {

    }

    void UI::RedrawUI() {
            menu->RedrawUI();
            workspace->RedrawUI();
            //DrawTextEx(myFont, TextFormat("MODE: %s", (segments >= 4)? "MANUAL" : "AUTO"), (Vector2){ 640, 280 }, 24, 10, (segments >= 4)? MAROON : DARKGRAY);

            DrawFPS(10, 10);
    }
} // Game