#pragma once
#include "decorator.h"

class FileDecorator : public Decorator {
public:
	FileDecorator(MyException* exc);
	~FileDecorator();
	void printMessage() override;
};