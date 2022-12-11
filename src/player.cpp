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
}

Player::Player(std::string name, CHARACTER_TYPE c) : Player(name)
{
    this->setCharacter(c);
}

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
    }
}

Player::~Player(){};

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
