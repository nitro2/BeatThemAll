#include "character.hpp"
#include <math.h>

Character::Character() : GameObject(0, 0, CFG_CHARACTER_WIDTH, CFG_CHARACTER_HEIGHT)
{
    this->state = ImageState::MaxImageStates; // Dummy init
    this->faceRight = true;
    this->scale = 1.0f;
    this->dead = false;
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

void Character::loadImage(ImageState state, std::string filename, int frames, float switchTime)
{
    AnimationTexture_t *ani = &aniTexture[state];
    ani->frames = frames;
    ani->texture.loadFromFile(resourcePath() + filename);
    ani->imgWidth = ani->texture.getSize().x / ani->frames;
    ani->imgHeight = ani->texture.getSize().y;
}

void Character::update(float deltaTime)
{
    if (this->dead)
    {
        return;
    }

    if ((this->state != ImageState::Idle) && (this->characterAnimation.isAnimationFinish()))
    {
        if (this->state == ImageState::Dead)
        {
            this->dead = true;
        }
        else
        {
            // Return the character to idle state after do any animation
            this->setState(ImageState::Idle);
        }
    }
    this->characterAnimation.update(0, deltaTime, this->faceRight);
    this->characterImg.setTextureRect(this->characterAnimation.uvRect);
    this->characterImg.setPosition(this->x, this->y);
}

void Character::moveLeft()
{
    // DEBUG_PRINT(this->name);
    this->faceRight = false;
    this->setState(ImageState::Walk);
};

void Character::moveRight()
{
    // DEBUG_PRINT(this->name);
    this->faceRight = true;
    this->setState(ImageState::Walk);
};

void Character::jump()
{
    // DEBUG_PRINT(this->name);
    this->setState(ImageState::Jump);
}

void Character::attackAct()
{
    this->setState(ImageState::Attack);
}

void Character::render(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->characterImg);
    // TODO: Comment this to not show debug body rectangle
    // this->body->render(window);
}

bool Character::setState(ImageState newState)
{
    // No update if state not change
    if (this->state == newState)
    {
        return false;
    }

    switch (this->state)
    {
    case ImageState::Hit:
        // Cannot jump, move or attack while being hit
        if ((newState == ImageState::Jump) || (newState == ImageState::Walk) || (newState == ImageState::Attack))
        {
            return false;
        }
    case ImageState::Dead:
    case ImageState::Jump:
    case ImageState::Walk:
    case ImageState::Attack:
    case ImageState::Idle:
    default:
        break;
    }
    this->state = newState;
    bool isRepeat = (newState == ImageState::Idle) ? true : false;

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

Character::ImageState Character::getState()
{
    return this->state;
}

bool Character::isDead()
{
    return this->dead;
}
