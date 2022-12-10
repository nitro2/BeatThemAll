#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "gameobject.hpp"
#include "SFML/Graphics.hpp"

class Character : public GameObject
{
public:
    Character(){};
    ~Character(){};

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };

    void update();
    void draw();

protected:
    int attack;
    int defend;
    int health;
    sf::Sprite characterImg;
    sf::Texture characterTexture;
    int characterIdleFrameNum;
};

class Warrior : public Character
{
public:
    Warrior()
    {
        this->attack = 10;
        this->defend = 5;
        this->health = 120;
    }
    ~Warrior(){};
};

class Wizard : public Character
{
public:
    Wizard()
    {
        this->attack = 15;
        this->defend = 3;
        this->health = 100;
    }
    ~Wizard(){};
};

#endif // _CHARACTER_HPP_
