#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "gameobject.hpp"
#include "character.hpp"
#include "weapon.hpp"

class Player : public GameObject
{
public:
    enum class CHARACTER_TYPE
    {
        WARRIOR,
        WIZARD
    };

    Player(CHARACTER_TYPE c);
    ~Player();

private:
    int attack;
    int defend;
    int health;
    std::shared_ptr<Character> character;
    std::shared_ptr<Weapon> weapon;
};

#endif // _PLAYER_HPP_
