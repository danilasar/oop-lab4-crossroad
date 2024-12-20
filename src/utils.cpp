//
// Created by danilasar on 20.12.2024.
//

#include "utils.h"

Vector2 operator*(const Vector2 v, float scalar) {
    return {v.x * scalar, v.y * scalar};
}

Vector2 operator+(const Vector2 v, const Vector2& other) {
    return {v.x + other.x, v.y + other.y};
}

Vector2 bezier(const std::vector<Vector2>& points, float t) {
    int n = points.size();
    std::vector<Vector2> temp = points;

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            temp[i] = temp[i] * (1 - t) + temp[i + 1] * t;
        }
    }

    return temp[0];
}