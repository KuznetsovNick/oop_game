#pragma once
#include "player.h"
#include "drawPlayer.h"

class WorkWithCmds {
public:
	void setCommand(Player::DIRS cmd, Keyboard::Key key);
	std::map <Player::DIRS, Keyboard::Key> getCommands();
	void callRender(float& current_frame, Player::DIRS dir);
	WorkWithCmds(std::string file, Player* player, DrawPlayer* drawPlayer);
private:
	Player* player;
	DrawPlayer* drawPlayer;
	std::map <Player::DIRS, Keyboard::Key> commands;
	std::map <Player::DIRS, Keyboard::Key> defaultCommands;
};