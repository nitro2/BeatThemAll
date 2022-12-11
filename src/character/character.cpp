#include "character.hpp"

Character::Character()
{
    this->width = 240;
    this->height = 320;
    this->x = 100;
    this->y = 100;
}

void Character::loadImage(State state, std::string filename, int frames)
{
    AnimationTexture_t *ani = &aniTexture[state];
    ani->frames = frames;
    ani->texture.loadFromFile(filename);

    this->setTexture(ani->texture);
    auto w = ani->texture.getSize().x / ani->frames;
    auto h = ani->texture.getSize().y;
    this->setTextureRect(sf::IntRect(0, 0, w, h));
    // In case the image is smaller than expected rectangle, we have to scale it up
    this->setScale(this->width / w, this->height / h);
    this->setPosition(sf::Vector2f({this->x, this->y}));
    DEBUG_PRINT(" Load path " << filename
                              << " w=" << w << " h=" << h
                              << " texture.getSize().x=" << ani->texture.getSize().x
                              << std::endl);
}

void Character::update(float deltaTime)
{
    this->characterAnimation.update(0, deltaTime);
    this->setTextureRect(this->characterAnimation.uvRect);
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
}