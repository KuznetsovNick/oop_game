#include "creator.h"

Creator::Creator(Level* level, LoggerPool* pool, std::vector<ControlScan*> controls) {
    std::ifstream f ("hash.txt");
    std::string cur;
    hash = new int;
    std::getline(f, cur);
    *hash = std::stoi(cur);
    this->controls = controls;
    loggerPool = pool;
    this->level = level; 
    field = this->level->generateLevel();
    player = field->getPlayer();
    //builder = new FieldBuilder();
    //field = new Field();
    //field = builder->createField(size.first, size.second);
    //builder->createStates(this->field);
    map = new Map("map.png");
    draw_player = new DrawPlayer("side_walk_left.png", "side_walk_right.png", "walk_up.png", "walk_down.png");
    controller = new Controller();
    workCmds = new WorkWithCmds("default.txt", player, draw_player);
    tablo = new Tablo();
    factory = new ActionFactory();
    tracker = new ActionTracker(factory->createAction(field, field->getCell(0, 0), player, ActionFactory::ENDING), factory->createAction(field, field->getCell(0, 0), player, ActionFactory::EXIT));

}

Creator::Creator(Creator& obj){
    obj.field = this->field;
    obj.map = map;
    obj.player = player;
    obj.draw_player = draw_player;
    obj.controller = controller;
    obj.tracker = tracker;
    obj.factory = factory;
    obj.tablo = tablo;
    obj.loggerPool = loggerPool;
    obj.workCmds = workCmds;
    obj.controls = controls;
    obj.level = level;
    obj.hash = hash;
}

Creator::~Creator() {
    delete map;
    delete draw_player;
    delete controller;
    delete tracker;
    delete factory;
    delete tablo;
    delete tracker;
}

Map* Creator::getMap() {
    return map;
}

Field* Creator::getField() {
    return field;
}

Player* Creator::getPlayer() {
    return player;
}

DrawPlayer* Creator::getDrawPlayer() {
    return draw_player;
}

Controller* Creator::getController() {
    return controller;
}

ActionFactory* Creator::getFactory() {
    return factory;
}

ActionTracker* Creator::getTracker() {
    return tracker;
}

Tablo* Creator::getTablo() {
    return tablo;
}

LoggerPool* Creator::getLoggerPool() {
    return loggerPool;
}

std::vector<ControlScan*> Creator::getControls() {
    return controls;
}

WorkWithCmds* Creator::getWorkCmds() {
    return workCmds;
}

int* Creator::getHash() {
    return hash;
}
void Creator::setHash(int* hash) {
    this->hash = hash;
}

Creator::Creator(){}