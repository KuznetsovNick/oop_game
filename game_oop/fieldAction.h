#pragma once
#include "action.h"
#include "cell.h"

class FieldAction : public Action {
public:
	virtual void interact() = 0;
};