#pragma once
#include "spawnCoin.h"
#include "spawnTrap.h"
#include "spawnPlayer.h"
#include "spawnDoor.h"
#include "spawnObstacle.h"
#include "sizeField.h"

template<class... Rules>
class FieldGenerator {
public:
	Field* fill() {
		Field* field = new Field();
		(Rules()(field), ...);
		return field;
	}
};