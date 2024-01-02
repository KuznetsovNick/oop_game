#include "fieldExc.h"

FieldExc::FieldExc(int height, int width): height(height), width(width){}

void FieldExc::printMessage() {
	std::string message = "Field Create Exception\n";
	message += "Wrong sizes of field\n";
	message += "Sizes should be > 2\n";
	message += "Height: " + std::to_string(height) + "\n";
	message += "Width: " + std::to_string(width) + "\n";
	cout << message;
}