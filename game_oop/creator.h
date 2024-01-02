#pragma once
#include "fieldBuilder.h"
#include "drawField.h"
#include "drawPlayer.h"
#include "controller.h"
#include "actionTracker.h"
#include "actionFactory.h"
#include "tablo.h"
#include "loggerPool.h"
#include "controlGUI.h"
#include "workWithCmds.h"
#include "level_1.h"
#include "level_2.h"
#define P_HASH 1000007
#define X_HASH 263


class Creator {
private:
    //FieldBuilder* builder;
    Field* field;
    Map* map;
    Player* player;
    DrawPlayer* draw_player;
    Controller* controller;
    ActionTracker* tracker;
    ActionFactory* factory;
    Tablo* tablo;
    LoggerPool* loggerPool;
    WorkWithCmds* workCmds;
    std::vector<ControlScan*> controls;
    Level* level;
    int* hash;
    
public:
    Creator(Level* level, LoggerPool* pool, std::vector<ControlScan*> controls);
    Creator();
    Creator(Creator& obj);
    ~Creator();
    Map* getMap();
    Field* getField();
    Player* getPlayer();
    DrawPlayer* getDrawPlayer();
    Controller* getController();
    ActionTracker* getTracker();
    ActionFactory* getFactory();
    Tablo* getTablo();
    LoggerPool* getLoggerPool();
    std::vector<ControlScan*> getControls();
    WorkWithCmds* getWorkCmds();
    int* getHash();
    void setHash(int*);
};