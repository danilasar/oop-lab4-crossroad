//
// Created by danilasar on 20.12.2024.
//

#include "Menu.h"
#include "../../../build/external/raylib-master/examples/shapes/raygui.h"
#include "../../Core.h"

namespace Game {
    void Menu::InitUI() {

    }
    void Menu::RedrawUI() {

            Game::Core &core = Game::Core::GetInstance();

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
    }
}