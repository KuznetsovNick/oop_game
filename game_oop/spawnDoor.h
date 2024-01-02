#pragma once
#include "field.h"

template<int number>
class SpawnDoor {
public:
	void operator()(Field* field) {
		int cur = number % field->getHeight();
		cur = number % field->getWidth();
		field->getCell(cur, cur)->setState(Cell::EXIT);
		field->getCell(cur, cur)->setAction(new Door(field->getPlayer()));
		field->getCell(cur, cur)->setClearAction(new Clear(field->getCell(cur, cur)));
	}
};