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

	selectPanel = std::make_shared<SelectPanel>(100, 100);
	selectPanel->selfCentering(0.5 * SCREEN_WIDTH, 0.5 * SCREEN_HEIGHT);
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
			if (pEvent.key.code == sf::Keyboard::A)
			{
				selectPanel->moveSelector("left", selectPanel->selector1);
			}
			if (pEvent.key.code == sf::Keyboard::D)
			{
				selectPanel->moveSelector("right", selectPanel->selector1);
			}
			if (pEvent.key.code == sf::Keyboard::W)
			{
				selectPanel->moveSelector("up", selectPanel->selector1);
			}
			if (pEvent.key.code == sf::Keyboard::S)
			{
				selectPanel->moveSelector("down", selectPanel->selector1);
			}
			if (pEvent.key.code == sf::Keyboard::Up)
			{
				selectPanel->moveSelector("up", selectPanel->selector2);
			}
			if (pEvent.key.code == sf::Keyboard::Down)
			{
				selectPanel->moveSelector("down", selectPanel->selector2);
			}
			if (pEvent.key.code == sf::Keyboard::Left)
			{
				selectPanel->moveSelector("left", selectPanel->selector2);
			}
			if (pEvent.key.code == sf::Keyboard::Right)
			{
				selectPanel->moveSelector("right", selectPanel->selector2);
			}
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
	// testing avatar
	selectPanel->update(dt);
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
	// testing
	selectPanel->draw(*window);
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