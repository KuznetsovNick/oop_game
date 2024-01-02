#include "gameLog.h"

GameLog::GameLog() {
	emptyMsg = new EmptyM();
};

Message* GameLog::update(Message* msg) {
	if (msg->getTag() == Message::GM) {
		return msg;
	}
	return emptyMsg;
}