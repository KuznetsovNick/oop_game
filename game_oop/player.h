#pragma once
#include <SFML/Graphics.hpp>

#define SPRITE_W 14
#define SPRITE_H 32
#define CELL_SIZE 30
#define SPEED 0.15
#define SIZE_DIRS 4
#define SIZE_KEYBOARD 100

class Player{
public:
	Player();
	Player(const Player& obj);
	Player& operator=(const Player& obj);
	Player(Player&& obj) noexcept;
	Player& operator=(Player&& obj) noexcept;

	enum DIRS { LEFT, RIGHT, UP, DOWN };
	DIRS getDir();
	void setDir(DIRS dir);

	float getSpeed();
	void setSpeed(float speed);
	int getHealth() const;
	void setHealth(int health);
	int getDamage() const;
	void setDamage(int damage);
	int getKills() const;
	void setKills();
	int getCoins() const;
	void setCoins(int coins);
	bool getIsAlive() const;
	void setIsAlive(bool statement);
	bool getWin();
	void setWin(bool win);

private:
	bool isAlive;
	bool win;
	float speed;
	DIRS dir;
	int health;
	int damage;
	int kills;
	int coins;
	void swap(Player& obj);
};