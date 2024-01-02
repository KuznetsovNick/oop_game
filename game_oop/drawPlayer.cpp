#include "drawPlayer.h"

DrawPlayer::DrawPlayer(sf::String F1, String F2, String F3, String F4): dx(0), dy(0) {

	image_left.loadFromFile(F1);
	texture_left.loadFromImage(image_left);

	image_right.loadFromFile(F2);
	texture_right.loadFromImage(image_right);

	image_up.loadFromFile(F3);
	texture_up.loadFromImage(image_up);

	image_down.loadFromFile(F4);
	texture_down.loadFromImage(image_down);

	sprite.setTexture(texture_down);
	sprite.setTextureRect(IntRect(0, 0, SPRITE_W, SPRITE_H));

	obsM = new ObstacleM;
}

DrawPlayer::~DrawPlayer() {
	//delete[] obsM;
}

void DrawPlayer::playerMovement(float time, Player* player, Field* field, LoggerPool* pool) {
	field->getCell(int(field->getPlayerCoords().first / CELL_SIZE), int(field->getPlayerCoords().second / CELL_SIZE))->setPlayerPrecence(false);
	Player::DIRS dir = player->getDir();
	float speed = player->getSpeed();

	switch (dir) {
	case Player::RIGHT: dx = speed; dy = 0; break;
	case Player::LEFT: dx = -speed; dy = 0; break;
	case Player::DOWN: dx = 0; dy = speed; break;
	case Player::UP: dx = 0; dy = -speed; break;
	}

	field->setPlayerCoords(field->getPlayerCoords().first + dy * time, field->getPlayerCoords().second + dx * time);
	player->setSpeed(0);
	sprite.setPosition(field->getPlayerCoords().second, field->getPlayerCoords().first);
	interactionWithObstacle(field, pool);
	field->getCell(int(field->getPlayerCoords().first / CELL_SIZE), int(field->getPlayerCoords().second / CELL_SIZE))->setPlayerPrecence(true);
}

void DrawPlayer::interactionWithObstacle(Field* field, LoggerPool* pool) {


	int y0 = int(field->getPlayerCoords().first) / CELL_SIZE;
	int x0 = int(field->getPlayerCoords().second) / CELL_SIZE;

	int y1, x1;
	if (int((field->getPlayerCoords().first + (SPRITE_H*2 - 2)) / CELL_SIZE) > field->getHeight()) y1 = field->getHeight();
	else y1 = int((field->getPlayerCoords().first + (SPRITE_H * 2 - 2)) / CELL_SIZE);

	if (int((field->getPlayerCoords().second + (CELL_SIZE*2 - SPRITE_W - 2)) / CELL_SIZE) > field->getWidth()) x1 = field->getWidth();
	else x1 = int((field->getPlayerCoords().second + (CELL_SIZE * 2 - SPRITE_W - 2)) / CELL_SIZE);


	for (int i = y0; i < y1; i++) {
		for (int j = x0; j < x1; j++) {
			if (field->getCell(i, j)->getState() == 0) {
				if (dx > 0) {
					field->setPlayerCoords(field->getPlayerCoords().first, j * CELL_SIZE - (SPRITE_W + 1));
				}
				if (dx < 0) {
					field->setPlayerCoords(field->getPlayerCoords().first, j * CELL_SIZE + CELL_SIZE);
				}
				if (dy > 0) {
					field->setPlayerCoords(i * CELL_SIZE - (SPRITE_H + 1), field->getPlayerCoords().second);
				}
				if (dy < 0) {
					field->setPlayerCoords(i * CELL_SIZE + CELL_SIZE, field->getPlayerCoords().second);
				}
				pool->logging(obsM);
			}
		}
	}
}

Sprite* DrawPlayer::getSpritePlayer() {
	return &sprite;
}

Texture* DrawPlayer::getTexture(Player::DIRS dir) {
	switch (dir){
	case Player::LEFT:
		return &texture_left;
	case Player::RIGHT:
		return &texture_right;
	case Player::UP:
		return &texture_up;
	case Player::DOWN:
		return &texture_down;
	}
}

void DrawPlayer::render(Player* player, float& current_frame, Player::DIRS dir) {
	player->setDir(dir);
	sprite.setTexture(*getTexture(dir));
	player->setSpeed(SPEED);
	sprite.setTextureRect(IntRect(SPRITE_W * int(current_frame) + 1, 0 + 1, SPRITE_W, SPRITE_H));
}

