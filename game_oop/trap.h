#pragma once
#include "playerAction.h"

class Trap : public PlayerAction {
private:
	Player* player;
public:
	Trap(Player* player);
	void interact() override;
};