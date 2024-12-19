//
// Created by danilasar on 20.12.2024.
//

#ifndef CPP_04_CROSSROAD_FONT_H
#define CPP_04_CROSSROAD_FONT_H

#include <string>
#include "raylib.h"

#define FONT_SIZE_LARGE  48
#define FONT_SIZE_BIG    32
#define FONT_SIZE_MEDIUM 24
#define FONT_SIZE_SMALL  18
#define FONT_SIZE_TINY   12
#define FONT_SIZES_COUNT 5
#define FONT_SIZE_DEFAULT FONT_SIZE_MEDIUM

namespace Core {
    class Font {
        ::Font variants[FONT_SIZES_COUNT];
    public:
        Font(const std::string &path);
        ::Font &GetFont(int size = FONT_SIZE_DEFAULT);
    };
}


#endif //CPP_04_CROSSROAD_FONT_H
