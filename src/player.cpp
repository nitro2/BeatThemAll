#include <memory>
#include <cstdlib>
#include <string>
#include <iostream>
#include "player.hpp"

Player::Player(CHARACTER_TYPE c)
{
    switch (c)
    {
    case CHARACTER_TYPE::WARRIOR:
        this->character = std::make_shared<Warrior>();
        break;
    case CHARACTER_TYPE::WIZARD:
        this->character = std::make_shared<Wizard>();
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
    else
    {
        this->attack = 0;
        this->defend = 0;
        this->health = 0;
    }
    this->name = "Player" + std::to_string(1);
}

Player::~Player(){};

void Player::takeDamage(int damage)
{
    int actual_damage = (float)damage * (1 - ((0.06 * this->defend) / (1 + 0.06 * abs(this->defend))));
    std::cout << "Player " << this->name << " take " << damage
              << " but receive " << actual_damage << std::endl;
}

void Player::printStat()
{
    std::cout << "Player " << this->name
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
