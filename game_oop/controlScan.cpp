#include "controlScan.h"

ControlScan::ControlScan(): file("controllKeys.txt") {}

void ControlScan::SetControll(WorkWithCmds* workCmds) {
    std::ifstream file(this->file);
	try {
		if (!file.is_open()) {
			throw this->file;
		}
	}
	catch (std::string f) {
		std::cout << "File " << f << " doesn't exist!\n";
		exit(1);
	}
    std::string cmd;
    std::string key;

    while (std::getline(file, cmd), std::getline(file, key)) {
        workCmds->setCommand(static_cast<Player::DIRS>(std::stoi(cmd)), static_cast<Keyboard::Key>(std::stoi(key)));
    }
    file.close();
}