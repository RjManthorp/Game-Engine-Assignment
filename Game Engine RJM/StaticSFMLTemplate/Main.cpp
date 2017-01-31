#include <SFML/Graphics.hpp>
#include <iostream>
#include "Logging.h"

int screenX = 800;
int screenY = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Skeleton Foot Engine");
	sf::Texture LogoTexture;
	sf::Sprite Logo;


	if (!LogoTexture.loadFromFile("logo.png"))
		std::cout << "Error loading image file" << std::endl;
	Logging instance;

	while (window.isOpen()) // main game loop
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		std::string Input;
		Input = "Hello";

		instance.DebugLog(Input);




		window.clear();

		// draw stuff here

		window.display();

	}

	return 0;

}