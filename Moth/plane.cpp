#include "plane.h"

Plane::Plane()
{
	arrows = {};
}

void Plane::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	sf::RectangleShape axis(sf::Vector2f(800, 0));
	axis.setOutlineThickness(0.5f);
	axis.setOutlineColor(sf::Color(0, 0, 0));
	axis.setFillColor(sf::Color::Transparent);
	axis.setOrigin(0.f, -400.f);
	target.draw(axis, states);

	axis.setRotation(90);
	axis.setOrigin(0.f, 400.f);
	target.draw(axis, states);
}

