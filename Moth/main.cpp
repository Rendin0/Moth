#include <SFML/Window.hpp>
#include "plane.h"
#include <vulcan.h>
#include <ctime>

int main()
{
	sf::WindowBase window(sf::VideoMode(1920, 1080), "Moth");
	//window.createVulkanSurface();
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
				case sf::Keyboard::PageUp:
					plane.rotateArrow(0, 2);
					break;
				case sf::Keyboard::PageDown:
					plane.rotateArrow(0, -2);
					break;
				case sf::Keyboard::Up:
					plane.moveArrow(0, sf::Vector2f(0, -5));
					break;
				case sf::Keyboard::Down:
					plane.moveArrow(0, sf::Vector2f(0, 5));
					break;
				case sf::Keyboard::Left:
					plane.moveArrow(0, sf::Vector2f(-5, 0));
					break;
				case sf::Keyboard::Right:
					plane.moveArrow(0, sf::Vector2f(5, 0));
					break;

				default:
					break;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) // Нажатие на мышку
			{
				plane.setPositionArrow(0, static_cast<sf::Vector2f>(mouse.getPosition()));
			}
		}
		window.clear(sf::Color(255, 255, 255));
		window.draw(plane);
		window.display();
	}


	return 0;
}