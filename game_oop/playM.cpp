#include "playM.h"

PlayM::PlayM(std::string message) {
	this->message = message;
	this->tag = Message::PM;
	this->message = this->tags[tag] + this->message;
}