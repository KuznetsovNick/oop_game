#include "level_2.h"

Field* Level_2::generateLevel() {
	FieldGenerator<SizeField<15, 15>, SpawnCoin<5>, SpawnTrap<4>, SpawnObstacle<1>, SpawnDoor<10>, SpawnPlayer<5, 0>> gen;
	return gen.fill();
}