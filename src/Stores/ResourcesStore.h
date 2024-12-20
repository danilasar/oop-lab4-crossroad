#ifndef CPP_04_CROSSROAD_RESOURCESSTORE_H
#define CPP_04_CROSSROAD_RESOURCESSTORE_H

#include <map>
#include <memory>
#include <string>
#include "raylib.h"
#include "../Font.h"


namespace Game {
	class ResourcesStore {
		std::map<std::string, Texture> textures;
        std::map<std::string, Font*> fonts;
        int defaultCodepoints[480];
	public:
        ResourcesStore();
		void AddTexture(const std::string &textureName, Texture &texture);
		Texture &GetTexture(const std::string &texture);
        void AddFont(const std::string &fontName, const std::string &path);
        Font *GetFont(const std::string &fontName);
	};
}


#endif //CPP_04_CROSSROAD_RESOURCESSTORE_H
