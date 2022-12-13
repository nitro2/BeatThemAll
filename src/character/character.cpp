#include "character.hpp"

Character::Character()
{
    this->width = CFG_CHARACTER_WIDTH;
    this->height = CFG_CHARACTER_HEIGHT;
    this->x = 100;
    this->y = 100;
    this->state = State::Idle;
    this->currentAnim = this->state;
}

void Character::loadImage(std::string filename)
{
    characterTexture.loadFromFile(filename);
    this->setTexture(characterTexture);
}

void Character::update(float deltaTime)
{
    this->characterAnimations[this->currentAnim].update(deltaTime);
    int x, y, width, height; float time;
    std::tie(x, y, width, height, time) = this->characterAnimations[this->currentAnim].getCurrentFrameInfo();
    this->setTextureRect(sf::IntRect(x, y, width, height));
    this->setOrigin(width/2, height/2);
    this->setPosition(12, 16);
}

void Character::setState(State s)
{
    switch (s)
    {
    case State::Walk:
        break;
    case State::Attack:
        break;
    case State::Hit:
        break;
    case State::Dead:
        break;
    case State::Idle:
    default:
        break;
    }
    this->state = s;

    /*// Change image with to animation if needed
    AnimationTexture_t *ani = &aniTexture[s];
    this->setTexture(aniTexture[this->state].texture);
    this->characterAnimation.init(&ani->texture, sf::Vector2u(ani->frames, 1), ani->switchTime);
    this->setTextureRect(sf::IntRect(0, 0, ani->imgWidth, ani->imgHeight));
    // In case the image is smaller than expected rectangle, we have to scale it up
    this->setScale(this->width / ani->imgWidth, this->height / ani->imgHeight);
    // TODO: No need to change position
    this->setPosition(sf::Vector2f({this->x, this->y}));*/


}