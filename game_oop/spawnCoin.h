#pragma once
#include "field.h"

template<int number>
class SpawnCoin {
public:
	void operator()(Field* field) {
		for (int i = 1; i < field->getHeight(); i++) {
			for (int j = 1; j < field->getWidth(); j++) {
				if (i != j && j % number * 8 == 0 && i % 2 == 1) {
					field->getCell(i, j)->setState(Cell::COINS);
					field->getCell(i, j)->setAction(new Coin(field->getPlayer()));
					field->getCell(i, j)->setClearAction(new Clear(field->getCell(i, j)));
				}
			}
		}
	}
};