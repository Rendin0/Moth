#pragma once
#include <SFML/Graphics.hpp>

class Arrow : public sf::Shape
{
	sf::RectangleShape line;
	sf::CircleShape triangle;
public:
	Arrow(float length);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void rotate(float angle);
	void setOrigin(sf::Vector2f vect2f);

};

