#include "message.h"

std::string Message::getMessage() {
	return message;
}


Message::TAGS Message::getTag() {
	return this->tag;
}

Message::Message(){
	tags = { {Message::GM, "[GM] "}, {Message::PM, "[PM] "}, {Message::EM, "[EM] "} };
}


