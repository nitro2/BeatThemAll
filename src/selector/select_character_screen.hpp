#pragma once
#ifndef SELECT_CHARACTER_SCREEN_HPP
#define SELECT_CHARACTER_SCRREN_HPP

#include <iostream>
#include "SFML/Graphics.hpp"
#include "spring_text.hpp"

// This is the select character screen game state
class SelectCharacterScreen
{
	public:
		// This function initialize select character screen here
		SelectCharacterScreen();
		// Deallocation memory in this function if needed
		~SelectCharacterScreen();

		// This function keep the game running
		void run();
		// This function help to set the running state of the game
		void setRunning(bool b);

		std::shared_ptr<sf::RenderWindow> window;

		// this is for delta time
		sf::Clock clock;
		float dt;
	private:
		// Handle game logic
		void update();
		// Handle events
		void handleEvents();
		// Draw the game
		void render();
		// Check to quit the game
		void checkQuit();

		bool running = false;

		std::vector<std::shared_ptr<SpringText>> springTextList;
};

#endif SELECT_CHARACTER_SCREEN_HPP