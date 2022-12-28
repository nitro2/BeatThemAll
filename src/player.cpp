#include <memory>
#include <cstdlib>
#include <string>
#include <iostream>
#include "player.hpp"

Player::Player(std::string name) : GameObject(0, 0, CFG_CHARACTER_WIDTH, CFG_CHARACTER_HEIGHT)
{
    this->attack = 0;
    this->defend = 0;
    this->health = 0;
    this->name = name;
    this->velocity.x = 0;
    this->velocity.y = 0;
    this->ableJump = false;
    /* Add body of character */
    this->body = std::make_shared<DebugRectangle>(
        this->x, this->y, this->width, this->height, sf::Color(0, 255, 0, 100));
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
    this->x = x;
    this->y = y;
    this->body->setPosition(x, y);
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
    DEBUG_PRINT("");
    this->destroyCharacter();
    DEBUG_PRINT("");
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
    this->velocity.x -= CFG_CHARACTER_SPEED;
    this->character->moveLeft();
};

void Player::moveRight()
{
    // DEBUG_PRINT(this->name);
    this->velocity.x += CFG_CHARACTER_SPEED;
    this->character->moveRight();
};

void Player::jump()
{
    // DEBUG_PRINT(this->name);
    if (this->ableJump)
    {
        this->velocity.y -= sqrtf(2.0f * CFG_GRAVITATION_ACCELERATION * CFG_CHARACTER_JUMP_HEIGHT);
        this->character->jump();
        this->ableJump = false;
    }
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
    return sf::FloatRect(this->x - (this->width / 2.0f), this->y - this->height, this->width, this->height);
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

void Player::update(float deltaTime, std::vector<std::shared_ptr<GameObject>> obstructionList)
{
    /*
        v = v0 + a*t
        s = v*t
    */
    // Smooth movements
    if (this->velocity.x > 0)
    {
        this->velocity.x -= (CFG_CHARACTER_ACCELERATION * deltaTime) / 2.0f;
    }
    else
    {
        this->velocity.x += (CFG_CHARACTER_ACCELERATION * deltaTime) / 2.0f;
    }
    this->velocity.y += CFG_GRAVITATION_ACCELERATION * deltaTime;

    if (velocity.y > CFG_GRAVITY_MAX_FALLING)
    {
        velocity.y = CFG_GRAVITY_MAX_FALLING;
    }

    // Ignore smaller 1 pixel movements
    auto deltaX = this->velocity.x * deltaTime;
    if (abs(deltaX) < 1.0f)
    {
        deltaX = 0.0f;
    }
    auto deltaY = this->velocity.y * deltaTime;
    if (abs(deltaY) < 1.0f)
    {
        deltaY = 0.0f;
    }

    // Apply pending movements
    this->x += deltaX;
    this->y += deltaY;

    // Process gravity here
    for (auto obj : obstructionList)
    {
        sf::Vector2f pushBack(0, 0);
        while (obj->AABBCollision(this->getBody(), pushBack))
        {

            this->x += pushBack.x;
            this->y += pushBack.y;
            if (pushBack.y < 0)
            {
                this->velocity.y = 0;
                this->ableJump = true;
            }
        }
    }
    this->velocity.x *= 0.9f;

    this->body->setPosition(this->x, this->y);
    this->character->setPosition(this->x, this->y);
    this->character->update(deltaTime);
    // DEBUG_PRINT(" state=" << this->state
    //                       << " x=" << x
    //                       << " y=" << y
    //                       << " v_x=" << velocity.x
    //                       << " v_y=" << velocity.y);
}

void Player::render(std::shared_ptr<sf::RenderWindow> window)
{
    this->character->render(window);
}