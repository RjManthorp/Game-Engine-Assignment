#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logging.h"
#include "Display.h"

int screenX = 800;
int screenY = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Skeleton Foot Engine");

	Display Draw;
	Logging instance;

	while (window.isOpen()) // main game loop
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();
				break;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "Right click" << std::endl;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "Left click" << std::endl;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
			{
				std::cout << "Middle click" << std::endl;
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "Right Release" << std::endl;
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "Left Release" << std::endl;
			}
		}

		std::string Input;
		Input = "Hello";

		instance.DebugLog(Input);

		window.clear();

		Draw.Draw(&window);

		window.display();

	}

	return 0;

}