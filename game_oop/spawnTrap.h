#pragma once
#include "field.h"

template<int number>
class SpawnTrap {
public:
	void operator()(Field* field) {
		for (int i = 1; i < field->getHeight(); i++) {
			for (int j = 1; j < field->getWidth(); j++) {
				if (i != j && j % number * 9 == 0 && i % 2 == 0) {
					field->getCell(i, j)->setState(Cell::TRAP);
					field->getCell(i, j)->setAction(new Trap(field->getPlayer()));
					field->getCell(i, j)->setClearAction(new Clear(field->getCell(i, j)));
				}
			}
		}
	}
};