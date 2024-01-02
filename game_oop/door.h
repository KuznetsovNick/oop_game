#pragma once
#include "playerAction.h"

class Door : public PlayerAction {
private:
	Player* player;
public:
	Door(Player* player);
	void interact() override;
};
