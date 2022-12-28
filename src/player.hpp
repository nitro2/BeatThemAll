#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "gameobject.hpp"
#include "character.hpp"

class Player : public GameObject
{
public:
    Player(std::string name);
    Player(std::string name, Character::Type c);
    ~Player();

    std::string getName() { return this->name; };

    int getAttack() { return this->attack; };
    int getDefend() { return this->defend; };
    int getHealth() { return this->health; };
    void printStat();

    void setName(std::string name) { this->name = name; };
    void setCharacter(Character::Type c);
    void destroyCharacter();
    void setPosition(float x, float y);
    sf::Vector2f getPosition();

    // Bind keyboard to Player
    void bindKey(sf::Keyboard::Key kLeft, sf::Keyboard::Key kRight, sf::Keyboard::Key kJump, sf::Keyboard::Key kAttack);
    void pressKey(sf::Keyboard::Key key);
    void checkKeyPress();

    // Movement
    void moveLeft() override;
    void moveRight() override;
    void jump();

    bool isDead();
    bool isAttacking();
    // Attack animation
    void attackAct();
    sf::FloatRect getAttackRegion();
    sf::FloatRect getBody();

    // Get hit animation
    void beHit(int damage, float hitPower);
    void beKilled();
    void beDestroyed();

    std::vector<std::shared_ptr<GameObject>> getDrawableObjects();

    // Just for debugging
    void test();

    void update(float deltaTime, std::vector<std::shared_ptr<GameObject>> obstructionList);
    void render(std::shared_ptr<sf::RenderWindow> window) override;

private:
    std::string name;
    int attack;
    int defend;
    int health;

    // User input keys will be recorded here. Then update in update() function
    sf::Vector2f velocity;
    bool ableJump;

    std::shared_ptr<Character> character;
    std::shared_ptr<DebugRectangle> body; // Body is used to detect hit region when a player is hit/attacked.

    std::vector<std::shared_ptr<GameObject>> drawableObjList;
    std::map<sf::Keyboard::Key, void (Player::*)(void)> keyList;
};

#endif // _PLAYER_HPP_
