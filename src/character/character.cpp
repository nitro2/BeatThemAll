#include "character.hpp"

Character::Character()
{
    this->width = 240;
    this->height = 320;
    this->x = 100;
    this->y = 100;
}

void Character::loadImage(std::string filename)
{
    this->characterTexture.loadFromFile(filename);
    this->setTexture(this->characterTexture);
    float w = this->characterTexture.getSize().x / this->characterIdleFrameNum;
    float h = this->characterTexture.getSize().y;
    this->setTextureRect(sf::IntRect(0, 0, w, h));
    this->setScale(this->width / w, this->height / h);
    this->setPosition(sf::Vector2f({this->x, this->y}));
}