#include "fieldDec.h"

FieldDecorator::FieldDecorator(MyException* exc): Decorator(exc) {}

FieldDecorator::~FieldDecorator() {
	delete decorated_obj;
}

void FieldDecorator::printMessage() {
	cout << "[FIELD ";
	Decorator::printMessage();
}
