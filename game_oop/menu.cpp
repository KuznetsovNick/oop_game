#include "menu.h"


void menu(RenderWindow& window, Field* field) {
	Texture menuTexture1, menuTexture2;
	menuTexture1.loadFromFile("10.png");
	menuTexture2.loadFromFile("20.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menuNum = 1;
	menu1.setPosition(0, 0);
	menu2.setPosition(0, 170);
	
	while (isMenu)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(0, 0, 164, 76).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		else menu1.setColor(Color::White);
		if (IntRect(0, 170, 192, 80).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		else menu2.setColor(Color::White);

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				field->setHeight(10);
				field->setWidth(10);
				isMenu = false;
			}
			if (menuNum == 2) {
				field->setHeight(20);
				field->setWidth(20);
				isMenu = false;
			}

		}

		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
}