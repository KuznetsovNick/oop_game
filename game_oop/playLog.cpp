#include "playLog.h"

PlayLog::PlayLog() {
	emptyMsg = new EmptyM();
};

Message* PlayLog::update(Message* msg) {
	if (msg->getTag() == Message::PM) {
		return msg;
	}
	return emptyMsg;
}

void PlayLog::setPlayer(Player* player) {
	this->player = player;
}
