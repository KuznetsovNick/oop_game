#pragma once
#include "field.h"
#include "player.h"

template<int y = 0, int x = 0>

class SpawnPlayer {
public:
	void operator()(Field* field) {
		if (y > field->getHeight() - 1 || x > field->getWidth() || y < 0 || x < 0) {
			if (field->getCell(y, x)->getState() == Cell::IMPAS || field->getCell(y + 1, x)->getState() == Cell::IMPAS ) {
				field->setPlayerCoords(0, 0);
			}
		}
		else field->setPlayerCoords(y * CELL_SIZE, x * CELL_SIZE);
	}
};