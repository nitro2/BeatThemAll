#pragma once
#ifndef  SPRING_HPP
#define SPRING_HPP

class Spring
{
	public:
		Spring();
		~Spring();
		void init(float x, float k, float d);
		void pull(float f, float k, float d);
		void update(float dt);
		float getX();
	private:
		float x, k, d, targetX, v;
};

#endif // ! SPRING_HPP
