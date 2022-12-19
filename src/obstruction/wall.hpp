#ifndef _WALL_HPP_
#define _WALL_HPP_

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"

class Wall : public GameObject
{
public:
    Wall(float x, float y, float width, float height, sf::Color color);
    ~Wall();

    void render(std::shared_ptr<sf::RenderWindow> window);

private:
    std::shared_ptr<sf::RectangleShape> shape;
};

#endif // _WALL_HPP_
