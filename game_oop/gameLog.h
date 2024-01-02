#pragma once
#include "logType.h"

class GameLog: public LogType{
public:
	GameLog();
	Message* update(Message* msg) override;
};