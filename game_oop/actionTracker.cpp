#include "actionTracker.h"


ActionTracker::ActionTracker(Action* ending, Action* exit){
	this->ending = ending;
	this->exit = exit;
	coinM = new CoinM;
	trapM = new TrapM;
}

ActionTracker::~ActionTracker() {
	//delete[] coinM;
	//delete[] trapM;
}


void ActionTracker::track(Player* player, Field* field, ActionFactory* factory, LoggerPool* pool) {
	int k1;

	int y0 = int(field->getPlayerCoords().first) / CELL_SIZE;
	int x0 = int(field->getPlayerCoords().second) / CELL_SIZE;

	int y1, x1;
	if (int((field->getPlayerCoords().first + (SPRITE_H*2 - 2)) / CELL_SIZE) > field->getHeight()) y1 = field->getHeight();
	else y1 = int((field->getPlayerCoords().first + SPRITE_H * 2 - 2) / CELL_SIZE);

	if (int((field->getPlayerCoords().second + (CELL_SIZE * 2 - SPRITE_W - 2)) / CELL_SIZE) > field->getWidth()) x1 = field->getWidth();
	else x1 = int((field->getPlayerCoords().second + (CELL_SIZE * 2 - SPRITE_W - 2)) / CELL_SIZE);


	for (int i = y0; i < y1; i++) {
		for (int j = x0; j < x1; j++) {
			Cell::STATES cur = field->getCell(i, j)->getState();
			k1 = field->getCell(i, j)->reactionOnPlayer();
			if (k1) {
				switch (cur) {
				case Cell::COINS:
					pool->logging(coinM);
					break;
				case Cell::TRAP:
					pool->logging(trapM);
					break;
				}
			}
			//exit->interact();
			ending->interact();

		}
	}
}