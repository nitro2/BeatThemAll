#include <iostream>
#include "animation.hpp"

Animation::Animation()
{
    uvRect.left = 0;
    uvRect.top = 0;
    uvRect.width = 0;
    uvRect.height = 0;
}

void Animation::init(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
    std::cout << float(imageCount.x) << " " << float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime)
{
    std::cout << __FUNCTION__ << " at line " << __LINE__
              << " totalTime=" << totalTime
              << " deltaTime=" << deltaTime
              << std::endl;
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}