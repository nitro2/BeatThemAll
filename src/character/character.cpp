#include "character.hpp"

Character::Character()
{
    this->width = CFG_CHARACTER_WIDTH;
    this->height = CFG_CHARACTER_HEIGHT;
    this->x = 0;
    this->y = 0;
    this->state = State::MaxState; // Dummy init
    this->faceRight = true;
    this->scale = 1.0f;

    /* Add debug shape */
    this->debugShape = std::make_shared<DebugRectangle>(
        this->x, this->y, this->width, this->height, sf::Color(255, 0, 0, 100));
}

void Character::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    this->body.setPosition(this->x, this->y);
    this->debugShape->setPosition(x, y);
}

sf::FloatRect Character::getBounds()
{
    return sf::FloatRect(this->x - (this->width / 2.0f), this->y - this->height, this->width, this->height);
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
    this->body.setTextureRect(this->characterAnimation.uvRect);

    if ((this->state != State::Idle) && (this->characterAnimation.isAnimationFinish()))
    {
        // Return the character to idle state after do any animation
        this->setState(State::Idle);
    }

    // Process gravity here
    this->y += CFG_GRAVITY_SPEED;
    for (auto obj : obstructionList)
    {
        if (this->getBounds().intersects(obj->getBounds()))
        {
            this->y -= CFG_GRAVITY_SPEED;
        }
    }

    this->body.setPosition(this->x, this->y);
    this->debugShape->setPosition(this->x, this->y);
}

void Character::movementAct(float delta_x, float delta_y)
{
    // this->body.move(delta_x, delta_y);
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
    this->setState(State::Walk);
}

void Character::attackAct()
{
    this->setState(State::Attack);
}

void Character::render(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->body);
    this->debugShape->render(window);
}

void Character::setState(State s)
{
    // No update if state not change
    if (this->state == s)
    {
        return;
    }

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
    // Set origin of image to bottom left corner, so we will have smoothly transition between Idle and Attack
    this->body.setOrigin((float)(this->aniTexture[this->state].imgWidth / 2), (float)this->aniTexture[this->state].imgHeight);
    this->characterAnimation.update(0, 0.0f, this->faceRight);
    this->body.setTextureRect(this->characterAnimation.uvRect);
    DEBUG_PRINT(" state=" << this->state
                          << " x=" << x
                          << " y=" << y);
}