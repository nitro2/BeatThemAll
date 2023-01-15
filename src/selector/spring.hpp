#pragma once
#ifndef SPRING_HPP
#define SPRING_HPP

class Spring
{
	public:
		// Leave the default constructor for the compiler
		Spring() = default;
		// Parameterized constructor
		Spring(float px = 0, float pk = 100, float pd = 10);
		// This function update spring acceleration, velocity and scale over time
		void update(float dt);
		// The pull function is called whenever we want to add a force to the spring to make it oscillate
		void pull(float f, float k = -1, float d = -1);
		// This function return the scale of spring
		float getScale();
	private:
		float x, k, d, targetX, v;
};

#endif // !SPRING_HPP
