#include "gameM.h"

GameM::GameM(std::string message) {
	this->message = message;
	this->tag = Message::GM;
	this->message = this->tags[tag] + this->message;
}