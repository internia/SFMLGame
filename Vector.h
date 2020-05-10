#pragma once
#include "SFML\System\Vector2.hpp"
#include <math.h>

class Vector {

public:
	//Normalise vectors
	static sf::Vector2f normalise(const sf::Vector2f& src);

	//vector 
	static float magnitude(sf::Vector2f vec);

private:
	Vector();
	~Vector();
};