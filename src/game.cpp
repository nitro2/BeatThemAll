#include <iostream>
#include <filesystem>
#include "game.hpp"
#include "grid.hpp"
#include "character.hpp"
#include "utils.hpp"
#include "wall.hpp"
// Constructor
Game::Game()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Beat them all");
    this->window->setPosition({0, 0});
    this->window->setVerticalSyncEnabled(true);
    // DEBUG: Enable this for testing in slow speed
    this->window->setFramerateLimit(60);
    this->window->setActive(false);

    // Test
    // auto s = std::make_shared<Skeleton>();
    // this->drawableObjList.push_back(s);

    // Add grid to debug pixels
    auto grid = std::make_shared<Grid>(sf::Vector2f(0, 0), 11, 20, 100.0f, sf::Color::Red);
    this->drawableObjList.push_back(grid);

    // Create test wall , we will create map later
    auto wall = std::make_shared<Wall>(960.0f, 850.0f, 800.0f, 150.0f, sf::Color::White);
    this->drawableObjList.push_back(wall);
}
// Destructor
Game::~Game()
{
}

std::shared_ptr<Player> Game::addPlayer(std::string name)
{
    for (auto &p : this->playerList)
    {
        if (p->getName() == name)
        {
            // Ignore if Player already created
            return nullptr;
        }
    }
    std::cout << "Created new player " << name << std::endl;
    auto p = std::make_shared<Player>(name);
    this->playerList.push_back(p);
    return p;
}

std::shared_ptr<Player> Game::getPlayer(const std::string &name)
{
    for (auto &p : this->playerList)
    {
        if (p->getName() == name)
        {
            return p;
        }
    }
    return nullptr;
}

void Game::handleButton(const sf::Event &event)
{
    // Manual add Player by pressing key for testing
    // MUST change in future
    // DEBUG_PRINT("Pressed key=" << event.key.code);
    switch (event.key.code)
    {
    case sf::Keyboard::Key::Num1:
    {
        auto p = this->addPlayer("Player1");
        if (p)
        {
            DEBUG_PRINT("Created Player 1");
            p->setCharacter(Player::CHARACTER_TYPE::SKELETON);
            p->setPosition(100, 400);
            // Bind movement keys to Player1
            p->bindKey(sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::W, sf::Keyboard::Key::F);
            // Draw all objects associate with the player
            for (auto &obj : p->getDrawableObjects())
            {
                this->drawableObjList.push_back(obj);
            }
        }
        break;
    }
    case sf::Keyboard::Key::Num2:
    {
        auto p = this->addPlayer("Player2");
        if (p)
        {
            DEBUG_PRINT("Created Player 2");
            p->setCharacter(Player::CHARACTER_TYPE::SKELETON);
            p->setPosition(800, 400);
            // Bind movement keys to Player2
            p->bindKey(sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up, sf::Keyboard::Key::M);
            // Draw all objects associate with the player
            for (auto &obj : p->getDrawableObjects())
            {
                this->drawableObjList.push_back(obj);
            }
        }
        break;
    }
    default:
        for (auto &p : this->playerList)
        {
            p->checkKeyPress();
        }
        break;
    }
}

void Game::update(float deltaTime)
{
    for (auto &obj : this->drawableObjList)
    {
        // TODO: check why this not work
        // if (instanceof <Character>(obj))
        auto p = std::dynamic_pointer_cast<Character>(obj);
        if (p)
        {
            std::dynamic_pointer_cast<Character>(obj)->update(deltaTime);
        }
    }
}

void Game::draw()
{
    this->window->setActive(false);

    for (auto &obj : this->drawableObjList)
    {
        if (obj)
        {
            // this->window->draw(*obj);
            obj->render(this->window);
        }
        else
        {
            std::cout << "Null object" << std::endl;
        }
    }
}

void Game::run()
{

    DEBUG_PRINT("running");
    this->window->setActive(true);

    // delta time
    float deltaTime = 0.0f;
    sf::Clock clock;

    // run the program as long as the window is open
    while (this->window->isOpen())
    {
        // update delta time
        deltaTime = clock.restart().asSeconds();
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
                this->handleButton(event);
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    // auto m = sf::Mouse::getPosition(this->window);
                    // std::cout << "Mouse click" << std::endl;
                }
                break;
            default:
                break;
            }
        }

        this->update(deltaTime);

        // draw...
        this->window->clear(sf::Color(0, 220, 220));
        this->draw();
        this->window->display();
    }
}