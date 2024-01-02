#pragma once
#include "fieldAction.h"

class Exit : public FieldAction {
private:
	Cell* cell;
	Player* player;
	Action* action;
	Action* clear;
public:
	Exit(Cell* cell, Player* player, Action* action, Action* clear);
	void interact() override;
};