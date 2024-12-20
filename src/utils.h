//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_UTILS_H
#define CPP_04_CROSSROAD_UTILS_H
#include <vector>
#include "raylib.h"


Vector2 operator*(const Vector2 v, float scalar);

Vector2 operator+(const Vector2 v, const Vector2& other);

/// Алгоритм Бервилла позволяет вычислять точку на кривой Безье, используя произвольное количество контрольных точек.
/// Он работает по принципу линейной интерполяции между контрольными точками.
Vector2 bezier(const std::vector<Vector2>& points, float t);


#endif //CPP_04_CROSSROAD_UTILS_H
