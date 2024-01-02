#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"
using namespace sf;

class Map {
private:
	Image map_image;
	Texture map_texture;
	Sprite sprite_map;
public:
	Map(std::string FileTexture);
	void setSpriteMap(Field* field, RenderWindow& window);
	Sprite* getSpriteMap();
};
