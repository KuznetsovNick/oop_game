#pragma once
#include "logger.h"

class ConsoleLogger : public Logger {
public:
	void print(Message* msg) override;	
};