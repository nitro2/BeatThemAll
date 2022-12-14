#pragma once
#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include "SFML/Graphics.hpp"
#include "utils.hpp"
class Animation
{
public:
	Animation();
	~Animation();
	void init(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	void update(int row, float deltaTime, bool faceRight);
	void setRepeat(bool isRepeat);

	bool isAnimationFinish();
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
	bool isFinish;
	bool isRepeat; // Set true if repeatedly display the image (eg: Idle)
};

#endif // !_ANIMATION_HPP_
