#pragma once
#include "controlScan.h"
#include <fstream>
#include <iostream>

class ControlGUI: public ControlScan {
public:
	void controlScanWindow(WorkWithCmds* workCmds) override;
};