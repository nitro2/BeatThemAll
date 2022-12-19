#include "wall.hpp"

Wall::Wall(float x, float y, float width, float height, sf::Color color)
    : GameObject(x, y, width, height)
{
    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    this->shape->setFillColor(color);
    this->shape->setOrigin(0, 0);
}

Wall::~Wall()
{
}

void Wall::render(std::shared_ptr<sf::RenderWindow> window)
{
    this->shape->setPosition(this->x, this->y);
    window->draw(*this->shape);
}
