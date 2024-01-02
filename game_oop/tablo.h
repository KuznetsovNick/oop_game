#pragma once
#include <sstream>
#include <iostream>
#include "player.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class Tablo {
public:
	Text tablo(int coins, int hearts, Text text);
	Text finishTablo(Text text, int health, bool win);
};