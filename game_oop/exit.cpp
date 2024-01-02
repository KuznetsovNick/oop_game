#include "exit.h"

Exit::Exit (Cell* cell, Player* player, Action* action, Action* clear) : cell(cell), player(player), action(action), clear(clear) {};

void Exit::interact() {
	if (player->getCoins() == 3) {
		cell->setState(Cell::EXIT);
		cell->setAction(action);
		cell->setClearAction(clear);
	}
}