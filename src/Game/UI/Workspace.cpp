//
// Created by danilasar on 20.12.2024.
//

#include "Workspace.h"
#include "../../../build/external/raylib-master/examples/shapes/raygui.h"
#include "../../utils.h"
#include "../../Core.h"


float t = 0.0f;
Vector2 p0 = {100, 100}; // Начальная точка
Vector2 p1 = {150, 50};  // Первая контрольная точка
Vector2 p2 = {200, 150}; // Вторая контрольная точка
Vector2 p3 = {250, 100}; // Конечная точка
//#define ROAD_WIDTH ROAD_SPACING * 9 + ROAD_LANE_WIDTH * 4 + MARKUP_WIDTH * 4
namespace Game {
    void Workspace::InitUI() {

    }

    void Workspace::DrawRoad() {
    }

    void Workspace::RedrawUI() {
        Game::Core &core = Game::Core::GetInstance();
        ClearBackground(RAYWHITE);

        DrawRoad();
        core.state->rec = { ((float)GetScreenWidth() - core.state->width - 250)/2, (GetScreenHeight() - core.state->height)/2.0f, (float)core.state->width, (float)core.state->height };

        DrawLine(560, 0, 560, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(600, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));

        if (core.state->drawRect) DrawRectangleRec(core.state->rec, Fade(GOLD, 0.6f));
        if (core.state->drawRoundedRect) DrawRectangleRounded(core.state->rec, core.state->roundness, (int)core.state->segments, Fade(MAROON, 0.2f));
        if (core.state->drawRoundedLines) DrawRectangleRoundedLinesEx(core.state->rec, core.state->roundness, (int)core.state->segments, core.state->lineThick, Fade(MAROON, 0.4f));

        Vector2 position = bezier({p0, p1, p2, p3}, t);

        // Рисуем прямоугольник на позиции (position.x, position.y)
        DrawRectangle(position.x - 10, position.y - 10, 20, 20, RED);
        DrawRectangle(WORKSPACE_H_MID - 10, WORKSPACE_BOTTOM - 20, 20, 20, RED);
        DrawRectangle(WORKSPACE_H_MID - 10, WORKSPACE_TOP + 20, 20, 20, GREEN);
        DrawRectangle(WORKSPACE_LEFT + 20, WORKSPACE_V_MID - 10, 20, 20, BLUE);
        DrawRectangle(WORKSPACE_RIGHT - 10, WORKSPACE_V_MID - 10, 20, 20, YELLOW);
        DrawRectangle(WORKSPACE_H_MID - 10, WORKSPACE_V_MID - 10, 20, 20, BROWN);

        

        // Увеличиваем t для следующей итерации
        t += 0.1f * core.GetDeltaTime(); // Шаг можно регулировать для изменения скорости
    }
} // Game