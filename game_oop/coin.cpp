#include "coin.h"

Coin::Coin(Player* player) : player(player) {};

void Coin::interact() {
	player->setCoins(player->getCoins() + 1);
}