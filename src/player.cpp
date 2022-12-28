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

Player::~Player(){};

void Player::setCharacter(CHARACTER_TYPE c)
{
    switch (c)
    {

    case CHARACTER_TYPE::KNIGHT:
        this->character = std::make_shared<Knight>();
        break;
    case CHARACTER_TYPE::NINJA:
        this->character = std::make_shared<Ninja>();
        break;
    case CHARACTER_TYPE::SKELETON:
        this->character = std::make_shared<Skeleton>();
        break;
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
        this->drawableObjList.push_back(this->character);
    }
    else
    {
        DEBUG_PRINT("Failed to create character");
    }
}

void Player::destroyCharacter()
{
    this->drawableObjList.clear();
}

void Player::setPosition(float x, float y)
{
    this->character->setPosition(x, y);
}

sf::Vector2f Player::getPosition()
{
    return this->character->getPosition();
}

void Player::beHit(int damage, float hitPower)
{
    // Only take damge 1 time
    if (this->character->setState(Character::State::Hit))
    {
        int actual_damage = static_cast<int>(static_cast<float>(damage) * (1 - ((0.06f * this->defend) / (1 + 0.06f * abs(this->defend)))));
        this->health -= actual_damage;
        std::cout << this->name << " take " << damage
                  << " but receive " << actual_damage << "damage. Health=" << this->health << std::endl;
    }
    this->character->move(hitPower, 0.0f);
}

void Player::beKilled()
{
    this->character->setState(Character::State::Dead);
}

void Player::beDestroyed()
{
    this->health = 0;
    this->destroyCharacter();
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
        this->beHit(i, CFG_HIT_POWER);
        this->printStat();
    }
}

void Player::moveLeft()
{
    // DEBUG_PRINT(this->name);
    this->character->moveLeft();
};

void Player::moveRight()
{
    // DEBUG_PRINT(this->name);
    this->character->moveRight();
};

void Player::jump()
{
    // DEBUG_PRINT(this->name);
    this->character->jump();
}

bool Player::isDead()
{
    // Return only if the Dead animation finishes
    return this->character->getState() == Character::State::End;
}

bool Player::isAttacking()
{
    return this->character->getState() == Character::State::Attack;
}

void Player::attackAct()
{
    // DEBUG_PRINT(this->name);
    this->character->attackAct();
}

sf::FloatRect Player::getAttackRegion()
{
    sf::FloatRect a = this->character->getBounds();
    // Attack region is faceup 1/3 of width
    if (this->character->isFaceRight())
    {
        return sf::FloatRect(a.left + a.width / 3.0, a.top, a.width, a.height);
    }
    else
    {
        return sf::FloatRect(a.left - a.width / 3.0, a.top, a.width, a.height);
    }
}

sf::FloatRect Player::getBody()
{
    return this->character->getBounds();
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

void Player::checkKeyPress()
{
    // Simultaneously check and do key action
    for (auto &k : this->keyList)
    {
        auto key = k.first;
        // TODO: Determine which action takes highest priority
        // Eg: When player presses Attack, then he cannot move?
        if (sf::Keyboard::isKeyPressed(key))
        {
            if (this->keyList.count(key) > 0)
            {
                (this->*(this->keyList[key]))();
            }
        }
    }
}

std::vector<std::shared_ptr<GameObject>> Player::getDrawableObjects()
{
    return this->drawableObjList;
}