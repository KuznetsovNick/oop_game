#pragma once
#include <iostream>
#include "message.h"

class Logger {
public:
	virtual void print(Message* msg) = 0;
};                             