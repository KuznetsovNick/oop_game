#include "cell.h"

Cell::Cell() {
	state = Cell::PASS;
	this->start = false;
	this->player_presence = false;
	this->action = nullptr;
	this->clear_action = nullptr;
};

Cell::Cell(const Cell& obj) {
	state = obj.state;
	start = obj.start;
	player_presence = obj.player_presence;
	action = obj.action;
	clear_action = obj.clear_action;
}
Cell& Cell::operator= (const Cell& obj) {
	if (this != &obj) {
		state = obj.state;
		start = obj.start;
		player_presence = obj.player_presence;
		action = obj.action;
		clear_action = obj.clear_action;
	}
	return *this;
}

Cell::STATES Cell::getState() const {
	return this->state;
}

void Cell::setState(STATES state) {
	this->state = state;
}

void Cell::setStart(bool condition) {
	this->start = condition;
}

bool Cell::getStart() const {
	return this->start;
}


bool Cell::IsPlayerOnCell() const {
	return player_presence;
}

void Cell::setPlayerPrecence(bool player_presence) {
	this->player_presence = player_presence;
}

void Cell::setAction(Action* action) {
	this->action = action;
}

Action* Cell::getAction() {
	return this->action;
}

void Cell::setClearAction(Action* action) {
	this->clear_action = action;
}

Action* Cell::getClearAction() {
	return this->clear_action;
}

int Cell::reactionOnPlayer() {
	if (state != PASS) {
		action->interact();
		clear_action->interact();
		return 1;
	}
	return 0;
}