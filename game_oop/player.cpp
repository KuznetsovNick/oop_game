#include "player.h"
#include <iostream>

Player::Player():health(3), coins(0), speed(0), dir(DOWN), kills(0), damage(10), isAlive(true), win(false) {};


Player::DIRS Player::getDir() {
	return this->dir;
}

void Player::setDir(DIRS dir) {
	this->dir = dir;
}

float Player::getSpeed() {
	return this->speed;
}
void Player::setSpeed(float speed) {
	this->speed = speed;
}

int Player::getHealth() const {
	return this->health;
}
void Player::setHealth(int health) {
	this->health = health;
}
int Player::getDamage() const {
	return this->damage;

}
void Player::setDamage(int damage) {
	this->damage;
}
int Player::getKills() const {
	return this->kills;
}
void Player::setKills() {
	this->kills = kills;
}
int Player::getCoins() const {
	return this->coins;
}
void Player::setCoins(int coin) {
	this->coins = coin;
}

bool Player::getIsAlive() const {
	return this->isAlive;
}
void Player::setIsAlive(bool statement) {
	this->isAlive = statement;
}

bool Player::getWin() {
	return this->win;
}
void Player::setWin(bool win) {
	this->win = win;
}



void Player::swap(Player& obj) {
	std::swap(isAlive, obj.isAlive);
	std::swap(win, obj.win);
	std::swap(damage, obj.damage);
	std::swap(kills, obj.kills);
	std::swap(speed, obj.speed);
	std::swap(dir, obj.dir);
	std::swap(health, obj.health);
	std::swap(coins, obj.coins);
}

Player::Player(const Player& obj) {
	isAlive = obj.isAlive;
	win = obj.win;
	damage = obj.damage;
	kills = obj.kills;
	speed = obj.speed;
	dir = obj.dir;
	health = obj.health;
	coins = obj.coins;
}

Player& Player::operator=(const Player& obj) {
	if (this != &obj) {
		Player(obj).swap(*this);
	}
	return *this;
}

Player::Player(Player&& obj) noexcept {
	this->swap(obj);
}

Player& Player::operator=(Player&& obj) noexcept {
	if (this != &obj) {
		this->swap(obj);
	}
	return *this;
}
