#include "workWithCmds.h"


WorkWithCmds::WorkWithCmds(std::string f, Player* player, DrawPlayer* drawPlayer): player(player), drawPlayer(drawPlayer) {
    defaultCommands = { {Player::RIGHT, Keyboard::D}, {Player::LEFT, Keyboard::A}, {Player::UP, Keyboard::W}, {Player::DOWN, Keyboard::S} };
    std::ifstream file(f);
    std::vector<int> cmds;
    std::vector<int> keys;
    bool flag = true;
    std::string cmd;
    std::string key;
    while (std::getline(file, cmd) && std::getline(file, key)) {
        for (int i = 0; i < cmds.size(); i++) {
            if (cmds[i] == std::stoi(cmd) || keys[i] == std::stoi(key)) {
                commands = defaultCommands;
                flag = false;
                break;
            }
        }
        if (std::stoi(cmd) < 0 || std::stoi(cmd) > SIZE_DIRS || std::stoi(key) < 0 || std::stoi(cmd) > SIZE_KEYBOARD) {
            commands = defaultCommands;
            break;
        }
        if (!flag) break;
        setCommand(static_cast<Player::DIRS>(std::stoi(cmd)), static_cast<Keyboard::Key>(std::stoi(key)));
    }
    if (cmd.size() != SIZE_DIRS) {
        commands = defaultCommands;
    }
    file.close();
}


void WorkWithCmds::setCommand(Player::DIRS cmd, Keyboard::Key key) {
    commands[cmd] = key;
}

std::map <Player::DIRS, Keyboard::Key> WorkWithCmds::getCommands() {
    return commands;
}

void WorkWithCmds::callRender(float& current_frame, Player::DIRS dir) {
    drawPlayer->render(player, current_frame, dir);
}
