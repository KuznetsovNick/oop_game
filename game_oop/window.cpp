#include "window.h"
#include "creator.h"
#include <iostream>
#include "download.h"
#include "save.h"

void MyWindow::gameWindow(Creator* creator) {
	RenderWindow window(sf::VideoMode(640, 480), "Game");

    Clock clock;
    float current_frame = 0;

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 18);
	text.setOutlineColor(Color::Blue);
	sf::Event event;


    while (window.isOpen() && creator->getPlayer()->getIsAlive())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        current_frame += 0.01 * time;
		if (current_frame > 6) current_frame -= 6;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Escape) {
				//for (int i = 0; i < creator->getControls().size(); i++) {
				//	creator->getControls().at(i)->controlScanWindow(creator->getWorkCmds());
				//}
				loadWindow(creator);
			}
        }
		if (creator->getPlayer()->getIsAlive()){
			creator->getController()->keyBoardCommands(creator->getWorkCmds(), current_frame);
		}
        creator->getDrawPlayer()->playerMovement(time, creator->getPlayer(), creator->getField(), creator->getLoggerPool());
		creator->getTracker()->track(creator->getPlayer(), creator->getField(), creator->getFactory(), creator->getLoggerPool());
        window.clear();

		creator->getMap()->setSpriteMap(creator->getField(), window);

		window.draw(creator->getTablo()->tablo(creator->getPlayer()->getCoins(), creator->getPlayer()->getHealth(), text));


        window.draw(*creator->getDrawPlayer()->getSpritePlayer());
        window.display();
    }
}

void MyWindow::loadWindow(Creator* creator) {
	Download* d = new Download("dwld.txt");
	Save* s = new Save("dwld.txt");
	RenderWindow window(sf::VideoMode(640, 480), "dwld");
	Texture levelTexture1, levelTexture2;
	levelTexture1.loadFromFile("load.png");
	levelTexture2.loadFromFile("save.png");
	Sprite menu1(levelTexture1), menu2(levelTexture2);
	bool isMenu = true;
	int menuNum = 0;
	menu1.setPosition(0, 0);
	menu2.setPosition(0, 200);

	sf::Event event;

	while (isMenu)
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(0, 0, 180, 70).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		else menu1.setColor(Color::White);
		if (IntRect(0, 180, 180, 70).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		else menu2.setColor(Color::White);

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				isMenu = false;
				try {
					d->download(creator);
				}
				catch (MyException& ex) {
					ex.printMessage();
				}
				menu1.setColor(Color::Magenta);
			}
			if (menuNum == 2) {
				isMenu = false;
				s->save(creator);
				menu2.setColor(Color::Magenta);

			}

		}

		window.draw(menu1);
		window.draw(menu2);


		window.display();
	}
	delete d;
	delete s;
}

std::vector<LogType*> MyWindow::logWindow() {
	std::vector<LogType*> logs;
	RenderWindow window(sf::VideoMode(640, 480), "Log");
	std::pair<int, int> size;
	Texture levelTexture1, levelTexture2, levelTexture3, levelTexture4;
	levelTexture1.loadFromFile("gameL.png");
	levelTexture2.loadFromFile("gpL.png");
	levelTexture3.loadFromFile("errorL.png");
	levelTexture4.loadFromFile("next.png");
	Sprite menu1(levelTexture1), menu2(levelTexture2), menu3(levelTexture3), menu4(levelTexture4);
	bool isMenu = true;
	bool isGameLog = false;
	bool isPlayLog = false;
	bool isErrorLog = false;
	int menuNum = 0;
	menu1.setPosition(0, 0);
	menu2.setPosition(0, 150);
	menu3.setPosition(0, 300);
	menu4.setPosition(400, 350);

	sf::Event event;

	while (isMenu)
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(0, 0, 225, 125).contains(Mouse::getPosition(window)) && isGameLog == false) { menu1.setColor(Color::Blue); menuNum = 1; }
		else if (isGameLog == false) menu1.setColor(Color::White);
		if (IntRect(0, 150, 365, 125).contains(Mouse::getPosition(window)) && isPlayLog == false) { menu2.setColor(Color::Blue); menuNum = 2; }
		else if (isPlayLog == false) menu2.setColor(Color::White);
		if (IntRect(0, 300, 225, 125).contains(Mouse::getPosition(window)) && isErrorLog == false) { menu3.setColor(Color::Blue); menuNum = 3; }
		else if (isErrorLog == false) menu3.setColor(Color::White);
		if (IntRect(400, 350, 155, 60).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Blue); menuNum = 4; }
		else menu4.setColor(Color::White);

		if (logs.size() == 3) menuNum = 4;

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				logs.push_back(new GameLog());
				isGameLog = true;
				menu1.setColor(Color::Magenta);
			}
			if (menuNum == 2) {
				logs.push_back(new PlayLog());
				isPlayLog = true;
				menu2.setColor(Color::Magenta);

			}
			if (menuNum == 3) {
				logs.push_back(new ErrorLog());
				isErrorLog = true;
				menu3.setColor(Color::Magenta);

			}
			if (menuNum == 4) {
				isMenu = false;
			}

		}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);

		window.display();
	}
	return logs;
}

