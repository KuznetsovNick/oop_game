#pragma once
#include "playerAction.h"

class Ending : public PlayerAction {
	Player* player;
public:
	Ending(Player* player);
	void interact() override;
};