#include "Ball.h"

Ball::Ball() : Sprite() {

	texture.loadFromFile("gfx/redball.png");
	setTexture(&texture);
	setSize(sf::Vector2f(48, 48));
	
	speed = 50.f;
	acceleration = 20.f;
	target = sf::Vector2f(150, 50);
	moving = true;


	/*scale = 200.f;
	gravity = 2.0f * scale;
	falling = true;*/
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0) {

		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > 350)
	{
		setPosition(350, getPosition().y);
		velocity.x = -velocity.x;
	}
}

void Ball::collisionResponse()
{

	velocity.x = -velocity.x;

}
