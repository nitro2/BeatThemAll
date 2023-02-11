#include "character_preview.hpp"

CharacterPreview::CharacterPreview(float x, float y, float width, float height) : mTransform{ x, y, width, height }
{

}

CharacterPreview::~CharacterPreview()
{

}

void CharacterPreview::update(float dt)
{

}

void CharacterPreview::draw(sf::RenderWindow& window)
{
	drawDebugRectangle(mTransform, window, sf::Color(255, 255, 255));
}