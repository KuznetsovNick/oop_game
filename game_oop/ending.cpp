#include "ending.h"

Ending::Ending(Player* player) : player(player) {};


void Ending::interact() {
	if (player->getHealth() == 0) {
		player->setIsAlive(false);
	}
	if (player->getWin() == true) {
		player->setIsAlive(false);
	}
}