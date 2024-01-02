#include "fileLogger.h"

FileLogger::FileLogger(std::string file) {
	this->file.open(file, std::ios_base::app | std::ios_base::out);
	try {
		if (!this->file.is_open()) {
			throw file;
		}
	}
	catch (std::string f) {
		std::cout << "File " << f << " doesn't exist!\n";
		exit(1);
	}
	this->file << "-----NEW SESSION-----" << "\n\n";
}

FileLogger::~FileLogger() {
	this->file << "-----END OF SESSION-----" << "\n\n";
	this->file.close();
}

void FileLogger::print(Message* msg) {
	file << msg;
}