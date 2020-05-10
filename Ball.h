#pragma once
#include "Sprite.h"
#include "Vector.h"

class Ball : public Sprite {

public:
	Ball();
	~Ball();

	void update(float dt);
	virtual void collisionResponse();
	//void setInput(Input* newInp);


private:

	bool moving;
	float speed;
	float acceleration;
	float gravity;
	sf::Vector2f target;
	sf::Vector2f direction;
	sf::Texture texture;
	//Input* input;

	/*bool falling;
	float scale;
	float gravity;
	sf::Texture texture;
	Input* input;*/
};