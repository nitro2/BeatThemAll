#include "character.hpp"
#include <math.h>

Character::Character() : GameObject(0, 0, CFG_CHARACTER_WIDTH, CFG_CHARACTER_HEIGHT)
{
    this->state = State::Init; // Dummy init
    this->faceRight = true;
    this->scale = 1.0f;
}

void Character::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    this->characterImg.setPosition(this->x, this->y);
}

sf::FloatRect Character::getBounds()
{
    return sf::FloatRect(this->x - (this->width / 2.0f), this->y - this->height, this->width, this->height);
}

bool Character::isFaceRight()
{
    return this->faceRight;
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
    this->characterImg.setTextureRect(this->characterAnimation.uvRect);
    this->characterImg.setPosition(this->x, this->y);
    if ((this->state != State::Idle) && (this->characterAnimation.isAnimationFinish()))
    {
        if (this->state == State::Dead)
        {
            this->setState(State::End);
            return;
        }
        else
        {
            // Return the character to idle state after do any animation
            this->setState(State::Idle);
        }
    }
}

void Character::moveLeft()
{
    // DEBUG_PRINT(this->name);
    this->faceRight = false;
    this->setState(State::Walk);
};

void Character::moveRight()
{
    // DEBUG_PRINT(this->name);
    this->faceRight = true;
    this->setState(State::Walk);
};

void Character::jump()
{
    // DEBUG_PRINT(this->name);
    this->setState(State::Jump);
}

void Character::attackAct()
{
    this->setState(State::Attack);
}

void Character::render(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->characterImg);
    // TODO: Comment this to not show debug body rectangle
    // this->body->render(window);
}

bool Character::setState(State newState)
{
    // No update if state not change
    if (this->state == newState)
    {
        return false;
    }

    switch (this->state)
    {
    case State::Hit:
        // Cannot jump, move or attack while being hit
        if ((newState == State::Jump) || (newState == State::Walk) || (newState == State::Attack))
        {
            return false;
        }
    case State::Dead:
        // Do not allow user to change state if already dead
        if (newState < State::MaxImageStates)
        {
            return false;
        }
    case State::Jump:
    case State::Walk:
    case State::Attack:
    case State::Idle:
    default:
        break;
    }
    this->state = newState;
    bool isRepeat = (newState == State::Idle) ? true : false;

    // Change image with to animation if needed
    AnimationTexture_t *ani = &aniTexture[newState];
    this->characterImg.setTexture(aniTexture[this->state].texture);
    this->characterAnimation.init(&ani->texture, sf::Vector2u(ani->frames, 1), ani->switchTime);
    this->characterAnimation.setRepeat(isRepeat);
    this->characterImg.setTextureRect(sf::IntRect(0, 0, ani->imgWidth, ani->imgHeight));
    // In case the image is smaller than expected rectangle, we have to scale it up
    this->characterImg.setScale(this->scale, this->scale);
    // Set origin of image to bottom left corner, so we will have smoothly transition between Idle and Attack
    this->characterImg.setOrigin(static_cast<float>(this->aniTexture[this->state].imgWidth / 2), static_cast<float>(this->aniTexture[this->state].imgHeight));
    this->characterAnimation.update(0, 0.0f, this->faceRight);
    this->characterImg.setTextureRect(this->characterAnimation.uvRect);
    DEBUG_PRINT(" state=" << this->state
                          << " x=" << x
                          << " y=" << y);
    return true;
}

Character::State Character::getState()
{
    return this->state;
}
