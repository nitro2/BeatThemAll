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

std::shared_ptr<Player> Game::addPlayer(std::string name)
{
    for (auto &p : this->player_list)
    {
        if (p->getName() == name)
        {
            // Ignore if Player already created
            return nullptr;
        }
    }
    std::cout << "Created new player " << name << std::endl;
    auto p = std::make_shared<Player>(name);
    this->player_list.push_back(p);
    return p;
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

    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;

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
            case sf::Event::KeyPressed:
                // Manual add Player by pressing key for testing
                // MUST change in future
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
                {
                    auto p = this->addPlayer("Player1");
                    if (p)
                    {
                        p->setCharacter(Player::CHARACTER_TYPE::SKELETON);
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
                {
                    auto p = this->addPlayer("Player2");
                    if (p)
                    {
                        p->setCharacter(Player::CHARACTER_TYPE::WARRIOR);
                    }
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    // auto m = sf::Mouse::getPosition(this->window);
                    // std::cout << "Mouse click" << std::endl;
                }
                break;
            default:
                // std::cout << event.type << std::endl;f
                break;
            }
        }

        this->update();

        // draw...
        this->window->clear(sf::Color(0, 220, 220));
        this->draw();
        // end the current frame -- this is a rendering function (it requires the context to be active)
        this->window->display();
    }
}