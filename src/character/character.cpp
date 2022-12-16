#include "character.hpp"

Character::Character()
{
    this->width = CFG_CHARACTER_WIDTH;
    this->height = CFG_CHARACTER_HEIGHT;
    this->x = 0;
    this->y = 0;
    this->state = State::Idle;
    this->faceRight = true;
    this->scale = 1.0f;
}

void Character::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
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

void Character::movementAct(float delta_x, float delta_y)
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
    this->x += delta_x;
    this->y += delta_y;
    if (this->state != State::Walk)
    {
    this->setState(State::Walk);
    }
    DEBUG_PRINT("x=" << x << " y=" << y);
}

void Character::attackAct()
{
    this->setState(State::Attack);
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
    this->body.setScale(this->scale, this->scale);
    this->update(0.0f);
}