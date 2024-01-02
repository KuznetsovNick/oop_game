#include "tablo.h"

Text Tablo::tablo(int coins, int hearts, Text text) {
	std::ostringstream playersCoins;
	playersCoins << coins;
	std::ostringstream playersHearts;
	playersHearts << hearts;
	text.setString("Coins collected: " + playersCoins.str() + '\n' + "Hearts: " + playersHearts.str());
	text.setPosition(0, 0);
	return text;
}

Text Tablo::finishTablo(Text text, int health, bool win) {
    std::ostringstream playerHealth;
    text.setFillColor(Color::Blue);
    playerHealth << health;
    if (win) {
        text.setString("Congrates!\nU win\nNew lvls will comin soon)\nhealth: " + playerHealth.str());
    }
    else {
        text.setString("Oh noo!\nU lose!\nhealth: " + playerHealth.str());
    }
    text.setPosition(230, 160);
    return text;

}

