#include "debug.hpp"

DebugRectangle::DebugRectangle(float x, float y, float width, float height, sf::Color color)
    : GameObject(x, y, width, height)
{
    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    this->shape->setFillColor(color);
    this->shape->setOrigin(this->width / 2, this->height);
}

DebugRectangle::~DebugRectangle()
{
}

void DebugRectangle::render(std::shared_ptr<sf::RenderWindow> window)
{
    this->shape->setPosition(this->x, this->y);
    window->draw(*this->shape);
}
