#include "arrow.h"

Arrow::Arrow(float length)
{
	line = sf::RectangleShape(sf::Vector2f(length, 0));
	triangle = sf::CircleShape(5, 3);
	triangle.setOrigin(sf::Vector2f(0, length));
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(line, states);
	target.draw(triangle, states);
}

void Arrow::rotate(float angle)
{
	line.rotate(angle);
	triangle.rotate(angle);
}
