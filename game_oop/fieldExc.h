#pragma once
#include "myExc.h"

class FieldExc: public MyException {
private:
	int height;
	int width;
public:
	FieldExc(int height, int width);
	void printMessage() override;
};