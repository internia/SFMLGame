#include "Background.h"

Background::Background(const sf::Vector2f& size)
{
	bgTexture.loadFromFile("gfx/Background.png");
	setSize(sf::Vector2f(1280, 720));
	setPosition(0,0);
	setTexture(&bgTexture);
	
}

Background::~Background()
{
}

void Background::update(float dt)
{
}
