#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "SFML/Graphics.hpp"
#include "gameobject.hpp"
#include "animation.hpp"

class Character : public GameObject, public sf::Sprite
{
public:
    Character();
    ~Character(){};

    enum State
    {
        Idle = 0,
        Walk = 1,
        Attack = 2,
        Hit = 3,
        Dead = 4,
        MaxState
    };

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };

    void update(float deltaTime);
    void setState(State s);

protected:
    int attack;
    int defend;
    int health;
    State state;

    sf::Texture characterTexture;

    std::vector<Animation> characterAnimations;
    int currentAnim;

    // Image handle
    void loadImage(std::string filename);

};

class Warrior : public Character
{
public:
    Warrior()
    {
        this->attack = CFG_WARRIOR_STAT_ATTACK;
        this->defend = CFG_WARRIOR_STAT_DEFEND;
        this->health = CFG_WARRIOR_STAT_HEALTH;
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

class Skeleton : public Character
{
public:
    Skeleton()
    {
        this->loadImage(CFG_SKELETON_IMG_PATH);
        this->setState(State::Idle);
        Animation idleAnim = Animation("idle");
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(0, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(1, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(2, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(3, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(4, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(5, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(6, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(7, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(8, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(9, 0)), std::make_tuple(0.1f)));
        idleAnim.addFrame(std::tuple_cat(idleAnim.grid(std::make_tuple(0, 0, 24, 32), std::make_pair(10, 0)), std::make_tuple(0.1f)));

        this->characterAnimations.push_back(idleAnim);
        this->attack = CFG_SKELETON_STAT_ATTACK;
        this->defend = CFG_SKELETON_STAT_DEFEND;
        this->health = CFG_SKELETON_STAT_HEALTH;
    }
    ~Skeleton(){};

private:
};

#endif // _CHARACTER_HPP_
