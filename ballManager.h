#pragma once
#include "ball.h"
#include <math.h>
#include <vector>

class ballManager {

public:
	ballManager();
	~ballManager();

	void spawn();
	void update(float dt);
	void checkIfDead();
	void render(sf::RenderWindow* window);

private:
	std::vector<Ball> ball;
	sf::Vector2f spawnLocation;
	sf::Texture texture; 

};