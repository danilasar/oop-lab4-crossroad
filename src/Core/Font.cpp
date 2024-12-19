//
// Created by danilasar on 20.12.2024.
//
#include <algorithm>
#include <array>
#include <string>
#include "Font.h"

int sizes[5];
int codepoints[480];

namespace Core {
    Font::Font(const std::string &path) {
        static bool preInitialised;
        if(!preInitialised) {
            sizes[0] = FONT_SIZE_TINY;
            sizes[1] = FONT_SIZE_SMALL;
            sizes[2] = FONT_SIZE_MEDIUM;
            sizes[3] = FONT_SIZE_BIG;
            sizes[4] = FONT_SIZE_LARGE;
            for (int i = 0; i < 480; i++) {
                int value = i + 32; // Начинаем с 32
                codepoints[i] = (value > 127) ? (0x380 + i) : value;
            }
            preInitialised = true;
        }
        for(size_t i = 0; i < 5; ++i) {
            variants[i] = LoadFontEx(path.c_str(), sizes[i], codepoints, sizeof codepoints); // (std::string("fonts/") + 
        }
    }

    ::Font &Font::GetFont(int size) {
        int left = 0;
        int right = sizeof sizes - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sizes[mid] == size) {
                index = mid;
                break;
            }
            if (sizes[mid] < size) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(index == -1) {
            return GetFont(FONT_SIZE_DEFAULT);
        }
        return variants[index];
    }
}