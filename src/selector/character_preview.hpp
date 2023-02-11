#pragma once
#ifndef CHARACTER_PREVIEW_HPP
#define CHARACTER_PREVIEW_HPP

#include "transform.hpp"
#include "SFML/Graphics.hpp"
#include "select_debug.hpp"

class CharacterPreview
{
public:
	// leave the default constructor for the compiler
	CharacterPreview() = default;
	// paramerterized constructor
	CharacterPreview(float x = 0, float y = 0, float width = 0, float height = 0);
	// destructor
	~CharacterPreview();

	void update(float dt);
	void draw(sf::RenderWindow& window);

private:
	Transform mTransform;
};

#endif // !CHARACTER_PREVIEW_HPP
