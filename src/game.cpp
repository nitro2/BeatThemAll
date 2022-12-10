#include <iostream>

#include "game.hpp"

// Constructor
Game::Game()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1600, 900), "Beat them all");
    this->window->setVerticalSyncEnabled(true);
    // window.setFramerateLimit(24);
    this->window->setActive(false);

    // Test
    // auto c = std::make_shared<sf::Drawable>();

    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;
    auto characterIdleFrameNum = 11;
    std::string filename = "../assets/skeleton/Skeleton/Sprite_Sheets/Skeleton_Idle.png";
    std::cout << filename << std::endl;

    this->characterImg = std::make_shared<sf::Sprite>();
    this->characterTexture = std::make_shared<sf::Texture>();

    this->characterTexture->loadFromFile(filename);
    this->characterImg->setTexture(*this->characterTexture);
    this->characterImg->setPosition(200, 200);
    this->characterImg->setTextureRect(sf::IntRect(0, 0, this->characterTexture->getSize().x / characterIdleFrameNum,
                                                   this->characterTexture->getSize().y));

    this->drawable_obj_list.push_back(this->characterImg);
}
// Destructor
Game::~Game()
{
}

void Game::update()
{
}

void Game::draw()
{
    // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    this->window->setActive(false);

    for (auto &obj : this->drawable_obj_list)
    {
        if (obj)
        {
            this->window->draw(*obj);
        }
        else
        {
            std::cout << "Null object" << std::endl;
        }
    }
}

void Game::run()
{
    // run the program as long as the window is open
    while (this->window->isOpen())
    {
        // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            // "close requested" event: we close the window
            switch (event.type)
            {
            case sf::Event::Closed:
                this->window->close();
                break;
            default:
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            std::cout << "Down key" << std::endl;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // auto m = sf::Mouse::getPosition(this->window);
            std::cout << "Mouse click" << std::endl;
        }

        this->update();

        // draw...
        this->window->clear(sf::Color(0, 220, 220));
        this->draw();
        // end the current frame -- this is a rendering function (it requires the context to be active)
        this->window->display();
    }
}