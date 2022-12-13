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
    std::tuple<float, float, float, float> getRect();

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
        //================================================= ANIMATE THE CHARACTER ===================================================
        Animation idleAnim = Animation("idle", 8, 12, 16);
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
        Animation walkAnim = Animation("walk", 8, 11, 16.5);
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(0, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(1, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(2, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(3, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(4, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(5, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(6, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(7, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(8, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(9, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(10, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(11, 0)), std::make_tuple(0.1f)));
        walkAnim.addFrame(std::tuple_cat(walkAnim.grid(std::make_tuple(0, 32, 22, 33), std::make_pair(12, 0)), std::make_tuple(0.1f)));
        Animation attackAnim = Animation("attack", 8, 11, 18.5);
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(0, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(1, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(2, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(3, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(4, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(5, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(6, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(7, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(8, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(9, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(10, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(11, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(12, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(13, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(14, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(15, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(16, 0)), std::make_tuple(0.1f)));
        attackAnim.addFrame(std::tuple_cat(attackAnim.grid(std::make_tuple(0, 65, 43, 37), std::make_pair(17, 0)), std::make_tuple(0.1f)));
        Animation hitAnim = Animation("hit", 8, 15, 16);
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(0, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(1, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(2, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(3, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(4, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(5, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(6, 0)), std::make_tuple(0.1f)));
        hitAnim.addFrame(std::tuple_cat(hitAnim.grid(std::make_tuple(0, 134, 30, 32), std::make_pair(7, 0)), std::make_tuple(0.1f)));
        //===========================================================================================================================
        Animation deadAnim = Animation("dead", 8, 16.5, 16);
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(0, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(1, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(2, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(3, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(4, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(5, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(6, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(7, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(8, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(9, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(10, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(11, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(12, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(13, 0)), std::make_tuple(0.1f)));
        deadAnim.addFrame(std::tuple_cat(deadAnim.grid(std::make_tuple(0, 166, 33, 32), std::make_pair(14, 0)), std::make_tuple(0.1f)));

        
        this->characterAnimations.push_back(idleAnim);
        this->characterAnimations.push_back(walkAnim);
        this->characterAnimations.push_back(attackAnim);
        this->characterAnimations.push_back(hitAnim);
        this->characterAnimations.push_back(deadAnim);
        this->attack = CFG_SKELETON_STAT_ATTACK;
        this->defend = CFG_SKELETON_STAT_DEFEND;
        this->health = CFG_SKELETON_STAT_HEALTH;
    }
    ~Skeleton(){};

private:
};

#endif // _CHARACTER_HPP_
