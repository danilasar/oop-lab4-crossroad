//
// Created by danilasar on 18.12.2024.
//

#include "ResourcesStore.h"
#include <map>

namespace Core {
    void ResourcesStore::AddTexture(const std::string &textureName, Texture &texture) {
        textures[textureName] = texture;
    }
    Texture &ResourcesStore::GetTexture(const std::string &texture) {
        return textures[texture];
    }
}