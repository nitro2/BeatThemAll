#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "gameobject.hpp"
#include "character.hpp"

class Player
{
public:
    enum class CHARACTER_TYPE
    {
        KNIGHT,
        NINJA,
        SKELETON,
        WARRIOR,
        WIZARD
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
    void destroyCharacter();
    void setPosition(float x, float y);
    sf::Vector2f getPosition();

    // Bind keyboard to Player
    void bindKey(sf::Keyboard::Key kLeft, sf::Keyboard::Key kRight, sf::Keyboard::Key kJump, sf::Keyboard::Key kAttack);
    void pressKey(sf::Keyboard::Key key);
    void checkKeyPress();

    // Movement
    void moveLeft();
    void moveRight();
    void jump();

    // Attack animation
    void attackAct();
    bool isAttacking();
    sf::FloatRect getAttackRegion();
    sf::FloatRect getBody();

    // Get hit animation
    void beHit(int damage, float hitPower);
    void beKilled();

    std::vector<std::shared_ptr<GameObject>> getDrawableObjects();

    // Just for debugging
    void test();

private:
    std::string name;
    int attack;
    int defend;
    int health;
    std::shared_ptr<Character> character;

    std::vector<std::shared_ptr<GameObject>> drawableObjList;
    std::map<sf::Keyboard::Key, void (Player::*)(void)> keyList;
};

#endif // _PLAYER_HPP_
