#include "character.hpp"

Character::Character()
{
    this->width = CFG_CHARACTER_WIDTH;
    this->height = CFG_CHARACTER_HEIGHT;
    this->x = 100;
    this->y = 100;
    this->state = State::Idle;
    this->faceRight = true;
    this->body.setPosition(sf::Vector2f(this->x, this->y));
}

void Character::loadImage(State state, std::string filename, int frames, float switchTime)
{
    AnimationTexture_t *ani = &aniTexture[state];
    ani->frames = frames;
    ani->texture.loadFromFile(filename);
    ani->imgWidth = ani->texture.getSize().x / ani->frames;
    ani->imgHeight = ani->texture.getSize().y;
}

void Character::update(float deltaTime)
{
    this->characterAnimation.update(0, deltaTime, this->faceRight);
    this->body.setTextureRect(this->characterAnimation.uvRect);
    if ((this->state != State::Idle) && (this->characterAnimation.isAnimationFinish()))
    {
        // Return the character to idle state after do any animation
        this->setState(State::Idle);
    }
}

void Character::movement(float delta_x, float delta_y)
{
    this->body.move(delta_x, delta_y);
    if (delta_x > 0.0f)
    {
        this->faceRight = true;
    }
    else
    {
        this->faceRight = false;
    }
    this->setState(State::Walk);
}

void Character::render(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->body);
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

    // Change image with to animation if needed
    AnimationTexture_t *ani = &aniTexture[s];
    this->body.setTexture(aniTexture[this->state].texture);
    this->characterAnimation.init(&ani->texture, sf::Vector2u(ani->frames, 1), ani->switchTime);
    this->body.setTextureRect(sf::IntRect(0, 0, ani->imgWidth, ani->imgHeight));
    // In case the image is smaller than expected rectangle, we have to scale it up
    this->body.setScale(this->width / ani->imgWidth, this->height / ani->imgHeight);
    this->update(0.0f);
}