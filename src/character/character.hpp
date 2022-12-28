#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <math.h>

#include "SFML/Graphics.hpp"
#include "gameobject.hpp"
#include "animation.hpp"
#include "debug/box.hpp"

class Character : public GameObject
{
public:
    Character();
    ~Character(){};

    enum class Type
    {
        KNIGHT,
        NINJA,
        SKELETON,
        WARRIOR,
        WIZARD
    };

    typedef enum State
    {
        // States that have images
        Idle = 0,
        Walk,
        Attack,
        Hit,
        Jump,
        Dead,
        MaxImageStates,
        Init = MaxImageStates,
        End
    } State;

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };

    void setPosition(float x, float y);
    sf::FloatRect getBounds() override;
    bool isFaceRight();

    void update(float deltaTime);
    void moveLeft() override;
    void moveRight() override;
    void jump();

    void attackAct();
    void render(std::shared_ptr<sf::RenderWindow> window) override;

    bool setState(State s);
    State getState();

protected:
    int attack;
    int defend;
    int health;
    State state;

    typedef struct AnimationTexture_t
    {
        sf::Texture texture;
        int frames;
        unsigned int imgWidth;
        unsigned int imgHeight;
        float switchTime;
    } AnimationTexture_t;
    AnimationTexture_t aniTexture[State::MaxImageStates];
    float scale;

    Animation characterAnimation;
    sf::Sprite characterImg;
    bool faceRight;

    // Image handle
    void loadImage(State state, std::string filename, int frames, float switchTime);
};

class Knight : public Character
{
public:
    Knight();
    ~Knight();
};

class Ninja : public Character
{
public:
    Ninja();
    ~Ninja();
};

class Skeleton : public Character
{
public:
    Skeleton();
    ~Skeleton();
};

class Warrior : public Character
{
public:
    Warrior();
    ~Warrior();
};

class Wizard : public Character
{
public:
    Wizard();
    ~Wizard();
};

#endif // _CHARACTER_HPP_
