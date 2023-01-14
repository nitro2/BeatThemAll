#pragma once
#ifndef SELECT_CHARACTER_SCREEN_HPP
#define SELECT_CHARACTER_SCRREN_HPP

#include <iostream>
#include "SFML/Graphics.hpp"


class SelectCharacterScreen
{
	public:
		SelectCharacterScreen();
		~SelectCharacterScreen();

		void run();
		void setRunning(bool b);

		std::shared_ptr<sf::RenderWindow> window;

		// this is for delta time
		sf::Clock clock;
		float dt;
	private:
		void update();
		void handleEvents();
		void render();
		void checkQuit();

		bool running = false;
};

#endif SELECT_CHARACTER_SCREEN_HPP