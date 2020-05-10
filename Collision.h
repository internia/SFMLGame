#pragma once
#include <SFML\Graphics.hpp>;

class Collision {

public:
	Collision(sf::RectangleShape& body);
	~Collision();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool checkCollision(Collision& other, float push);
	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getHalf() { return body.getSize() / 2.0f;  }

private:
	sf::RectangleShape& body;
};
