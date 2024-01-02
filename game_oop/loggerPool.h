#pragma once
#include "gameLog.h"
#include "playLog.h"
#include "errorLog.h"
#include "consoleLogger.h"
#include "fileLogger.h"
#include "Logger.h"


class LoggerPool {
public:
	LoggerPool(std::vector<Logger*> loggers, std::vector<LogType*> logs);
	~LoggerPool();
	void logging(Message* msg);

private:
	std::vector<LogType*> logs;
	std::vector<Logger*> loggers;
};