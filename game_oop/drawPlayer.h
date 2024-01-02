#pragma once
#include "field.h"
#include "player.h"
#include "loggerPool.h"

using namespace sf;

class DrawPlayer {
private:
	float dx, dy;

	Image image_left;
	Image image_right;
	Image image_up;
	Image image_down;

	Texture texture_left;
	Texture texture_right;
	Texture texture_up;
	Texture texture_down;

	Sprite sprite;

	Message* obsM;


public:
	DrawPlayer(String F1, String F2, String F3, String F4);
	~DrawPlayer();
	Texture* getTexture(Player::DIRS);
	Sprite* getSpritePlayer();
	void render(Player* player, float& current_frame, Player::DIRS dir);


	void playerMovement(float time, Player* player, Field* field, LoggerPool* pool);
	void interactionWithObstacle(Field* field, LoggerPool* pool);

};

