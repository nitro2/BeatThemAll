#pragma once
#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#define DEFAULT_SCALE 2

#include <iostream>
#include "transform.hpp"
#include "SFML/Graphics.hpp"
#include "utils.hpp"
#include "spring.hpp"

class Selector
{
public:
	Selector() = default;
	Selector(float x, float y, float width, float height);
	~Selector();

	void update(float dt);
	void draw(sf::RenderWindow& window);

	float getX(), getY();
	void setX(float x), setY(float y), pullSpring(float force);
private:
	Transform mTransform;
	sf::Texture texture;
	sf::Sprite sprite;
	Spring mSpring;
	float arrowX, arrowY, sineCycle;

	void spriteInit();
};

#endif // !SELECTOR_HPP
