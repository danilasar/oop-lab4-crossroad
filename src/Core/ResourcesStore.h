#ifndef CPP_04_CROSSROAD_RESOURCESSTORE_H
#define CPP_04_CROSSROAD_RESOURCESSTORE_H

#include <map>
#include <string>
#include "raylib.h"

class ResourcesStore {
    std::map<std::string, Texture> textures;
public:
    Texture &GetTexture(const std::string &texture);

};


#endif //CPP_04_CROSSROAD_RESOURCESSTORE_H
