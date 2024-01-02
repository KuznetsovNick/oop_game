#pragma once
#include "emptyMessage.h"
#include "startMessage.h"
#include "endMessage.h"
#include "smallMessage.h"
#include "obstacleMessage.h"
#include "coinMessage.h"
#include "trapMessage.h"

class LogType {
protected:
	Message* emptyMsg;
public:
	virtual Message* update(Message* msg) = 0;
};