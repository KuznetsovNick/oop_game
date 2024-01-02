#include "drawField.h"
#include <fstream>
#include <iostream>
using namespace sf;


Map::Map(std::string FileTexture) {
	this->map_image.loadFromFile(FileTexture);
	this->map_texture.loadFromImage(map_image);
	this->sprite_map.setTexture(map_texture);
}

void Map::setSpriteMap(Field* field, RenderWindow& window) {
	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++)
		{
			if (field->getCell(i, j)->getState() == 0) {
				sprite_map.setTextureRect(IntRect(30 + 1, 0 + 1, 30, 30));
			}
			if (field->getCell(i, j)->getState() == 1) {
				sprite_map.setTextureRect(IntRect(0 + 1, 0 + 1, 30, 30));
			}
			if (field->getCell(i, j)->getState() == 2) {
				sprite_map.setTextureRect(IntRect(60 + 1, 0 + 1, 30, 30));
			}
			if (field->getCell(i, j)->getState() == 3) {
				sprite_map.setTextureRect(IntRect(90 + 1, 0 + 1, 30, 30));
			}
			if(field->getCell(i, j)->getState() == 4) {
				sprite_map.setTextureRect(IntRect(120 + 1, 0 + 1, 30, 30));
			}

			sprite_map.setPosition(j * 30, i * 30);

			window.draw(sprite_map);
		}
	}
}

Sprite* Map::getSpriteMap() {
	return &this->sprite_map;
}
