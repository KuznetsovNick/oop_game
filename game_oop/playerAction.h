#pragma once
#include "action.h"
#include "player.h"

class PlayerAction : public Action {
public:
	virtual void interact() = 0;
 };