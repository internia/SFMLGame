#include "Animation.h"

Animation::Animation()
{
	currentFrame = 0;
}

Animation::~Animation()
{
}

void Animation::init(int left, int top, int width, int height, int numFrames, float speed)
{
	frame.left = left;
	frame.top = top;
	frame.width = width;
	frame.height = height;
	numberOfFrames = numFrames;
	animationSpeed = speed;

	if (frame.width < 0)
	{
		flipped = true;
	}
}

sf::IntRect Animation::getCurrentFrame()
{		
	sf::IntRect temp;	
	if (flipped == false)
	{	
		// Rectangle function draws frame sets size ect.
		temp = sf::IntRect(frame.width * currentFrame, frame.top, frame.width, frame.height);
	}
	else if (flipped == true)
	{
		// -width * currentframe + 1 | Inverts frame and adds frame to make up for flip
		temp = sf::IntRect((-frame.width) * (currentFrame + 1), frame.top, frame.width, frame.height);
	}
	return temp;
}

void Animation::nextFrame()
{
	currentFrame++;
	if (currentFrame >= numberOfFrames) {

		currentFrame = 0;
	}
}
