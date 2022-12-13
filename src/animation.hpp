#pragma once
#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <tuple>
#include "SFML/Graphics.hpp"

class Animation
{
public:
	Animation(std::string name, float scale, float originX, float originY);
	~Animation();
	void init(std::string mode);
	void addFrame(std::tuple<int, int, int, int, float> frame);
	void update(float deltaTime);
	void pause();
	void resume();
	float getScale();
	void setAnimOrigin(float oX, float oY);
	std::pair<float, float> getAnimOrigin();
	std::tuple<int ,int, int, int, float> getCurrentFrameInfo();
	std::tuple<int, int, int, int> grid(std::tuple<int, int, int, int> gridRect, std::pair<int, int> frameCoord);
private:
	float frameTimer, scale;
	std::string status, name;
	std::vector <std::tuple<int, int, int, int, float>> frames;
	int currentFrame, originX, originY;
};

#endif // !_ANIMATION_HPP_
