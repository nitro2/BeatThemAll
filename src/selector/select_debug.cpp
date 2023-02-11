#include "select_debug.hpp"

void drawDebugRectangle(Transform& mTransform, sf::RenderWindow& window, sf::Color& color)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(mTransform.getWidth(), mTransform.getHeight()));
	rect.setPosition(sf::Vector2f(mTransform.getX(), mTransform.getY()));
	rect.setFillColor(color);
	window.draw(rect);
}