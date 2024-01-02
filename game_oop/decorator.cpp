#include "decorator.h"

Decorator::Decorator(MyException* exc): decorated_obj(exc){}

void Decorator::printMessage() {
	cout << "ERROR]\n";
	decorated_obj->printMessage();
}
