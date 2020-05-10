#include "Collision.h"

Collision::Collision(sf::RectangleShape& body) :
	body(body)
{
	
}

Collision::~Collision()
{
}

bool Collision::checkCollision(Collision& other, float push)
{

	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherhalf = other.getHalf();

	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisSize = getHalf();

	float dx = otherPosition.x - thisPosition.x;
	float dy = otherPosition.y - thisPosition.y;

	float intersectX = abs(dx) - (otherhalf.x + thisSize.x);
	float intersectY = abs(dy) - (otherhalf.y + thisSize.y);

	if(intersectX < 0.0f && intersectY < 0.0f){
	
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {

			if (dx > 0.0f) {

				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
		}
		else {
			if (dy > 0.0f) {

				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
		}
		
		return true;
	
	}
	return false;
}
