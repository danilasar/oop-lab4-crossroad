#ifndef CPP_04_CROSSROAD_RESOURCESSTORE_H
#define CPP_04_CROSSROAD_RESOURCESSTORE_H

#include <map>
#include <string>
#include "raylib.h"

namespace Core {
	class ResourcesStore {
		std::map<std::string, Texture> textures;
	public:
		void AddTexture(const std::string &textureName, Texture &texture);
		Texture &GetTexture(const std::string &texture);
        void AddFont(const std::string &fontName, const std::string &path);
	};
}


#endif //CPP_04_CROSSROAD_RESOURCESSTORE_H
