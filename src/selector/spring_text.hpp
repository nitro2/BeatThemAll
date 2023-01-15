#pragma once
#ifndef SPRING_TEXT_HPP
#define SPRING_TEXT_HPP

#include <string>
#include <iostream>
#include "transform.hpp"
#include "spring.hpp"
#include "collision_detection.hpp"
#include "utils.hpp"
#include "SFML/Graphics.hpp"

class SpringText
{ 
	public:
		// Leave the default constructor for the compile :)
		SpringText() = default;
		// Parameterized constructor
		SpringText(std::string text, float x, float y);


		// This function help spring text center itselt to a specific position
		void selfCentering(float posX, float posY);
		// This function update the spring text
		void update(float dt, sf::Vector2i& mousePos);
		// This function draw the spring text
		void draw(sf::RenderWindow& window);

	private:
		Transform mTransform;
		Spring mSpring;
		sf::Font font;
		sf::Text text;
		std::string content;

		bool hot;
		float localX, localY, elapsedTime, radAngle;

		// This funciton used to load font for the text
		void loadFont();
		// This function initialize the text
		void textInit();
		// This function get the size(width, height) of spring text arcording to the content,
		// we get a rectangle wrap the content
		void sizeInit();
		// This function update the text's position, rotation, scale,...
		void transformText();

		// This function is used to draw debug rectangle
		void drawDebugRect(sf::RenderWindow& window);
};

#endif // !SPRING_TEXT_HPP
