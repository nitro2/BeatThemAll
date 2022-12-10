#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "gameobject.hpp"
#include "character.hpp"

class Player : public GameObject
{
public:
    enum class CHARACTER_TYPE
    {

        WARRIOR,
        WIZARD,
        SKELETON
    };

    Player(std::string name);
    Player(std::string name, CHARACTER_TYPE c);
    ~Player();

    std::string getName() { return this->name; };

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };
    void printStat();

    void setName(std::string name) { this->name = name; };
    void setCharacter(CHARACTER_TYPE c);

    // Movement
    void jump();

    // Attack animation
    void shoot();
    void swing();
    void throwAway();

    // Get hit animation
    void takeDamage(int damage);

    // Just for debugging
    void test();

private:
    std::string name;
    int attack;
    int defend;
    int health;
    std::shared_ptr<Character> character;
};

#endif // _PLAYER_HPP_
