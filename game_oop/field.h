#pragma once

#include "cell.h"
#include <vector>
#include "actionFactory.h"

class Field {
private:
	Player* player;
	int width;
	int height;
	std::vector<std::vector<Cell>> field;
	std::pair<float, float> player_coords;
	void swap(Field& obj);

public:
	Field(int width = 30, int height = 30);
	void resizeField(int width, int height);
	Field(const Field& obj);
	Field& operator= (const Field& obj);
	Field(Field&& obj) noexcept;
	Field& operator=(Field&& obj) noexcept;
	~Field();

	Cell* getCell(int y, int x);
	void makeCell(Cell::STATES, int y, int x);
	void setStartCell(int y, int x);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
	Player* getPlayer();
	void setPlayer(Player*);
	std::vector<std::vector<Cell>>* getField();

	std::pair<float, float> getPlayerCoords() const;
	void setPlayerCoords(float y, float x);

};