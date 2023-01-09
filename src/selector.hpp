#pragma once
#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <iostream>
#include "SFML/Graphics.hpp"
#include "animation.hpp"

class Selector
{
	public:
		Selector(float x, float y);
		~Selector();

		void update(float dt);
		void draw(sf::RenderWindow &window);

		float getX();
		void setX(float x);
		float getY();
		void setY(float x);

	private:
		sf::Sprite image;
		sf::Texture texture;
		std::shared_ptr<Animation> animation;
		float x, y, width, height;
};

#endif // !SELECTOR_HPP
