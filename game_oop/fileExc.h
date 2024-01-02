#pragma once
#include "myExc.h"
using namespace std;

class FileExc: public MyException {
private:
	string file;
public:
	FileExc(string file);
	void printMessage() override;
};