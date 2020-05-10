#include "Ball2.h"
#include "Vector.h"

Ball2::Ball2() : Sprite()
{
	texture2.loadFromFile("gfx/greenball.png");
	setTexture(&texture2);
	setSize(sf::Vector2f(48, 48));

	speed = 50.f;
	acceleration = 20.f;
	target = sf::Vector2f(150, 50);
	moving = true;
}

Ball2::~Ball2()
{
}

void Ball2::update(float dt)
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
	/*if (moving) {
		direction = target - getPosition();
		direction = Vector::normalise(direction);
		velocity = (direction * speed);
		move(velocity * dt);
	}
	*/
	//if (Vector::magnitude(target - getPosition()) < 10.f) {

	//	moving = false;
	//	setPosition(target);
	//}
}

void Ball2::collisionResponse()
{

	velocity.x = -velocity.x;

}

void Ball2::setInput(Input* newInp)
{
}
