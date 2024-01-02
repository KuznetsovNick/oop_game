#include "level_1.h"

Field* Level_1::generateLevel() {
	try {
		FieldGenerator<SizeField<10, 10>, SpawnCoin<3>, SpawnTrap<7>, SpawnObstacle<2>, SpawnDoor<5>, SpawnPlayer<0, 0>> gen;
		return gen.fill();
	}
	catch (MyException& ex) {
		ex.printMessage();
		FieldGenerator<SizeField<10, 10>, SpawnCoin<3>, SpawnTrap<7>, SpawnObstacle<2>, SpawnDoor<5>, SpawnPlayer<0, 0>> gen;
		return gen.fill();
	}
}