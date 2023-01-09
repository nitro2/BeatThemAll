#pragma once
#ifndef SPRING_TEXT_HPP
#define SPRING_TEXT_HPP

#include <iostream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "spring.hpp"
#include "collision_detection.hpp"
#include "utils.hpp"

class SpringText
{
	public:
		SpringText(float x, float y);
		~SpringText();

		void update(float dt, sf::RenderWindow& window);
		void draw(sf::RenderWindow& window);

	private:
		sf::Text text;
		sf::Font font;
		float x, y, localX, localY, width, height, elapsedTime, radAngle;
		std::shared_ptr<Spring> spring;
		bool hot;
};

#endif