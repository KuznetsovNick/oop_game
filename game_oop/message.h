#pragma once
#include <string>
#include <map>

class Message {
public:
	enum TAGS { EM, GM, PM };
	std::string getMessage();
	Message::TAGS getTag();
	Message();
	friend std::ostream& operator<<(std::ostream& out, Message* message);
protected:
	std::string message;
	TAGS tag;
	std::map <Message::TAGS, std::string> tags;
};