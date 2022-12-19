#include "box.hpp"

DebugRectangle::DebugRectangle(float x, float y, float width, float height, sf::Color color)
    : GameObject(x, y, width, height)
{
    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    this->shape->setFillColor(color);
    this->shape->setOrigin(this->width / 2, this->height);
    this->coordinate = std::make_shared<sf::Text>();
    if (!this->font.loadFromFile("assets/fonts/Mabook.ttf"))
    {
        DEBUG_PRINT("Error while loading font");
    }
    this->coordinate->setFont(this->font);
}

DebugRectangle::~DebugRectangle()
{
}

void DebugRectangle::render(std::shared_ptr<sf::RenderWindow> window)
{
    this->shape->setPosition(this->x, this->y);
    window->draw(*this->shape);

    this->coordinate->setPosition(this->x, this->y);
    auto str = std::to_string((int)this->x) + std::string(",") + std::to_string((int)this->y);
    this->coordinate->setString(str);
    window->draw(*this->coordinate);
}
