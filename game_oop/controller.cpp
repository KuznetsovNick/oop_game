#include "controller.h"

void Controller::keyBoardCommands(WorkWithCmds* workCmds, float& current_frame) {
    Player::DIRS pressed;
    for (int i = 0; i < workCmds->getCommands().size(); i++) {
        pressed = static_cast<Player::DIRS>(i);
        if (Keyboard::isKeyPressed(workCmds->getCommands()[pressed])) { 
            workCmds->callRender(current_frame, pressed);
            break;
        }
    }
}

//Player* player, DrawPlayer* draw_player, float &current_frame
// draw_player->render(player, current_frame, pressed);

