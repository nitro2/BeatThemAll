#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "SFML/Graphics.hpp"
#include "gameobject.hpp"
#include "animation.hpp"

class Character : public GameObject
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
    void movement(float delta_x, float delta_y);
    void render(std::shared_ptr<sf::RenderWindow> window);

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
    sf::Sprite body;
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
        this->loadImage(State::Idle, CFG_SKELETON_IMG_IDLE_PATH, CFG_SKELETON_IMG_IDLE_FRAMES, CFG_SKELETON_IMG_SWITCH_TIME);
        this->loadImage(State::Attack, CFG_SKELETON_IMG_ATTACK_PATH, CFG_SKELETON_IMG_ATTACK_FRAMES, CFG_SKELETON_IMG_SWITCH_TIME);
        this->loadImage(State::Dead, CFG_SKELETON_IMG_DEAD_PATH, CFG_SKELETON_IMG_DEAD_FRAMES, CFG_SKELETON_IMG_SWITCH_TIME);
        this->loadImage(State::Hit, CFG_SKELETON_IMG_HIT_PATH, CFG_SKELETON_IMG_HIT_FRAMES, CFG_SKELETON_IMG_SWITCH_TIME);
        this->loadImage(State::Walk, CFG_SKELETON_IMG_WALK_PATH, CFG_SKELETON_IMG_WALK_FRAMES, CFG_SKELETON_IMG_SWITCH_TIME);
        this->setState(State::Idle);
        this->attack = CFG_SKELETON_STAT_ATTACK;
        this->defend = CFG_SKELETON_STAT_DEFEND;
        this->health = CFG_SKELETON_STAT_HEALTH;
    }
    ~Skeleton(){};

private:
};

#endif // _CHARACTER_HPP_
