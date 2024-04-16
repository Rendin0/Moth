#include <iostream>
#include <SFML/Window.hpp>
#include "plane.h"
#include <ctime>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Moth");
	window.setFramerateLimit(80);

	sf::Event event;
	sf::Mouse mouse;
	Plane plane;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // Закрытие
				window.close();
			if (event.type == sf::Event::KeyPressed) // Нажатие на клаву
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;

				default:
					break;
				}
			}
		}
		window.clear(sf::Color(255, 255, 255));
		window.draw(plane);
		window.display();
	}


	return 0;
}