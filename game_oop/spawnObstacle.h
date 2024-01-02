#pragma once
#include "field.h"

template<int number>
class SpawnObstacle {
public:
	void operator()(Field* field) {
		for (int i = 1; i < field->getHeight(); i++) {
			for (int j = 1; j < field->getWidth(); j++) {
				if (i == j && i % number == 0) {
					field->getCell(i, j)->setState(Cell::IMPAS);
				}
			}
		}
	}
};