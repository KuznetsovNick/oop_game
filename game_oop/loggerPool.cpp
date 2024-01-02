#include "loggerPool.h"

LoggerPool::LoggerPool(std::vector<Logger*> loggers, std::vector<LogType*> logs) : loggers(loggers), logs(logs) {}

LoggerPool::~LoggerPool() {
	for (int i = 0; i < loggers.size(); i++) {
		delete[] loggers.at(i);
	}

	for (int i = 0; i < logs.size(); i++) {
		delete[] logs.at(i);
	}
}

void LoggerPool::logging(Message* message) {
	for (int i = 0; i < logs.size(); i++){
		Message* msg = logs.at(i)->update(message);
		for (int j = 0; j < loggers.size(); j++) {
			loggers.at(j)->print(msg);
		}
	}
}

