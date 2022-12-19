#ifndef _GAME_OBJECT_HPP_
#define _GAME_OBJECT_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include "gamecfg.hpp"
class GameObject
{
public:
    GameObject(float x, float y, float width, float height);
    GameObject(){};
    ~GameObject(){};

    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    float getWidth();
    float getHeight();

    bool isCollision(const sf::FloatRect &other);
    sf::FloatRect getBounds();

    // Movement
    virtual void move(float delta_x, float delta_y);
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();

    virtual void render(std::shared_ptr<sf::RenderWindow> window);

protected:
    float width;
    float height;
    float x;
    float y;
};

#endif // _GAME_OBJECT_HPP_
