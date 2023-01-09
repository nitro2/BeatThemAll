#include "spring_text.hpp"

SpringText::SpringText(float x, float y)
{
	if (!font.loadFromFile("./assets/fonts/minecraft.ttf"))
	{
		std::cout << "Load font failed.\n";
	}
	text.setFont(font);
	text.setString("Choose your cool hero!!!");
	text.setFillColor(sf::Color::Black);
	this->x = x;
	this->y = y;

	sf::FloatRect rect = text.getLocalBounds();
	width = rect.width;
	height = rect.height;
	localX = rect.left;
	localY = rect.top;
	spring = std::make_shared<Spring>();

	hot = false;
	elapsedTime = 0.0f;
	radAngle = 0.0f;
}

SpringText::~SpringText()
{

}

void SpringText::update(float dt, sf::RenderWindow& window)
{
	spring->update(dt);
	sf::Vector2i position = sf::Mouse::getPosition(window);
	if (pointInRect(position.x, position.y, x + localX, y + localY, width, height))
	{
		if (!hot)
		{
			hot = true;
			spring->pull(0.25f, -1, -1);
		}
	}
	else
	{
		hot = false;
	}

	if (hot && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		spring->pull(0.25f, -1, -1);
	}

	elapsedTime += dt;

	if (elapsedTime >= 2*PI)
	{
		elapsedTime = 0;
	}

	float sinValue = std::sin(elapsedTime);
	radAngle = PI / 24 * sinValue;

	text.setPosition(x, y);
	text.setOrigin(width / 2, height / 2);
	text.setScale(spring->getX(), spring->getX());
	text.setPosition(x + width / 2, y + height / 2);
	text.setRotation(radAngle/PI*180);
}

void SpringText::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(width, height));
	rect.setPosition(x+localX, y+localY);
	
	//window.draw(rect);
	window.draw(text);
}