#pragma once
#include "decorator.h"

class HashDecorator : public Decorator {
public:
	HashDecorator(MyException* exc);
	~HashDecorator();
	void printMessage() override;
};