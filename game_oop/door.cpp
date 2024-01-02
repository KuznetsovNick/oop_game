#include "door.h"
Door::Door(Player* player) : player(player) {};

void Door::interact() {
	player->setWin(true);
}