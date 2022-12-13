#include <iostream>
#include "animation.hpp"

Animation::Animation(std::string name)
{
	this->name = name;
	this->currentFrame = 0;
	this->frameTimer = 0;
	this->status = "playing";
}

Animation::~Animation()
{

}

void Animation::init(std::string mode)
{
	
}

void Animation::addFrame(std::tuple<int, int, int, int, float> frame)
{
	frames.push_back(frame);
}

void Animation::update(float deltaTime)
{
	if (status != "playing") return;
	frameTimer += deltaTime;
	std::cout << frameTimer << "\n";
	if (frameTimer >= std::get<4>(frames[currentFrame]))
	{
		frameTimer = 0;
		currentFrame++;
		if (currentFrame >= frames.size())
		{
			currentFrame = 0;
		}
	}
}

void Animation::pause()
{
	status = "paused";
}

void Animation::resume()
{
	status = "playing";
}

std::tuple<int, int, int, int> Animation::grid(std::tuple<int, int, int, int> gridRect, std::pair<int, int> frameCoord)
{
	int x, y;
	x = std::get<0>(gridRect) + frameCoord.first * std::get<2>(gridRect);
	y = std::get<1>(gridRect) + frameCoord.second * std::get<3>(gridRect);
	return std::make_tuple(x, y, std::get<2>(gridRect), std::get<3>(gridRect));
}

std::tuple<int, int, int, int, float> Animation::getCurrentFrameInfo() {
	return frames[currentFrame];
}