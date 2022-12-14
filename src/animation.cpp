#include <iostream>
#include "animation.hpp"
Animation::Animation()
{
    uvRect.left = 0;
    uvRect.top = 0;
    uvRect.width = 0;
    uvRect.height = 0;
    this->isFinish = false;
}

void Animation::init(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    this->isFinish = false;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / imageCount.x;
    uvRect.height = texture->getSize().y / imageCount.y;
}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime, bool faceRight)
{
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
            this->isFinish = true;
        }
    }

    if (faceRight)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }

    uvRect.top = currentImage.y * uvRect.height;
}

bool Animation::isAnimationFinish()
{
    return this->isFinish;
}