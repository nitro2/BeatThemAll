#include "select_character_screen.hpp"

SelectCharacterScreen::SelectCharacterScreen()
{
	// set running to true
	this->running = true;
	// create a new window
	this->window = std::make_shared<sf::RenderWindow>();
	this->window->create(sf::VideoMode(1920, 1080), "Select Character Screen");
	// config the window
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);

	// initialize delta time
	dt = 0;

	springTextList.push_back(std::make_shared<SpringText>("Choose your cool hero!", 500, 500));
	// test self centering
	springTextList[0]->selfCentering(0.5 * SCREEN_WIDTH, 0.25 * SCREEN_HEIGHT);
}

SelectCharacterScreen::~SelectCharacterScreen()
{
	// In this game states, we mainly using shared pointer so we don't need to care about memory deallocate
}

void SelectCharacterScreen::setRunning(bool b)
{
	running = b;
}

void SelectCharacterScreen::handleEvents()
{
	// Handle window events
	sf::Event pEvent;
	while (window->pollEvent(pEvent))
	{
		// close event
		if (pEvent.type == sf::Event::Closed)
		{
			setRunning(false);
		}
		// key pressed event
		if (pEvent.type == sf::Event::KeyPressed)
		{
			
		}
	}
}

void SelectCharacterScreen::update()
{
	// Get the mouse position related to window and then pass it to update function of every spring text 
	sf::Vector2i position = sf::Mouse::getPosition(*window);
	for (size_t i = 0; i < springTextList.size(); i++)
	{
		springTextList[i]->update(dt, position);
	}
}

void SelectCharacterScreen::render()
{
	window->clear(sf::Color(38, 122, 233, 255));
	// draw stuff here

	// Iterate through all elements in springTextList and draw them
	for (size_t i = 0; i < springTextList.size(); i++)
	{
		springTextList[i]->draw(*window);
	}
	//
	window->display();
}

void SelectCharacterScreen::checkQuit()
{
	// running == false mean the game is end, close the window
	if (!running)
	{
		window->close();
	}
}

void SelectCharacterScreen::run()
{
	while (running) {
		dt = clock.restart().asSeconds();
		// do the game
		handleEvents();
		update();
		render();
		checkQuit();
	}
}