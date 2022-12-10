#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "SFML/Graphics.hpp"
#include "gameobject.hpp"

class Character : public GameObject, public sf::Sprite
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
