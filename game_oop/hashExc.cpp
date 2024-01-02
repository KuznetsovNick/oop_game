#include "HashExc.h"

HashExc::HashExc(int hash) : hash(hash) {}

void HashExc::printMessage() {
	string message = "Load data has been changed cause hash is wrong: " + std::to_string(hash) + "\n";
	cout << message;
}

