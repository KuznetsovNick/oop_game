#include "trap.h"
Trap::Trap(Player* player) : player(player) {};

void Trap::interact() {
	player->setHealth(player->getHealth() - 1);
}