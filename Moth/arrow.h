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
	void move(sf::Vector2f vect2f);
	void setOrigin(sf::Vector2f vect2f);
	void setPosition(sf::Vector2f vec2f);

	sf::Vector2f getPoint(std::size_t index) const override;
	std::size_t getPointCount() const override;
};

