#include "select_character_screen.hpp"

SelectCharacterScreen::SelectCharacterScreen()
{
	// set running to true
	this->running = true;
	// create a new window
	this->window = std::make_shared<sf::RenderWindow>();
	this->window->create(sf::VideoMode(16 * 64, 9 * 64), "Select Character Screen");
	// config the window
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);

	// initialize delta time
	dt = 0;
	loadFonts();

	testing.setFont(pixelFont);
	testing.setString("Select character");
	testing.setCharacterSize(24);
	testing.setFillColor(sf::Color::White);

	// initialize the selector
	selector = std::make_shared<Selector>(200, 200);
	// initialize the spring title
	title = std::make_shared<SpringText>(330, 100);
}

SelectCharacterScreen::~SelectCharacterScreen()
{

}

void SelectCharacterScreen::loadFonts()
{
	if (!pixelFont.loadFromFile("./assets/fonts/minecraft.ttf"))
	{
		std::cout << "Load pixel font failed.\n";
	}
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
		
		if (pEvent.type == sf::Event::KeyPressed)
		{
			if (pEvent.key.code == sf::Keyboard::A)
			{
				selector->setX(selector->getX() - 80);
			}
			if (pEvent.key.code == sf::Keyboard::D)
			{
				selector->setX(selector->getX() + 80);
			}
			if (pEvent.key.code == sf::Keyboard::W)
			{
				selector->setY(selector->getY() - 80);
			}
			if (pEvent.key.code == sf::Keyboard::S)
			{
				selector->setY(selector->getY() + 80);
			}
		}
	}
}

void SelectCharacterScreen::update()
{
	selector->update(dt);
	title->update(dt, *window);
}

void SelectCharacterScreen::render()
{
	window->clear(sf::Color(38, 122, 233, 255));
	// draw stuff here
	//window->draw(testing);
		// draw selector
	selector->draw(*window);
		// draw title
	title->draw(*window);
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
		dt = clock.restart().asSeconds();
		// do the game
		handleEvents();
		update();
		render();
		checkQuit();
	}
}