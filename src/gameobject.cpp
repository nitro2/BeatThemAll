#include "gameobject.hpp"

GameObject::GameObject(float x, float y, float width, float height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void GameObject::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

sf::Vector2f GameObject::getPosition()
{
    return sf::Vector2f(this->x, this->y);
}

float GameObject::getWidth()
{
    return this->width;
}

float GameObject::getHeight()
{
    return this->height;
}

void GameObject::move(float delta_x, float delta_y)
{
    // DEBUG_PRINT("");
    this->x += delta_x;
    this->y += delta_y;
};

void GameObject::moveLeft()
{
    DEBUG_PRINT("");
};

void GameObject::moveRight()
{
    DEBUG_PRINT("");
};

void GameObject::moveUp()
{
    DEBUG_PRINT("");
};

void GameObject::moveDown()
{
    DEBUG_PRINT("");
};

void GameObject::render(std::shared_ptr<sf::RenderWindow> window)
{
    DEBUG_PRINT("");
}
