#pragma once
#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include "SFML/Graphics.hpp"

struct grid {
	int startX, startY, cellWidth, cellHeight;
};

class Animation
{
public:
	Animation();
	~Animation();
	void init(sf::Texture *texture, std::vector<std::pair<grid, std::string>> animate, std::string mode);
	void update(float deltaTime);
private:
	sf::Vector2u currentImage;
	float frameTimer;
};

#endif // !_ANIMATION_HPP_
