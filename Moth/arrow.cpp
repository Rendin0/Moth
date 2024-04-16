#include "arrow.h"

Arrow::Arrow(float length)
{
	line = sf::RectangleShape(sf::Vector2f(length, 0));
	line.setOutlineThickness(0.5f);
	line.setOutlineColor(sf::Color(0, 0, 0));
	line.setFillColor(sf::Color::Transparent);

	triangle = sf::CircleShape(5, 3);
	triangle.rotate(90);
	triangle.setOrigin(sf::Vector2f(triangle.getRadius(), line.getSize().x));
	triangle.setOutlineThickness(0.8f);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineColor(sf::Color(0, 0, 0));
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

void Arrow::move(sf::Vector2f vect2f)
{
	line.move(vect2f);
	triangle.move(vect2f);
}

void Arrow::setOrigin(sf::Vector2f vect2f)
{
	line.setOrigin(vect2f);
	triangle.setOrigin(vect2f);
}

void Arrow::setPosition(sf::Vector2f vec2f)
{
	line.setPosition(vec2f);
	triangle.setPosition(vec2f);
}

sf::Vector2f Arrow::getPoint(std::size_t index) const
{
	return (index < line.getPointCount() ? line.getPoint(index) : triangle.getPoint(index - line.getPointCount()));
}

std::size_t Arrow::getPointCount() const
{
	return line.getPointCount() + triangle.getPointCount();
}
