#include "character.hpp"
#include <math.h>

Character::Character()
{
    this->width = CFG_CHARACTER_WIDTH;
    this->height = CFG_CHARACTER_HEIGHT;
    this->x = 0;
    this->y = 0;
    this->velocity.x = 0;
    this->velocity.y = 0;
    this->state = State::MaxState; // Dummy init
    this->faceRight = true;
    this->scale = 1.0f;
    this->ableJump = false;

    /* Add body of character */
    this->body = std::make_shared<DebugRectangle>(
        this->x, this->y, this->width, this->height, sf::Color(0, 255, 0, 100));
}

void Character::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    this->characterImg.setPosition(this->x, this->y);
    this->body->setPosition(x, y);
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

void Character::update(float deltaTime, std::vector<std::shared_ptr<GameObject>> obstructionList)
{
    this->characterAnimation.update(0, deltaTime, this->faceRight);
    this->characterImg.setTextureRect(this->characterAnimation.uvRect);

    if ((this->state != State::Idle) && (this->characterAnimation.isAnimationFinish()))
    {
        // Return the character to idle state after do any animation
        this->setState(State::Idle);
    }

    /*
        v = v0 + a*t
        s = v*t
    */
    // Smooth movements
    if (this->velocity.x > 0)
    {
        this->velocity.x -= (CFG_CHARACTER_ACCELERATION * deltaTime) / 2.0f;
    }
    else
    {
        this->velocity.x += (CFG_CHARACTER_ACCELERATION * deltaTime) / 2.0f;
    }
    this->velocity.y += CFG_GRAVITATION_ACCELERATION * deltaTime;

    if (velocity.y > CFG_GRAVITY_MAX_FALLING)
    {
        velocity.y = CFG_GRAVITY_MAX_FALLING;
    }

    // Ignore smaller 1 pixel movements
    auto deltaX = this->velocity.x * deltaTime;
    if (abs(deltaX) < 1.0f)
    {
        deltaX = 0.0f;
    }
    auto deltaY = this->velocity.y * deltaTime;
    if (abs(deltaY) < 1.0f)
    {
        deltaY = 0.0f;
    }

    // Apply pending movements
    this->x += deltaX;
    this->y += deltaY;

    // Process gravity here
    for (auto obj : obstructionList)
    {
        sf::Vector2f pushBack(0, 0);
        while (obj->AABBCollision(this->getBounds(), pushBack))
        {

            this->x += pushBack.x;
            this->y += pushBack.y;
            if (pushBack.y < 0)
            {
                this->velocity.y = 0;
                this->ableJump = true;
            }
            // DEBUG_PRINT("Collision"
            //             << " obj:" << obj->positionToString() << "\n"
            //             << " pla:" << this->positionToString() << "\n"
            //             << " x=" << this->getBounds().left
            //             << " y=" << this->getBounds().top
            //             << " w=" << this->getBounds().width
            //             << " h=" << this->getBounds().height);
        }
    }
    this->velocity.x *= 0.9f;

    this->characterImg.setPosition(this->x, this->y);
    this->body->setPosition(this->x, this->y);
    // DEBUG_PRINT(" state=" << this->state
    //                       << " x=" << x
    //                       << " y=" << y
    //                       << " v_x=" << velocity.x
    //                       << " v_y=" << velocity.y);
}

void Character::movementAct(float delta_x, float delta_y)
{
    // this->characterImg.move(delta_x, delta_y);
    if (delta_x > 0.0f)
    {
        this->faceRight = true;
    }
    else if (delta_x < 0.0f)
    {
        this->faceRight = false;
    }
    else
    {
        // Do nothing
    }
    this->velocity.x += delta_x;
    this->velocity.y += delta_y;

    if (delta_y == 0)
    {
        this->setState(State::Walk);
    }
    else
    {
        this->setState(State::Jump);
    }
}

void Character::moveLeft()
{
    // DEBUG_PRINT(this->name);
    this->faceRight = false;
    this->velocity.x -= CFG_CHARACTER_SPEED;
    // this->velocity.x -= sqrtf(2.0f * CFG_CHARACTER_ACCELERATION * 100.0f);
    this->setState(State::Walk);
};

void Character::moveRight()
{
    // DEBUG_PRINT(this->name);
    this->faceRight = true;
    this->velocity.x += CFG_CHARACTER_SPEED;
    // this->velocity.x += sqrtf(2.0f * CFG_CHARACTER_ACCELERATION * 100.0f);
    this->setState(State::Walk);
};

void Character::jump()
{
    // DEBUG_PRINT(this->name);
    if (this->ableJump)
    {
        this->velocity.y -= sqrtf(2.0f * CFG_GRAVITATION_ACCELERATION * CFG_CHARACTER_JUMP_HEIGHT);
        this->setState(State::Jump);
        this->ableJump = false;
    }
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

bool Character::setState(State s)
{
    // No update if state not change
    if (this->state == s)
    {
        return false;
    }

    switch (s)
    {
    case State::Jump:
    case State::Walk:
    case State::Attack:
        // Cannot move or attack while being hit
        if (this->state == State::Hit)
        {
            return false;
        }
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
    this->characterImg.setTexture(aniTexture[this->state].texture);
    this->characterAnimation.init(&ani->texture, sf::Vector2u(ani->frames, 1), ani->switchTime);
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
