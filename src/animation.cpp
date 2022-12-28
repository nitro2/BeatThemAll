#include <iostream>
#include "animation.hpp"
Animation::Animation()
{
    this->uvRect.left = 0;
    this->uvRect.top = 0;
    this->uvRect.width = 0;
    this->uvRect.height = 0;
    this->isFinish = false;
    this->isRepeat = false;
}

void Animation::init(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    this->isFinish = false;
    this->totalTime = 0.0f;
    this->currentImage.x = 0;

    this->uvRect.width = texture->getSize().x / this->imageCount.x;
    this->uvRect.height = texture->getSize().y / this->imageCount.y;
}

void Animation::setRepeat(bool isRepeat)
{
    this->isRepeat = isRepeat;
}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime, bool faceRight)
{
    if (!this->isFinish || this->isRepeat)
    {
        this->currentImage.y = row;
        this->totalTime += deltaTime;
        if (this->totalTime >= this->switchTime)
        {
            this->totalTime -= this->switchTime;
            this->currentImage.x++;
            if (this->currentImage.x >= this->imageCount.x)
            {
                this->currentImage.x = 0;
                this->isFinish = true;
            }
        }

        if (faceRight)
        {
            this->uvRect.left = this->currentImage.x * this->uvRect.width;
            this->uvRect.width = abs(this->uvRect.width);
        }
        else
        {
            this->uvRect.left = (this->currentImage.x + 1) * abs(this->uvRect.width);
            this->uvRect.width = -abs(this->uvRect.width);
        }

        this->uvRect.top = this->currentImage.y * this->uvRect.height;
    }
}

bool Animation::isAnimationFinish()
{
    return this->isFinish;
}