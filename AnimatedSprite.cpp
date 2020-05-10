#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(const sf::Vector2f& size): Sprite(size)
{
	elapsedTime = 0.f;
	animationSpeed = 1.0f;
	frame = sf::IntRect(0, 0, 0, 0);
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update(float dt)
{
	//increment
	elapsedTime += dt;

	//check if time to move to next frame
	if (elapsedTime >= animationSpeed) {

		frame.left += frame.width;

		//check animation frames
		if (frame.left > getTexture()->getSize().x - frame.width) {

			frame.left = 0;
		}
		setTextureRect(frame);
		//timer reset
		elapsedTime = 0;
	}
}

void AnimatedSprite::setFrameSize(int width, int height)
{
	frame.width = width;
	frame.height = height;
	setTextureRect(frame);
}

void AnimatedSprite::setAnimationSpeed(float speed)
{
	animationSpeed = speed;
}
