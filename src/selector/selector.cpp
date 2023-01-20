#include "selector.hpp"

Selector::Selector(float x, float y, float width, float height) 
	: mTransform {x, y, width, height}, arrowX{ -10 }, arrowY{ -10 }, sineCycle { 0 }, mSpring{ 1 }
{
	spriteInit();
}

Selector::~Selector()
{

}

void Selector::spriteInit()
{
	// load arrow texture
	if (!texture.loadFromFile("./assets/UI_elements/arrow.png"))
	{
		std::cout << "Load arrow texture failed.\n";
	}
	else
	{
		sprite.setTexture(texture);
	}
	sprite.setTextureRect(sf::IntRect(0, 0, 13, 13));
	sf::Vector2u textureSize = sprite.getTexture()->getSize();
	float textureWidth{(float) textureSize.x};
	float textureHeight{(float) textureSize.y};
	sprite.setOrigin(sf::Vector2f(textureWidth / 2, textureHeight / 2));
	float adjustY{  sprite.getTexture()->getSize().y * sprite.getScale().y};
	sprite.setPosition(mTransform.getX() + arrowX, mTransform.getY() + arrowY - adjustY);
}

void Selector::pullSpring(float force)
{
	mSpring.pull(force);
}

void Selector::update(float dt)
{
	sineCycle += 3 * dt;
	if (sineCycle >= 2 * PI)
	{
		sineCycle = 0;
	}
	float sinValue = std::sin(sineCycle);
	sf::Vector2u textureSize = sprite.getTexture()->getSize();
	sf::Vector2f spriteScale = sprite.getScale();
	float adjustY{ textureSize.y * spriteScale.y };
	sprite.setPosition(mTransform.getX() + arrowX + textureSize.x * spriteScale.x / 2, mTransform.getY() + textureSize.y * spriteScale.y / 2 + arrowY + sinValue * 10 - adjustY);
	mSpring.update(dt);
	float springScale = mSpring.getScale();
	sprite.setScale(springScale*DEFAULT_SCALE, springScale*DEFAULT_SCALE);
	
}

void Selector::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(mTransform.getX(), mTransform.getY()));
	rect.setSize(sf::Vector2f(mTransform.getWidth(), mTransform.getHeight()));
	rect.setOutlineColor(sf::Color(38, 122, 233, 255));
	rect.setOutlineThickness(4);
	rect.setFillColor(sf::Color(0, 0, 0, 0));
	window.draw(rect);
	window.draw(sprite);
}

float Selector::getX()
{
	return mTransform.getX();
}

float Selector::getY()
{
	return mTransform.getY();
}

void Selector::setX(float x)
{
	mTransform.setX(x);
}

void Selector::setY(float y)
{
	mTransform.setY(y);
}