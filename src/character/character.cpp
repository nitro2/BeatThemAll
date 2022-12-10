#include "character.hpp"

Character::Character()
{
    this->width = 240;
    this->height = 320;
    this->x = 100;
    this->y = 100;
    characterAnimation = std::make_shared<Animation>(&characterTexture, sf::Vector2u(0, 11), 0.1f);
}

void Character::loadImage(std::string filename)
{
    std::cout << __FUNCTION__ << " at line " << __LINE__
              << " Load path " << filename
              << std::endl;
    // this->characterTexture.loadFromFile(filename, sf::IntRect(sf::Vector2i(this->x, this->y),sf::Vector2i(this->width, this->height)));
    this->characterTexture.loadFromFile(filename);
}

void Character::update(float deltaTime) {

}