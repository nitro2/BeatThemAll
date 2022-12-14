#ifndef _GAME_OBJECT_HPP_
#define _GAME_OBJECT_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include "gamecfg.hpp"
class GameObject
{
public:
    GameObject(){};
    ~GameObject(){};

    // Movement
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
