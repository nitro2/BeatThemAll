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
        Walk,
        Attack,
        Hit,
        Dead,
        MaxState
    };

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };

    void update(float deltaTime);
    void draw();

    void setState(State s);

protected:
    int attack;
    int defend;
    int health;
    State state;

    // Image handle
    void loadImage(State state, std::string filename, int frames, float switchTime);

    typedef struct AnimationTexture_t
    {
        sf::Texture texture;
        int frames;
        unsigned int imgWidth;
        unsigned int imgHeight;
        float switchTime;
    } AnimationTexture_t;
    AnimationTexture_t aniTexture[State::MaxState];

    Animation characterAnimation;
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

class Skeleton : public Character
{
public:
    Skeleton()
    {
        this->loadImage(State::Idle, "assets/skeleton/Sprite_Sheets/Skeleton_Idle.png", 11, 0.08f);
        this->loadImage(State::Attack, "assets/skeleton/Sprite_Sheets/Skeleton_Attack.png", 18, 0.08f);
        this->loadImage(State::Dead, "assets/skeleton/Sprite_Sheets/Skeleton_Dead.png", 15, 0.08f);
        this->loadImage(State::Hit, "assets/skeleton/Sprite_Sheets/Skeleton_Hit.png", 8, 0.08f);
        this->loadImage(State::Walk, "assets/skeleton/Sprite_Sheets/Skeleton_Walk.png", 13, 0.08f);
        this->setState(State::Idle);
        this->attack = 10;
        this->defend = 5;
        this->health = 120;
    }
    ~Skeleton(){};

private:
};

#endif // _CHARACTER_HPP_
