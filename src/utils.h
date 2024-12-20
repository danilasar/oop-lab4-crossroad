//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_UTILS_H
#define CPP_04_CROSSROAD_UTILS_H
#include <vector>
#include "raylib.h"


#define WORKSPACE_TOP 0
#define WORKSPACE_LEFT 0
#define WORKSPACE_WIDTH GetScreenWidth() * 0.7
#define WORKSPACE_HEIGHT GetScreenHeight()
#define WORKSPACE_BOTTOM WORKSPACE_TOP + WORKSPACE_HEIGHT
#define WORKSPACE_RIGHT WORKSPACE_LEFT + WORKSPACE_WIDTH
#define WORKSPACE_V_MID (WORKSPACE_BOTTOM - WORKSPACE_TOP) / 2
#define WORKSPACE_H_MID (WORKSPACE_RIGHT - WORKSPACE_LEFT) / 2

#define MENU_TOP 0
#define MENU_LEFT WORKSPACE_RIGHT
#define MENU_RIGHT GetScreenWidth()
#define MENU_BOTTOM GetScreenHeight()
#define MENU_WIDTH GetScreenWidth() - WORKSPACE_WIDTH
#define MENU_HEIGHT GetScreenHeight()
#define MENU_V_MID (MENU_BOTTOM - MENU_TOP) / 2
#define MENU_H_MID (MENU_RIGHT - MENU_LEFT) / 2


#define ROAD_SPACING 1
#define ROAD_LANE_WIDTH 30
#define MARKUP_WIDTH 2
#define MARKUP_LENGTH 10
#define MARKUP_SPACING 5
#define ROAD_LEFT_LANE1 MARKUP_SPACING
#define ROAD_LEFT_LINE (ROAD_LEFT_LANE1 + ROAD_LANE_WIDTH + ROAD_SPACING)
#define ROAD_LEFT_LANE2 (ROAD_LEFT_LINE + MARKUP_WIDTH + ROAD_SPACING)
#define ROAD_CENTRAL_MARKUP1 (ROAD_LEFT_LANE2 + ROAD_LANE_WIDTH + ROAD_SPACING)
#define ROAD_CENTRAL_MARKUP2 (ROAD_CENTRAL_MARKUP1 + MARKUP_WIDTH + ROAD_SPACING)
#define ROAD_RIGHT_LANE1 (ROAD_CENTRAL_MARKUP2 + MARKUP_WIDTH + ROAD_SPACING)
#define ROAD_RIGHT_LINE (ROAD_RIGHT_LANE1 + ROAD_LANE_WIDTH + ROAD_SPACING)
#define ROAD_RIGHT_LANE2 (ROAD_RIGHT_LINE + MARKUP_WIDTH + ROAD_SPACING)
#define ROAD_WIDTH (ROAD_RIGHT_LANE2 + ROAD_LANE_WIDTH + ROAD_SPACING)
#define ROAD_ZEBRA_HEIGHT 30
#define ROAD_ZEBRA_OUTER_HEIGHT (2 * ROAD_SPACING + ROAD_ZEBRA_HEIGHT)


#define ROAD_VERTICAL_X WORKSPACE_H_MID - (ROAD_WIDTH / 2)
#define ROAD_VERTICAL_Y WORKSPACE_TOP
#define ROAD_VERTICAL_W ROAD_WIDTH
#define ROAD_VERTICAL_H WORKSPACE_HEIGHT
#define ROAD_HORIZONTAL_X WORKSPACE_LEFT
#define ROAD_HORIZONTAL_Y WORKSPACE_V_MID - (ROAD_WIDTH / 2)
#define ROAD_HORIZONTAL_W WORKSPACE_WIDTH
#define ROAD_HORIZONTAL_H ROAD_WIDTH

#define ROAD_LEFT_END    ROAD_HORIZONTAL_Y + ROAD_LEFT_LINE
#define ROAD_RIGHT_BEGIN ROAD_VERTICAL_X + ROAD_WIDTH
#define ROAD_TOP_END     ROAD_VERTICAL_Y

#define TRAFFIC_SINGLE_LIGHT_SIZE 24
#define TRAFFIC_LIGHT_HEIGHT TRAFFIC_SINGLE_LIGHT_SIZE * 3
#define TRAFFIC_LIGHT_WIDTH TRAFFIC_SINGLE_LIGHT_SIZE
#define TRAFFIC_LIGHT_SPACING 10
#define TRAFFIC_LIGHT_LEFT_X ROAD_VERTICAL_X - 10
#define TRAFFIC_LIGHT_LEFT_Y ROAD_HORIZONTAL_Y + ROAD_WIDTH + TRAFFIC_LIGHT_SPACING


Vector2 operator*(const Vector2 v, float scalar);

Vector2 operator+(const Vector2 v, const Vector2& other);

/// Алгоритм Бервилла позволяет вычислять точку на кривой Безье, используя произвольное количество контрольных точек.
/// Он работает по принципу линейной интерполяции между контрольными точками.
Vector2 bezier(const std::vector<Vector2>& points, float t);


#endif //CPP_04_CROSSROAD_UTILS_H