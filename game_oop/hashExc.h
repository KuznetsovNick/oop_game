#pragma once
#include "myExc.h"

class HashExc : public MyException {
private:
	int hash;
public:
	HashExc(int hash);
	void printMessage() override;
};