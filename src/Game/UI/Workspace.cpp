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
        DrawRectangle(ROAD_VERTICAL_X, ROAD_VERTICAL_Y, ROAD_VERTICAL_W, ROAD_VERTICAL_H, DARKGRAY);
        DrawRectangle(ROAD_HORIZONTAL_X, ROAD_HORIZONTAL_Y, ROAD_HORIZONTAL_W, ROAD_HORIZONTAL_H, DARKGRAY);
        int i = 0;
        while((i + 1) * (MARKUP_LENGTH + MARKUP_SPACING) < ROAD_HORIZONTAL_Y - ROAD_ZEBRA_OUTER_HEIGHT) {
            DrawRectangle(ROAD_VERTICAL_X + ROAD_LEFT_LINE, ROAD_VERTICAL_Y + i * (MARKUP_LENGTH + MARKUP_SPACING), MARKUP_WIDTH, MARKUP_LENGTH, WHITE);
            DrawRectangle(ROAD_VERTICAL_X + ROAD_RIGHT_LINE, ROAD_VERTICAL_Y + i * (MARKUP_LENGTH + MARKUP_SPACING), MARKUP_WIDTH, MARKUP_LENGTH, WHITE);
            ++i;
        }
        i = 0;
        while((i + 1) * (MARKUP_LENGTH + MARKUP_SPACING) < ROAD_VERTICAL_X - ROAD_ZEBRA_OUTER_HEIGHT) {
            DrawRectangle(ROAD_HORIZONTAL_X + i * (MARKUP_LENGTH + MARKUP_SPACING), ROAD_HORIZONTAL_Y + ROAD_LEFT_LINE, MARKUP_LENGTH, MARKUP_WIDTH, WHITE);
            DrawRectangle(ROAD_HORIZONTAL_X + i * (MARKUP_LENGTH + MARKUP_SPACING), ROAD_HORIZONTAL_Y + ROAD_RIGHT_LINE, MARKUP_LENGTH, MARKUP_WIDTH, WHITE);
            ++i;
        }
        i = 0;
        while((i + 1) * (MARKUP_LENGTH + MARKUP_SPACING) < ROAD_VERTICAL_H - (ROAD_HORIZONTAL_Y + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT)) {
            DrawRectangle(ROAD_VERTICAL_X + ROAD_LEFT_LINE, ROAD_HORIZONTAL_Y + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT + i * (MARKUP_LENGTH + MARKUP_SPACING), MARKUP_WIDTH, MARKUP_LENGTH, WHITE);
            DrawRectangle(ROAD_VERTICAL_X + ROAD_RIGHT_LINE, ROAD_HORIZONTAL_Y + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT + i * (MARKUP_LENGTH + MARKUP_SPACING), MARKUP_WIDTH, MARKUP_LENGTH, WHITE);
            ++i;
        }
        i = 0;
        while((i + 1) * (MARKUP_LENGTH + MARKUP_SPACING) < ROAD_HORIZONTAL_W - (ROAD_VERTICAL_X + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT)) {
            DrawRectangle(ROAD_VERTICAL_X + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT + i * (MARKUP_LENGTH + MARKUP_SPACING), ROAD_HORIZONTAL_Y + ROAD_LEFT_LINE, MARKUP_LENGTH, MARKUP_WIDTH, WHITE);
            DrawRectangle(ROAD_VERTICAL_X + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT + i * (MARKUP_LENGTH + MARKUP_SPACING), ROAD_HORIZONTAL_Y + ROAD_RIGHT_LINE, MARKUP_LENGTH, MARKUP_WIDTH, WHITE);
            ++i;
        }
        DrawRectangle(ROAD_VERTICAL_X + ROAD_CENTRAL_MARKUP1, ROAD_VERTICAL_Y, MARKUP_WIDTH, ROAD_HORIZONTAL_Y - ROAD_VERTICAL_Y - ROAD_ZEBRA_OUTER_HEIGHT, WHITE);
        DrawRectangle(ROAD_VERTICAL_X + ROAD_CENTRAL_MARKUP2, ROAD_VERTICAL_Y, MARKUP_WIDTH, ROAD_HORIZONTAL_Y - ROAD_VERTICAL_Y - ROAD_ZEBRA_OUTER_HEIGHT, WHITE);
        DrawRectangle(ROAD_VERTICAL_X + ROAD_CENTRAL_MARKUP1, ROAD_HORIZONTAL_Y + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT, MARKUP_WIDTH, ROAD_VERTICAL_Y + ROAD_VERTICAL_H - ROAD_HORIZONTAL_Y - ROAD_ZEBRA_OUTER_HEIGHT, WHITE);
        DrawRectangle(ROAD_VERTICAL_X + ROAD_CENTRAL_MARKUP2, ROAD_HORIZONTAL_Y + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT, MARKUP_WIDTH, ROAD_VERTICAL_Y + ROAD_VERTICAL_H - ROAD_HORIZONTAL_Y - ROAD_ZEBRA_OUTER_HEIGHT, WHITE);
        DrawRectangle(ROAD_HORIZONTAL_X, ROAD_HORIZONTAL_Y + ROAD_CENTRAL_MARKUP1, ROAD_VERTICAL_X - ROAD_HORIZONTAL_X - ROAD_ZEBRA_OUTER_HEIGHT, MARKUP_WIDTH, WHITE);
        DrawRectangle(ROAD_HORIZONTAL_X, ROAD_HORIZONTAL_Y + ROAD_CENTRAL_MARKUP2, ROAD_VERTICAL_X - ROAD_HORIZONTAL_X - ROAD_ZEBRA_OUTER_HEIGHT, MARKUP_WIDTH, WHITE);
        DrawRectangle(ROAD_VERTICAL_X + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT, ROAD_HORIZONTAL_Y + ROAD_CENTRAL_MARKUP1, ROAD_HORIZONTAL_W - ROAD_VERTICAL_X - ROAD_ZEBRA_OUTER_HEIGHT, MARKUP_WIDTH, WHITE);
        DrawRectangle(ROAD_VERTICAL_X + ROAD_WIDTH + ROAD_ZEBRA_OUTER_HEIGHT, ROAD_HORIZONTAL_Y + ROAD_CENTRAL_MARKUP2, ROAD_HORIZONTAL_W - ROAD_VERTICAL_X - ROAD_ZEBRA_OUTER_HEIGHT, MARKUP_WIDTH, WHITE);
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
        t += 0.1f * core.deltaTime; // Шаг можно регулировать для изменения скорости
    }
} // Game