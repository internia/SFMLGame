#include "Vector.h"
//Vector has direction and magnitude, used to init direction or represent change

Vector::Vector()
{

}

Vector::~Vector()
{
}

sf::Vector2f Vector::normalise(const sf::Vector2f& src)
{
	float len = sqrt((src.x * src.x) + (src.y * src.y));
	if (len != 0) {
		return sf::Vector2f(src.x / len, src.y / len);
	}
	else {
		return src;
	}
}

float Vector::magnitude(sf::Vector2f vec)
{
	return sqrt((vec.x*vec.x) + (vec.y*vec.y));
}
