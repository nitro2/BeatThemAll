#include "spring.hpp"

// uniform intialization
Spring::Spring(float px, float pk, float pd) : x{ px }, k{ pk }, d{ pd }, targetX{ px }, v{ 0 }
{

}

Spring::~Spring()
{

}

void Spring::update(float dt)
{
	// a: accleration
	// k: stiffness 
	// the higher stiffness the more aggressively the spring will go back to its initial value
	// d: dampening
	// the lower the dampening the longer the spring will oscillate for
	// v: velocity
	// x: spring scale
	float a = -k * (x - targetX) - d * v;
	v += a * dt;
	x += v * dt;
}

void Spring::pull(float f, float k, float d)
{
	if (k != -1) this->k = k;
	if (d != -1) this->d = d;
	x += f;
}

float Spring::getScale()
{
	return x;
}