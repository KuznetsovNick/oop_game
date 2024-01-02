#include "consoleLogger.h"

void ConsoleLogger::print(Message* msg) {
	std::cout << msg;
}

std::ostream& operator<<(std::ostream& out, Message* message) {
	out << message->getMessage();
	return out;
}