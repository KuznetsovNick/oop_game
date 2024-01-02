#include "fileExc.h"

FileExc::FileExc(string file): file(file) {}

void FileExc::printMessage(){	
	string message = "Some problemls with openning file " + file + "\n";
	cout << message;
}

