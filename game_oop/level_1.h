#pragma once
#include "level.h"


class Level_1: public Level {
public:
	Field* generateLevel() override;
};