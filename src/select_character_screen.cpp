#include "select_character_screen.hpp"

SelectCharacterScreen::SelectCharacterScreen() 
{
	// set running to true
	this->running = true;
	// create a new window
	this->window = std::make_shared<sf::RenderWindow>();
	this->window->create(sf::VideoMode(16*64, 9*64), "Select Character Screen");
	// config the window
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);
}

SelectCharacterScreen::~SelectCharacterScreen()
{

}

void SelectCharacterScreen::init()
{

}

void SelectCharacterScreen::setRunning(bool b)
{
	running = b;
}

void SelectCharacterScreen::handleEvents()
{
	// Handle window close event
	sf::Event pEvent;
	while (window->pollEvent(pEvent))
	{
		if (pEvent.type == sf::Event::Closed)
		{
			setRunning(false);
		}
	}
}

void SelectCharacterScreen::update()
{

}

void SelectCharacterScreen::render()
{
	window->clear();
	// draw stuff here

	//
	window->display();
}

void SelectCharacterScreen::checkQuit()
{
	if (!running)
	{
		window->close();
	}
}

void SelectCharacterScreen::run()
{
	while (running) {
		// do the game
		handleEvents();
		update();
		render();
		checkQuit();
	}
}