#include <iostream>
#include <filesystem>
#include "game.hpp"
#include "character.hpp"
// Constructor
Game::Game()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1600, 900), "Beat them all");
    this->window->setPosition({0, 0});
    this->window->setVerticalSyncEnabled(true);
    // window.setFramerateLimit(24);
    this->window->setActive(false);

    // Test
    auto s = std::make_shared<Skeleton>();
    this->drawable_obj_list.push_back(s);
}
// Destructor
Game::~Game()
{
}

void Game::update(float deltaTime)
{
    for (auto& obj : this->drawable_obj_list)
    {
        std::shared_ptr<Character> derived =
            std::dynamic_pointer_cast<Character>(obj);
        derived->update(deltaTime);
    }
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

    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;
    this->window->setActive(true);

    // delta time
    float deltaTime = 0.0f;
    sf::Clock clock;

    // run the program as long as the window is open
    while (this->window->isOpen())
    {
        // update delta time
        deltaTime = clock.restart().asSeconds();
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
            // std::cout << "Mouse click" << std::endl;
        }

        this->update(deltaTime);

        // draw...
        this->window->clear(sf::Color(0, 220, 220));
        this->draw();
        // end the current frame -- this is a rendering function (it requires the context to be active)
        this->window->display();
    }
}