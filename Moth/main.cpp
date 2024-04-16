#include <iostream>
#include <SFML/Window.hpp>
#include "plane.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Moth");
	window.setFramerateLimit(80);

	sf::Event event;
	Plane plane;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		window.clear(sf::Color(255, 255, 255));
		window.draw(plane);
		window.display();
	}


	return 0;
}