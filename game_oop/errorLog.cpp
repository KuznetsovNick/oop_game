#include "errorLog.h"

ErrorLog::ErrorLog() {
	emptyMsg = new EmptyM();
};

Message* ErrorLog::update(Message* msg) {
	if (msg->getTag() == Message::EM) {
		return msg;
	}
	return emptyMsg;
}