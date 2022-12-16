#include <memory>
#include <cstdlib>
#include <string>
#include <iostream>
#include "player.hpp"

Player::Player(std::string name)
{
    this->attack = 0;
    this->defend = 0;
    this->health = 0;
    this->name = name;
    this->movementSpeed = 30.f;
}

Player::Player(std::string name, CHARACTER_TYPE c) : Player(name)
{
    this->setCharacter(c);
}

Player::~Player(){};

void Player::setCharacter(CHARACTER_TYPE c)
{
    switch (c)
    {
    case CHARACTER_TYPE::WARRIOR:
        this->character = std::make_shared<Warrior>();
        break;
    case CHARACTER_TYPE::WIZARD:
        this->character = std::make_shared<Wizard>();
        break;
    case CHARACTER_TYPE::SKELETON:
        this->character = std::make_shared<Skeleton>();
        break;

    default:
        break;
    }
    if (this->character)
    {
        this->attack = this->character->getAttack();
        this->defend = this->character->getDefend();
        this->health = this->character->getHealth();
        // this->character.setPosition()
    }
    else
    {
        DEBUG_PRINT("Failed to create character");
    }
}

void Player::setPosition(float x, float y)
{
    this->character->setPosition(x, y);
}

void Player::takeDamage(int damage)
{
    int actual_damage = (float)damage * (1 - ((0.06f * this->defend) / (1 + 0.06f * abs(this->defend))));
    std::cout << this->name << " take " << damage
              << " but receive " << actual_damage << std::endl;
}

void Player::printStat()
{
    std::cout << this->name
              << " attack=" << this->attack
              << " defend=" << this->defend
              << " health=" << this->health
              << std::endl;
}

void Player::test()
{
    for (auto i = 0; i < 100; i++)
    {
        this->takeDamage(i);
        this->printStat();
    }
}

void Player::moveLeft()
{
    // DEBUG_PRINT(this->name);
    this->character->movementAct(-this->movementSpeed, 0.f);
};

void Player::moveRight()
{
    // DEBUG_PRINT(this->name);
    this->character->movementAct(this->movementSpeed, 0.f);
};

void Player::jump()
{
    // DEBUG_PRINT(this->name);
}

void Player::attackAct()
{
    // DEBUG_PRINT(this->name);
    this->character->attackAct();
}

void Player::bindKey(sf::Keyboard::Key kLeft, sf::Keyboard::Key kRight, sf::Keyboard::Key kJump, sf::Keyboard::Key kAttack)
{
    this->keyList[kLeft] = &Player::moveLeft;
    this->keyList[kRight] = &Player::moveRight;
    this->keyList[kJump] = &Player::jump;
    this->keyList[kAttack] = &Player::attackAct;
}

void Player::pressKey(sf::Keyboard::Key key)
{
    // Check if the key exist then call the binding function to handle the button
    if (this->keyList.count(key) > 0)
    {
        (this->*(this->keyList[key]))();
    }
}

std::shared_ptr<GameObject> Player::getDrawableObject()
{
    return this->character;
}