#pragma once
#include "arrow.h"
#include <vector>

class Plane : public sf::Drawable, public sf::Transformable
{
	std::vector<Arrow> arrows;

public:
	Plane();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Arrow& getArrow(size_t index);


	void rotateArrow(size_t index, float angle);
	void moveArrow(size_t index, sf::Vector2f cords);
	void setPositionArrow(size_t index, sf::Vector2f cords);
	void setOriginArrow(size_t index, sf::Vector2f cords);

	Plane& addPoint(long double x, long double y);
};

