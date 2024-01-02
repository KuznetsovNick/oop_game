#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "workWithCmds.h"
using namespace sf;

class ControlScan {
protected:
	std::string file;
public:
	virtual void controlScanWindow(WorkWithCmds* workCmds) = 0;
	ControlScan();
	void SetControll(WorkWithCmds* workCmds);
};