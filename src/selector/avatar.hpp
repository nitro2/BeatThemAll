#pragma once
#ifndef AVATAR_HPP
#define AVATAR_HPP

#include <iostream>
#include "transform.hpp"
#include "select_debug.hpp"
#include "SFML/Graphics.hpp"

class Avatar
{
	public:
		// leave the default constructor for the compiler
		Avatar() = default;
		// parameterized constructor
		Avatar(float x, float y);
		// this constructor crop the sprite and load it to avatar texture
		Avatar(float x, float y, std::string path, sf::IntRect cropRect);
		// destructor
		~Avatar();

		// This function handle avatar logic
		void update(float dt);
		// This function draw the avatar
		void draw(sf::RenderWindow& window);

		float getX(), getY();
		void setX(float x), setY(float y);
	private:
		Transform mTransform;
		sf::Texture frameTexture, avatarTexture;
		sf::Sprite frameSprite, avatarSprite;

		// This function load texture for the avatar
		void loadFrameTexture();
		// This function config the frame sprite (texture, texture rect,...)
		void frameSpriteConfig();
		// This function load hero face texture for the avatar
		void loadAvatarTexture(std::string& path);
		void avatarSpriteConfig(sf::IntRect& cropRect);

		float textureScale;
};

#endif // !AVATAR_HPP
