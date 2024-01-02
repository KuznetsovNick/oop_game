#pragma once
#include "logger.h"
#include <fstream>

class FileLogger: public Logger {
private:
	std::ofstream file;
public:
	FileLogger(std::string file = "fileOutput.txt");
	~FileLogger();
	void print(Message* msg) override;
};