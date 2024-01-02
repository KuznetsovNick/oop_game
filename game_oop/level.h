#pragma once
#include "field.h"
#include "fieldGenerator.h"
#include <iostream>

class Level {
public:
	virtual Field* generateLevel() = 0;
};