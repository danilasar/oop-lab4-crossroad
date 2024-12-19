//
// Created by danilasar on 18.12.2024.
//

#include <map>
#include "ResourcesStore.h"

namespace Core {
    ResourcesStore::ResourcesStore() {
    }
    void ResourcesStore::AddTexture(const std::string &textureName, Texture &texture) {
        textures[textureName] = texture;
    }
    Texture &ResourcesStore::GetTexture(const std::string &texture) {
        return textures[texture];
    }
    void ResourcesStore::AddFont(const std::string &fontName, const std::string &path) {
        Font *f = new Font(path);
        fonts[fontName] = f;
    }
    Font *ResourcesStore::GetFont(const std::string &fontName) {
        return fonts[fontName];
    }
}