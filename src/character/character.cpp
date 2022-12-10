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
    std::cout << __FUNCTION__ << " at line " << __LINE__
              << " Load path " << filename
              << std::endl;
    // this->characterTexture.loadFromFile(filename, sf::IntRect(sf::Vector2i(this->x, this->y),sf::Vector2i(this->width, this->height)));
    this->characterTexture.loadFromFile(filename);
    this->setTexture(this->characterTexture);
    auto w = this->characterTexture.getSize().x / this->characterIdleFrameNum;
    auto h = this->characterTexture.getSize().y;
    this->setTextureRect(sf::IntRect(0, 0, w, h));
    this->setScale(this->width / w, this->height / h);
    this->setPosition(sf::Vector2f({this->x, this->y}));
}

void Character::update(float deltaTime) {
    this->characterAnimation.update(0, deltaTime);

    this->setTextureRect(this->characterAnimation.uvRect);
}