#include "hashDec.h"

HashDecorator::HashDecorator(MyException* exc): Decorator(exc){}

HashDecorator::~HashDecorator() {
	delete decorated_obj;
}

void HashDecorator::printMessage() {
	cout << "[HASH ";
	Decorator::printMessage();
}
