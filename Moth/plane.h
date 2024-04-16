#pragma once
#include "arrow.h"
#include <vector>

class Plane : public sf::Drawable, public sf::Transformable
{
	std::vector<Arrow> arrows;

public:
	Plane();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	Plane& addPoint(long double x, long double y);
};

