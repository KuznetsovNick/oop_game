#pragma once
#include "fieldAction.h"

class Clear : public FieldAction {
private:
	Cell* cell;
public:
	Clear(Cell* cell);
	void interact() override;
};