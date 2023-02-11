#pragma once
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

class Transform
{
public:
	// leave the default constructor for the compiler :)
	Transform() = default;
	// parameterized constructor
	Transform(float x = 0, float y = 0, float width = 0, float height = 0);
	// destructor
	~Transform();
	// getter and setter
	float getX(), getY(), getWidth(), getHeight(), getCenterX(), getCenterY();
	void setX(float x), setY(float y), setWidth(float width), setHeight(float height);
	// This function is used to help the object center itself
	void selfCenteringX(float xPos), selfCenteringY(float yPos);
private:
	float mX, mY, mWidth, mHeight;
};

#endif // !TRANSFORM_HPP
