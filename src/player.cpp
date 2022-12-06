#include <memory>
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
}

Player::~Player(){};