#pragma once
#include "decorator.h"

class FieldDecorator : public Decorator {
public:
	FieldDecorator(MyException* exc);
	~FieldDecorator();
	void printMessage() override;
};