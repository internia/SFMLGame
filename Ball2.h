#pragma once
#include"Sprite.h"
#include "Input.h"

class Ball2 : public Sprite {
public:
	Ball2();
	~Ball2();

	void update(float dt);
	virtual void collisionResponse();
	void setInput(Input* newInp);

private:
	bool moving;
	float speed;
	float acceleration;
	float gravity;
	sf::Vector2f target;
	sf::Vector2f direction;
	sf::Texture texture2;
	Input* input;
};