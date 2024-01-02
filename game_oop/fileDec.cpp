#include "fileDec.h"

FileDecorator::FileDecorator(MyException* exc) : Decorator(exc) {}

FileDecorator::~FileDecorator() {
	delete decorated_obj;
}

void FileDecorator::printMessage() {
	cout << "[FILE ";
	Decorator::printMessage();
}