std::vector<Logger*> MyWindow::outLogWindow() {
	std::vector<Logger*> loggers;
	RenderWindow window(sf::VideoMode(640, 480), "Out");
	std::pair<int, int> size;
	Texture levelTexture1, levelTexture2, levelTexture3;
	levelTexture1.loadFromFile("console.png");
	levelTexture2.loadFromFile("file.png");
	levelTexture3.loadFromFile("next.png");
	Sprite menu1(levelTexture1), menu2(levelTexture2), menu3(levelTexture3);
	bool isMenu = true;
	bool isConsole = false;
	bool isFile = false;
	int menuNum = 0;
	menu1.setPosition(0, 0);
	menu2.setPosition(0, 80);
	menu3.setPosition(400, 350);
	sf::Event event;

	while (isMenu)
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(0, 0, 225, 60).contains(Mouse::getPosition(window)) && isConsole == false) { menu1.setColor(Color::Blue); menuNum = 1; }
		else if (isConsole == false)menu1.setColor(Color::White);
		if (IntRect(0, 80, 105, 60).contains(Mouse::getPosition(window)) && isFile == false) { menu2.setColor(Color::Blue); menuNum = 2; }
		else if (isFile == false) menu2.setColor(Color::White);
		if (IntRect(400, 350, 155, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		else menu3.setColor(Color::White);

		if (loggers.size() == 2) menuNum = 3;

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				loggers.push_back(new ConsoleLogger());
				isConsole = true;
				menu1.setColor(Color::Magenta);
			}
			if (menuNum == 2) {
				loggers.push_back(new FileLogger());
				isFile = true;
				menu2.setColor(Color::Magenta);
			}
			if (menuNum == 3) {
				isMenu = false;
			}

		}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	return loggers;
}

std::vector<ControlScan*> MyWindow::controlScanWindow(){
	std::vector<ControlScan*> controls;
	RenderWindow window(sf::VideoMode(640, 480), "Controll");
	std::pair<int, int> size;
	Texture levelTexture1, levelTexture3;
	levelTexture1.loadFromFile("GUI.png");
	levelTexture3.loadFromFile("next.png");
	Sprite menu1(levelTexture1), menu3(levelTexture3);
	bool isMenu = true;
	bool isConsole = false;
	bool isFile = false;
	int menuNum = 0;
	menu1.setPosition(0, 0);
	menu3.setPosition(400, 350);
	sf::Event event;

	while (isMenu)
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(0, 0, 105, 70).contains(Mouse::getPosition(window)) && isConsole == false) { menu1.setColor(Color::Blue); menuNum = 1; }
		else if (isConsole == false)menu1.setColor(Color::White);
		if (IntRect(400, 350, 155, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		else menu3.setColor(Color::White);

		if (controls.size() == 1) menuNum = 3;

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				controls.push_back(new ControlGUI());
				isConsole = true;
				menu1.setColor(Color::Magenta);
			}
			if (menuNum == 3) {
				isMenu = false;
			}

		}

		window.draw(menu1);
		window.draw(menu3);

		window.display();
	}
	if (controls.empty()) {
		controls.push_back(new ControlGUI());
	}
	return controls;
}

std::pair<int, int> MyWindow::menuWindow() {
	RenderWindow window(sf::VideoMode(640, 480), "Menu");
	std::pair<int, int> size;
	Texture menuTexture1, menuTexture2;
	menuTexture1.loadFromFile("10.png");
	menuTexture2.loadFromFile("20.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menuNum = 1;
	menu1.setPosition(0, 0);
	menu2.setPosition(0, 170);
	sf::Event event;

	while (isMenu)
	{

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
				size.first = 10;
				size.second = 10;
				isMenu = false;
			}
			if (menuNum == 2) {
				size.first = 20;
				size.second = 15;
				isMenu = false;
			}

		}

		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	return size;
}

void MyWindow::finishWindow(Creator* creator) {
	RenderWindow window(sf::VideoMode(640, 480), "Ur results");
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 36);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(Color(129, 181, 221));

		window.draw(creator->getTablo()->finishTablo(text, creator->getPlayer()->getHealth(), creator->getPlayer()->getWin()));
		window.display();
	}

}

Level* MyWindow::levelWindow() {
	RenderWindow window(sf::VideoMode(640, 480), "Menu");
	Level* level = new Level_1();
	Texture menuTexture1, menuTexture2;
	menuTexture1.loadFromFile("level1.png");
	menuTexture2.loadFromFile("level2.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menuNum = 1;
	menu1.setPosition(0, 0);
	menu2.setPosition(0, 120);
	sf::Event event;

	while (isMenu)
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(0, 0, 205, 60).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		else menu1.setColor(Color::White);
		if (IntRect(0, 120, 205, 80).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		else menu2.setColor(Color::White);

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				isMenu = false;
			}
			if (menuNum == 2) {
				level = new Level_2();
				isMenu = false;
			}

		}

		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	return level;
}

