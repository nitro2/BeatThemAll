#include "transform.hpp"

Transform::Transform(float x, float y, float width, float height) : mX{ x }, mY{ y }, mWidth{ width }, mHeight{ height }
{

}

float Transform::getX()
{
	return mX;
}

float Transform::getY()
{
	return mY;
}

float Transform::getWidth()
{
	return mWidth;
}

float Transform::getHeight()
{
	return mHeight;
}

float Transform::getCenterX()
{
	return mX + mWidth / 2;
}

float Transform::getCenterY()
{
	return mY + mHeight / 2;
}

void Transform::setX(float x)
{
	mX = x;
}

void Transform::setY(float y)
{
	mY = y;
}

void Transform::setWidth(float width)
{
	mWidth = width;
}

void Transform::setHeight(float height)
{
	mHeight = height;
}

void Transform::selfCenteringX(float xPos)
{
	mX = xPos - mWidth / 2;
}

void Transform::selfCenteringY(float yPos)
{
	mY = yPos - mHeight / 2;
}