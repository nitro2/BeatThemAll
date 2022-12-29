#include <iostream>
#include <filesystem>
#include "game.hpp"
#include "grid.hpp"
#include "utils.hpp"
#include "map.hpp"

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)

// Constructor
Game::Game()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Beat them all");
    this->window->setPosition({0, 0});
    this->window->setVerticalSyncEnabled(true);
    // DEBUG: Enable this for testing in slow speed
    this->window->setFramerateLimit(60);
    this->window->setActive(false);

    // Add map background and walls
    auto map = std::make_shared<Map>(SCREEN_WIDTH, SCREEN_HEIGHT);
    map->loadMap("assets/map/map1.txt", false);
    this->gameObjList.push_back(map);
    auto m = map->getWallList();
    this->obstructionList.insert(this->obstructionList.end(), m.begin(), m.end());

    // Add grid to debug pixels
    auto grid = std::make_shared<Grid>(sf::Vector2f(0, 0), 12, 21, 100.0f, sf::Color::Red);
    this->gameObjList.push_back(grid);
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
            p->setCharacter(Character::Type::WARRIOR);
            p->setPosition(300, 400);
            // Bind movement keys to Player1
            p->bindKey(sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::W, sf::Keyboard::Key::F);
            this->gameObjList.push_back(p);
        }
        break;
    }
    case sf::Keyboard::Key::Num2:
    {
        auto p = this->addPlayer("Player2");
        if (p)
        {
            DEBUG_PRINT("Created Player 2");
            p->setCharacter(Character::Type::NINJA);
            p->setPosition(800, 600);
            // Bind movement keys to Player2
            p->bindKey(sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up, sf::Keyboard::Key::M);
            this->gameObjList.push_back(p);
        }
        break;
    }
    case sf::Keyboard::Key::Num3:
    {
        auto p = this->addPlayer("Player3");
        if (p)
        {
            DEBUG_PRINT("Created Player 3");
            p->setCharacter(Character::Type::KNIGHT);
            p->setPosition(500, 400);
            // Bind movement keys to Player3
            p->bindKey(sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::W, sf::Keyboard::Key::F);
            this->gameObjList.push_back(p);
        }
        break;
    }
    case sf::Keyboard::Key::Num4:
    {
        auto p = this->addPlayer("Player4");
        if (p)
        {
            DEBUG_PRINT("Created Player 4");
            p->setCharacter(Character::Type::SKELETON);
            p->setPosition(1000, 400);
            // Bind movement keys to Player2
            p->bindKey(sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up, sf::Keyboard::Key::M);
            this->gameObjList.push_back(p);
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
    for (auto &obj : this->gameObjList)
    {
        // TODO: check why this not work
        // if (instanceof <Character>(obj))
        auto p = std::dynamic_pointer_cast<Player>(obj);
        if (p)
        {
            p->update(deltaTime, obstructionList);
        }
    }

    // Process events
    for (auto &p : this->playerList)
    {
        // Player will be death if moving outside of the screen
        // Double screen height for better experience
        if (!sf::FloatRect(0, -SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT * 2).contains(p->getPosition()))
        {
            // DEBUG_PRINT("Player is outside");
            p->beKilled();
        }

        // Check if the player is attacking
        if (p->isAttacking())
        {
            // Check if any enemy being hit in the attack region
            for (auto &e : this->playerList)
            {
                if (p->getName() != e->getName())
                {
                    if (p->getAttackRegion().intersects(e->getBody()))
                    {
                        float hitPower = (p->getPosition().x < e->getPosition().x) ? CFG_HIT_POWER : -CFG_HIT_POWER;
                        e->beHit(p->getAttack(), hitPower);
                        // DEBUG_PRINT(p->getName() << " attacked " << e->getName());
                        // TODO: add beHit to later process to make sure we have equal chance of attacking process, not FIFO
                    }
                }
            }
        }

        if (p->getHealth() <= 0)
        {
            p->beKilled();
            // DEBUG_PRINT(p->getName() << " is dead");
        }
    }

    // Process post-event
    for (auto it = this->playerList.begin(); it != this->playerList.end();)
    {
        if ((*it)->isDead())
        {
            (*it)->beDestroyed();
            it = this->playerList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::draw()
{
    this->window->setActive(false);

    for (auto &obj : this->gameObjList)
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
        // prevent bug when the framerate lower than 20fps
        if (deltaTime > 1.0f / 20.0f)
        {
            deltaTime = 1.0f / 20.0f;
        }
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
        this->window->clear();
        this->draw();
        this->window->display();
    }
}
