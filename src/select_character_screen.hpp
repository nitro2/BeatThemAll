#pragma once
#ifndef SELECT_CHARACTER_SCREEN_H
#define SELECT_CHARACTER_SCRREN_H

#include "SFML/Graphics.hpp"

class SelectCharacterScreen
{
	public:
		SelectCharacterScreen();
		~SelectCharacterScreen();

		void init();
		void run();
		void setRunning(bool b);

		std::shared_ptr<sf::RenderWindow> window;
	private:
		void update();
		void handleEvents();
		void render();
		void checkQuit();

		bool running = false;
};

#endif SELECT_CHARACTER_SCREEN_H