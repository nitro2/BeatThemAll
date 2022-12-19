#ifndef _BOX_HPP_
#define _BOX_HPP_

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"
#include "utils.hpp"

class DebugRectangle : public GameObject
{
public:
    DebugRectangle(float x, float y, float width, float height, sf::Color color);
    ~DebugRectangle();

    void render(std::shared_ptr<sf::RenderWindow> window);

private:
    std::shared_ptr<sf::RectangleShape> shape;
    std::shared_ptr<sf::Text> coordinate;
    sf::Font font;
};

#endif // _BOX_HPP_
