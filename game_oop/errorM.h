#pragma once
#include "message.h"
class ErrorM : public Message {
public:
	ErrorM(std::string message);
};