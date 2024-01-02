#pragma once
#include "field.h"
#include "coin.h"
#include "clear.h"
#include "trap.h"
#include "ending.h"
#include "exit.h"
#include "door.h"

class Field;

class ActionFactory {
public:
	enum ACTS {COIN, TRAP, CLEAR, ENDING, EXIT, DOOR};
	Action* createAction(Field* field, Cell* cell, Player* player, ACTS act);
};