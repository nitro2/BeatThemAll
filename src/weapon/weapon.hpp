#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include "gameobject.hpp"

class Weapon : public GameObject
{
public:
    Weapon(){};
    ~Weapon(){};

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };

protected:
    int attack;
    int defend;
};

class Gun : public Weapon
{
public:
    Gun()
    {
        this->attack = 5;
        this->defend = 1;
    }
    ~Gun(){};
};

class Sword : public Weapon
{
public:
    Sword()
    {
        this->attack = 3;
        this->defend = 2;
    }
    ~Sword(){};
};

#endif // _WEAPON_HPP_
