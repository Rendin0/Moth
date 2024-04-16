#include "plane.h"

Plane::Plane()
{
	arrows = {};
}

void Plane::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	Arrow x_axis(target.getSize().x - 10);
	Arrow y_axis(target.getSize().y - 10);

	x_axis.move(sf::Vector2f(0, target.getSize().y / 2));
	y_axis.move(sf::Vector2f(target.getSize().x / 2, target.getSize().y));

	y_axis.rotate(-90);

	target.draw(x_axis, states);
	target.draw(y_axis, states);

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



