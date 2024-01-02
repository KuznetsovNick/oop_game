#include "field.h"
#include <math.h>
#include <random>



Field::Field(int width, int height) : width(width), height(height), player_coords({0,0}), player(new Player()) {
	for (int i = 0; i < height; i++) {
		field.emplace_back();
		for (int j = 0; j < width; j++) {
			field.at(i).emplace_back();
		}
	}
}

void Field::resizeField(int width, int height) {
	for (int i = 0; i < height; i++) {
		field.at(i).resize(width);
	}
	field.resize(height);
	this->height = height;
	this->width = width;
}

int Field::getWidth() {
	return this->width;
}

void Field::setWidth(int width) {
	this->width = width;
}

int Field::getHeight() {
	return this->height;
}

void Field::setHeight(int height) {
	this->height = height;
}

Cell* Field::getCell(int y, int x){
	return &field.at(y).at(x);
}

void Field::setStartCell(int y, int x) {
	field.at(y).at(x).setStart(true);
}

std::pair<float, float> Field::getPlayerCoords() const {
	return player_coords;
}

std::vector<std::vector<Cell>>* Field::getField() {
	return &field;
}

Player* Field::getPlayer() {
	return player;
}
void Field::setPlayer(Player* player) {
	this->player = player;
}


void Field::setPlayerCoords(float y, float x) {
	if (x < 0) x = (width - 1) * 30 + 16;  if (y < 0) y = (height - 1) * 30 - 2;
	if (x > ((width - 1) * 30 + 16)) x = 0;
	if (y > ((height - 1) * 30 - 2)) y = 0;
	player_coords.first = y;
	player_coords.second = x;
}


Field::Field(const Field& obj) : width(obj.width), height(obj.height), player_coords(obj.player_coords), player(obj.player) {
	for (int i = 0; i < height; i++) {
		field.emplace_back();
		for (int j = 0; j < width; j++) {
			field.at(i).push_back(obj.field.at(i).at(j));
		}
	}
}

void Field::swap(Field& obj) {
	std::swap(width, obj.width);
	std::swap(player, obj.player);
	std::swap(height, obj.height);
	std::swap(field, obj.field);
	std::swap(player_coords, obj.player_coords);
}

Field& Field::operator=(const Field& obj) {
	if (this != &obj) {
		Field(obj).swap(*this);
	}
	return *this;
}

Field::Field(Field&& obj) noexcept {
	this->swap(obj);
}

Field& Field::operator=(Field&& obj) noexcept {
	if (this != &obj) {
		this->swap(obj);
	}
	return *this;
}

Field::~Field() {
	delete player;
}

void Field::makeCell(Cell::STATES state, int y, int x) {
	field.at(y).at(x).setState(state);
	switch (state)
	{
	case Cell::IMPAS:
		break;
	case Cell::PASS:
		break;
	case Cell::COINS:
		field.at(y).at(x).setAction(new Coin(player));
		field.at(y).at(x).setClearAction(new Clear(getCell(y, x)));
		break;
	case Cell::TRAP:
		field.at(y).at(x).setAction(new Trap(player));
		field.at(y).at(x).setClearAction(new Clear(getCell(y, x)));
		break;
	case Cell::EXIT:
		field.at(y).at(x).setAction(new Door(player));
		field.at(y).at(x).setClearAction(new Clear(getCell(y, x)));
		break;
	default:
		break;
	}
}


