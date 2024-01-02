#pragma once
#include "playerAction.h"

class Coin : public PlayerAction {
private:
	Player* player;
public:
	Coin(Player* player);
	void interact() override;
};