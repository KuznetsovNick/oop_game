#include "window.h"
#include "game.h"
#include <fstream>
#include "download.h"

Game::Game() {
    startM = new StartM();
    endM = new EndM();
    smallM = new SmallM();
}

Game::~Game() {
    //delete[] startM;
    //delete[] endM;
    //delete[] smallM;
}

void Game::start()
{   
    //MyWindow project_window;
    Level* level = MyWindow::get().levelWindow();
    std::vector<LogType*> logs = MyWindow::get().logWindow();
    std::vector<Logger*> loggers = MyWindow::get().outLogWindow();
    std::vector<ControlScan*> controls = MyWindow::get().controlScanWindow();
    LoggerPool* pool= new LoggerPool(loggers, logs);
    //std::pair<int, int> sizeOfField = project_window.menuWindow();
    //if (sizeOfField.first < 2 || sizeOfField.second < 2) {
    //    pool->logging(smallM);
    //    return;
    //}
    Creator* creator = new Creator(level, pool, controls);
    creator->getLoggerPool()->logging(startM);
    MyWindow::get().gameWindow(creator);
    creator->getLoggerPool()->logging(endM);
    MyWindow::get().finishWindow(creator);
    for (int i = 0; i < loggers.size(); i++) {
        delete loggers.at(i);
    }
}