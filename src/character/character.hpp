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

    typedef enum State
    {
        Idle = 0,
        Walk,
        Attack,
        Hit,
        Dead,
        Jump,
        MaxState
    } State;

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };

    void setPosition(float x, float y);
    sf::FloatRect getBounds() override;
    bool isFaceRight();

    void update(float deltaTime, std::vector<std::shared_ptr<GameObject>> obstructionList);
    void movementAct(float delta_x, float delta_y);
    void moveLeft() override;
    void moveRight() override;
    void jump();

    void attackAct();
    void render(std::shared_ptr<sf::RenderWindow> window) override;

    void setState(State s);
    State getState();

protected:
    int attack;
    int defend;
    int health;
    State state;

    // User input keys will be recorded here. Then update in update() function
    sf::Vector2f velocity;
    bool ableJump;

    typedef struct AnimationTexture_t
    {
        sf::Texture texture;
        int frames;
        unsigned int imgWidth;
        unsigned int imgHeight;
        float switchTime;
    } AnimationTexture_t;
    AnimationTexture_t aniTexture[State::MaxState];
    float scale;

    Animation characterAnimation;
    sf::Sprite characterImg;
    bool faceRight;

    std::shared_ptr<DebugRectangle> body; // Body is used to detect hit region when a player is hit/attacked.
    std::shared_ptr<DebugRectangle> attackRegion;

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
