#pragma once
#include "loggerPool.h"
#include "player.h"
#include "field.h"
#include "action.h"
#include "coin.h"
#include "trap.h"
#include "ending.h"
#include "exit.h"
#include "random"

class ActionTracker {
private:
	Action* ending;
	Action* exit;
	Message* coinM;
	Message* trapM;
public:
	ActionTracker(Action* ending, Action* exit);
	~ActionTracker();
	void track(Player* player, Field* field, ActionFactory* factory, LoggerPool* pool);
};