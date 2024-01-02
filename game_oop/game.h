#pragma once
#include "game.h"
#include "creator.h"
#include "loggerPool.h"

class Game {
private:
	Message* startM;
	Message* endM;
	Message* smallM;
public:
	Game();
	~Game();
	void start();
};