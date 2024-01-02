#pragma once
#include "myExc.h"
using namespace std;

class Decorator : public MyException {
protected:
	MyException* decorated_obj;
public:
	Decorator(MyException*);
	void printMessage() override;
};