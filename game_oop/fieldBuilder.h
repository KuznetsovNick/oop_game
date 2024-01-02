#pragma once
#include "field.h"
#include "random"
#include "actionFactory.h"
#include "player.h"

class FieldBuilder {
public:
	Field* createField(int width, int height);
	void createStates(Field* field);
	void fillActions(Field* field, ActionFactory* factory, Player* player);
};