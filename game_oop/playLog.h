#pragma once
#include "cell.h"
#include "logType.h"
#include "Message.h"

class PlayLog : public LogType {
public:
	PlayLog();
	void setPlayer(Player* player);
	Message* update(Message* msg) override;
private:
	Player* player;
};