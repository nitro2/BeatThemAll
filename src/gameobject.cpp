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

bool GameObject::isCollision(const sf::FloatRect &other)
{
    return this->getBounds().intersects(other);
}

/* Check collision and push back the object */
bool GameObject::AABBCollision(const sf::FloatRect &otherRect, sf::Vector2f &pushBack)
{
    auto thisRect = this->getBounds();
    float deltaX = otherRect.left - thisRect.left;
    float deltaY = otherRect.top - thisRect.top;
    float intersectX = abs(deltaX) - (otherRect.width + thisRect.width) / 2.0f;
    float intersectY = abs(deltaY) - (otherRect.height + thisRect.height) / 2.0f;
    pushBack.x = 0.0f;
    pushBack.y = 0.0f;

    if ((intersectX < 0.0f) && (intersectY < 0.0f))
    {
        if (intersectX > intersectY)
        {
            if (deltaX > 0.0f)
            {
                pushBack.x = -intersectX;
            }
            else
            {
                pushBack.x = intersectX;
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                pushBack.y = -intersectY;
            }
            else
            {
                pushBack.y = intersectY;
            }
        }
        return true;
    }
    return false;
}

sf::FloatRect GameObject::getBounds()
{
    return sf::FloatRect(this->x, this->y, this->width, this->height);
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
