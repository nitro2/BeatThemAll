#include "selector.hpp"

Selector::Selector(float x, float y)
{
	if (!texture.loadFromFile("./assets/UI_elements/gui_gradient_animated_selection.png"))
	{
		std::cout << "Load texture failed.\n";
	}
	image.setTexture(texture);
	image.setScale(2.f, 2.f);

	animation = std::make_shared<Animation>();
	animation->init(&texture, sf::Vector2u(4, 1), 0.1f);
	animation->setRepeat(true);

	width = 64;
	height = 64;
	this->x = x;
	this->y = y;
}

Selector::~Selector()
{

}

float Selector::getX()
{
	return x;
}

void Selector::setX(float x)
{
	this->x = x;
}

float Selector::getY()
{
	return y;
}

void Selector::setY(float y)
{
	this->y = y;
}

void Selector::update(float dt)
{
	animation->update(0, dt, false);
	image.setTextureRect(animation->uvRect);
	image.setPosition(x, y);
}

void Selector::draw(sf::RenderWindow& window)
{
	//sf::RectangleShape rect;
	//rect.setSize(sf::Vector2f(width, height));
	//rect.setPosition(x, y);
	//window.draw(rect);
	window.draw(image);
}