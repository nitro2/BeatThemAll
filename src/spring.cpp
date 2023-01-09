#include "spring.hpp"

Spring::Spring()
{
	x = 0;
	k = 100;
	d = 10;
	targetX = 1;
	v = 0;
}

Spring::~Spring()
{

}

void Spring::init(float x, float k, float d)
{
	this->x = x;
	this->k = k;
	this->d = d;
	this->targetX = x;
}

void Spring::pull(float f, float k, float d)
{
	if (k != -1)
	{
		this->k = k;
	}
	if (d != -1)
	{
		this->d = d;
	}
	this->x += f;
}

void Spring::update(float dt)
{
	float a = -k * (x - targetX) - d * v;
	v += a * dt;
	x += v * dt;
}

float Spring::getX()
{
	return x;
}