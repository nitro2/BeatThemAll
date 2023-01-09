#pragma once
#ifndef SELECT_CHARACTER_SCREEN_H
#define SELECT_CHARACTER_SCRREN_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "selector.hpp"
#include "spring_text.hpp"

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

		void loadFonts();

		bool running = false;

		sf::Font pixelFont;
		sf::Text testing;

		std::shared_ptr<Selector> selector;
		std::shared_ptr<SpringText> title;

};

#endif SELECT_CHARACTER_SCREEN_H