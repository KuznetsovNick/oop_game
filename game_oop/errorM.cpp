#include "errorM.h"

ErrorM::ErrorM(std::string message) {
	this->message = message;
	this->tag = Message::EM;
	this->message = this->tags[tag] + this->message;
}