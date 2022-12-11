#ifndef _GAME_OBJECT_HPP_
#define _GAME_OBJECT_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
class GameObject : public sf::Drawable
{
public:
    GameObject(){};
    ~GameObject(){};

    // Movement
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

protected:
    float width;
    float height;
    float x;
    float y;
};

#endif // _GAME_OBJECT_HPP_
