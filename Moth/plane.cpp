#include "plane.h"

Plane::Plane()
{
	arrows = { Arrow(500.f) };
}

void Plane::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (const Arrow& i : arrows)
		target.draw(i, states);
}

Arrow& Plane::getArrow(size_t index)
{
	return arrows.at(index);
}

void Plane::rotateArrow(size_t index, float angle)
{
	arrows.at(index).rotate(angle);
}

void Plane::moveArrow(size_t index, sf::Vector2f cords)
{
	arrows.at(index).move(cords);
}

void Plane::setPositionArrow(size_t index, sf::Vector2f cords)
{
	arrows.at(index).setPosition(cords);
}

void Plane::setOriginArrow(size_t index, sf::Vector2f cords)
{
	arrows.at(index).setOrigin(cords);
}



