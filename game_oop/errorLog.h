#pragma once
#include "logType.h"

class ErrorLog : public LogType {
public:
	ErrorLog();
	Message* update(Message* msg) override;
};