#include "fieldBuilder.h"
#include <iostream>

Field* FieldBuilder::createField(int width, int height) {
	Field* field = new Field(width, height);
	for (int i = 0; i < height; i++) {
		field->getField()->emplace_back();
		for (int j = 0; j < width; j++) {
			field->getField()->at(i).emplace_back();
		}
	}
	return field;
}

void FieldBuilder::createStates(Field* field) {
	field->getField()->at(0).at(0).setPlayerPrecence(true);
	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++) {
			if (i > 2 || j > 2) {
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> distrib(1, 15);

				switch (distrib(gen)) {
				case 1:
					field->getCell(i, j)->setState(Cell::IMPAS);
					break;
				case 2:
					field->getCell(i, j)->setState(Cell::COINS);
					break;
				case 3:
					field->getCell(i, j)->setState(Cell::TRAP);
					break;
				default:
					break;
				}
			}
		}
	}
}

void FieldBuilder::fillActions(Field* field, ActionFactory* factory, Player* player) {
	for (int i = 0; i < field->getHeight(); i++) {
		for (int j = 0; j < field->getWidth(); j++) {
			switch (field->getCell(i, j)->getState()) {
			case 2:
				field->getCell(i, j)->setAction(factory->createAction(field, field->getCell(i, j), player, ActionFactory::COIN));
				field->getCell(i, j)->setClearAction(factory->createAction(field, field->getCell(i, j), player, ActionFactory::CLEAR));
				break;
			case 3:
				field->getCell(i, j)->setAction(factory->createAction(field, field->getCell(i, j), player, ActionFactory::TRAP));
				field->getCell(i, j)->setClearAction(factory->createAction(field, field->getCell(i,j), player, ActionFactory::CLEAR));
				break;
			}
		}
	}
}