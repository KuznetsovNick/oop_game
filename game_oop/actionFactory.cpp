#include "actionFactory.h"
#include "random"

Action* ActionFactory::createAction(Field* field, Cell* cell, Player* player, ACTS act) {
    switch (act) {
    case ActionFactory::COIN:
        return new Coin(player);
    case ActionFactory::TRAP:
        return new Trap(player);
    case ActionFactory::ENDING:
        return new Ending(player);
    case ActionFactory::DOOR:
        return new Door(player);
    case ActionFactory::CLEAR:
        return new Clear(cell);
    case ActionFactory::EXIT:
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, std::min(field->getHeight(), field->getWidth()));
        int i = distrib(gen);
        int j = distrib(gen);
        return new Exit(field->getCell(i, j), player, new Door(player), new Clear(field->getCell(i, j)));
    }
}
