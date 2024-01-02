#pragma once
#include "player.h"
#include "playerAction.h"

class Cell {

public:
	Cell(const Cell& obj);
	Cell& operator= (const Cell& obj);
	enum STATES { IMPAS, PASS, COINS, TRAP, EXIT};
	Cell();
	bool getStart() const;
	void setStart(bool condition);

	STATES getState() const;
	void setState(STATES state);

	bool IsPlayerOnCell() const;
	void setAction(Action* action);
	Action* getAction();
	void setClearAction(Action* action);
	Action* getClearAction();
	void setPlayerPrecence(bool player_presence);
	int reactionOnPlayer();

private:
	STATES state;
	bool start;
	bool player_presence;
	Action* action;
	Action* clear_action;
};

