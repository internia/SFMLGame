#include "ballManager.h"

ballManager::ballManager() {

	spawnLocation = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/sparkle.gif");

	for (int i = 0; i < 20; i++) {

		ball.push_back(Ball());
		ball[i].setAliveStatus(false);
		ball[i].setTexture(&texture);
		ball[i].setSize(sf::Vector2f(100, 100));
	}

}

ballManager::~ballManager()
{
}


void ballManager::update(float dt)
{
	//call update on all ALIVE
	for (int i = 0; i < ball.size(); i++) {
		if (ball[i].isAlive()) {

				ball[i].update(dt);
		}
	}
	checkIfDead();
}

//spawn new ball
void ballManager::spawn()
{
	for (int i = 0; i < ball.size(); i++) {

		if (!ball[i].isAlive()) {
			ball[i].setAliveStatus(true);
			ball[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			ball[i].setPosition(spawnLocation);
			return;
		}
	}
}

//check for dead balls
void ballManager::checkIfDead()
{
	for (int i = 0; i < ball.size(); i++) {

		if (ball[i].isAlive()) {

			if (ball[i].getPosition().x < -100) {
				
				ball[i].setAliveStatus(false);
			}
			if (ball[i].getPosition().x > 800) {

				ball[i].setAliveStatus(false);
			}
			if (ball[i].getPosition().y < -100) {

				ball[i].setAliveStatus(false);
			}
			if (ball[i].getPosition().y > 600) {

				ball[i].setAliveStatus(false);
			}
		}
	}
}

//render all alive
void ballManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < ball.size(); i++) {

		if (ball[i].isAlive()) {

			window->draw(ball[i]);
		}
	}
}
