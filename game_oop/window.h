#pragma once
#include <iostream> 
#include "creator.h"
#include <vector>
using namespace sf;

class MyWindow {
private:
	//static MyWindow* window;
public:
	static MyWindow& get() {
		static MyWindow window;
		return window;
	}
	//static auto get() {
	//	if (window == nullptr) {
	//		window = new MyWindow();
	//	}
	//	return window;
	//}
	std::vector<LogType*> logWindow();
	Level* levelWindow();
	std::vector<Logger*> outLogWindow();
	std::vector<ControlScan*> controlScanWindow();
	void gameWindow(Creator* creator);
	std::pair<int, int> menuWindow();
	void finishWindow(Creator* creator); 
	void loadWindow(Creator* creator);
};
