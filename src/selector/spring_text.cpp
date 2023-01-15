#include "spring_text.hpp"

SpringText::SpringText(std::string text, float x, float y) 
	: content{text}, mTransform { x, y }, mSpring{ 1 }, hot{ false }, localX {0}, localY {0}, elapsedTime { 0 }, radAngle { 0 }
{
	loadFont();
	textInit();
	sizeInit();
}

void SpringText::loadFont()
{
	// Load minecraft font
	if (!font.loadFromFile("./assets/fonts/minecraft.ttf"))
	{
		std::cout << "Load font failed.\n";
	}
}

void SpringText::textInit()
{
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(48);
	text.setFillColor(sf::Color::Black);
}

void SpringText::sizeInit()
{
	// Get the local bounding rectangle of the entity.
	// The returned rectangle is in local coordinates, 
	// which means that it ignores the transformations(translation, rotation, scale, ...) that are applied to the entity.
	// In other words, this function returns the bounds of the entity in the entity's coordinate system.
	sf::FloatRect localBound = text.getLocalBounds();
	localX = localBound.left;
	localY = localBound.top;
	// Assign value for width, height
	mTransform.setWidth(localBound.width);
	mTransform.setHeight(localBound.height);
}

void SpringText::transformText()
{
	text.setPosition(mTransform.getCenterX(), mTransform.getCenterY());
	text.setRotation(radAngle / PI * 180);
	text.setScale(mSpring.getScale(), mSpring.getScale());
	text.setOrigin(mTransform.getWidth() / 2, mTransform.getHeight() / 2);
}

void SpringText::selfCentering(float posX, float posY)
{
	mTransform.selfCenteringX(posX);
	mTransform.selfCenteringY(posY);
}

void SpringText::drawDebugRect(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(mTransform.getWidth(), mTransform.getHeight()));
	rect.setPosition(sf::Vector2f(mTransform.getX() + localX, mTransform.getY() + localY));
	rect.setFillColor(sf::Color::White);
	window.draw(rect);
}

void SpringText::update(float dt, sf::Vector2i& mousePos)
{
	// Update text position, rotation, scale,...
	transformText();
	// Update the spring
	mSpring.update(dt);
	
	// If mouse touch the spring text, pull the spring
	if (pointInRect(mousePos.x, mousePos.y, mTransform.getX() + localX, mTransform.getY() + localY, mTransform.getWidth(), mTransform.getHeight()))
	{
		if (!hot)
		{
			hot = true;
			mSpring.pull(0.25);
		}
	} else
	{
		hot = false;
	}

	// Pull the spring if player click on the text
	if (hot && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mSpring.pull(0.25);
	}

	// Wobbling the spring text from left to right 
	elapsedTime += dt;
	// 2*PI is the cycle of sine function
	if (elapsedTime >= 2 * PI)
	{
		elapsedTime = 0;
	}
	
	// sinValue is from -1 to 1
	float sinValue = std::sin(elapsedTime);
	// largest rotation angle is 15 
	radAngle = PI / 24 * sinValue;
}

void SpringText::draw(sf::RenderWindow& window)
{
	//drawDebugRect(window);
	window.draw(text);
}