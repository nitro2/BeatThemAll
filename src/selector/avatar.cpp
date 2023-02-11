#include "avatar.hpp"

Avatar::Avatar(float x, float y) : mTransform{x, y}, textureScale{ 2.0f }
{
	loadFrameTexture();
	frameSpriteConfig();
}

Avatar::Avatar(float x, float y, std::string path, sf::IntRect cropRect) : mTransform {x, y}, textureScale{ 2.0f }
{
	loadFrameTexture();
	frameSpriteConfig();
	loadAvatarTexture(path);
	avatarSpriteConfig(cropRect);
}

Avatar::~Avatar()
{

}

void Avatar::loadAvatarTexture(std::string& path)
{
	if (!avatarTexture.loadFromFile(path))
	{
		std::cout << "Load avatar texture fail.\n";
	}
}

void Avatar::avatarSpriteConfig(sf::IntRect& cropRect)
{
	avatarSprite.setTexture(avatarTexture);
	avatarSprite.setTextureRect(cropRect);
	avatarSprite.setPosition(mTransform.getX(), mTransform.getY());
	sf::IntRect textureRect = avatarSprite.getTextureRect();
	float scale = mTransform.getWidth() / textureRect.width;
	avatarSprite.setScale(scale, scale);
}

void Avatar::loadFrameTexture()
{
	if (!frameTexture.loadFromFile("./assets/UI_elements/faceset-box.png"))
	{
		std::cout << "Load faceset-box texture fail.\n";
	}
}

void Avatar::frameSpriteConfig()
{
	frameSprite.setTexture(frameTexture);
	mTransform.setWidth(frameTexture.getSize().x*textureScale);
	mTransform.setHeight(frameTexture.getSize().y*textureScale);
	frameSprite.setPosition(sf::Vector2f(mTransform.getX(), mTransform.getY()));
	frameSprite.setScale(sf::Vector2f(textureScale, textureScale));
}

void Avatar::update(float dt)
{
	avatarSprite.setPosition(mTransform.getX(), mTransform.getY());
	frameSprite.setPosition(sf::Vector2f(mTransform.getX(), mTransform.getY()));
}

void Avatar::draw(sf::RenderWindow& window)
{
	drawDebugRectangle(mTransform, window, sf::Color(0, 0, 0, 255));
	window.draw(avatarSprite);
	window.draw(frameSprite);
	
	
}

float Avatar::getX()
{
	return mTransform.getX();
}

float Avatar::getY()
{
	return mTransform.getY();
}

void Avatar::setX(float x)
{
	mTransform.setX(x);
}

void Avatar::setY(float y)
{
	mTransform.setY(y);
}