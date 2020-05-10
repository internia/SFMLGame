#pragma once
#include "SFML/Graphics.hpp"

class Animation {

public:
	Animation();
	~Animation();

	void init(int left, int top, int width, int height, int frame, float speed);

	sf::IntRect getCurrentFrame();
	float getAnimationTime() { return animationSpeed; };
	void nextFrame();

protected:
	sf::IntRect frame;
	int numberOfFrames;
	int currentFrame;
	float animationSpeed;
	bool flipped;
};