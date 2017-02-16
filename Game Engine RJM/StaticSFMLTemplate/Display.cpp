#include "Display.h"

void Display::drawScreenGrid(sf::RenderWindow * window)

{
	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 40; y++) {

			sf::Vector2f shapeSize = sf::Vector2f(window->getSize().x / 40, window->getSize().y / 40);

			sf::RectangleShape square;
			square.setPosition(sf::Vector2f(x * shapeSize.x, y * shapeSize.y));
			square.setSize(sf::Vector2f(shapeSize.x, shapeSize.y));
			square.setOutlineColor(sf::Color(125, 125, 0, 125));
			square.setOutlineThickness(-1);
			square.setFillColor(sf::Color::Transparent);

			window->draw(square);

		}
	}
}

void Display::testShape(sf::RenderWindow * window)
{
	sf::RectangleShape block;
	block.setPosition(320, 80);
	block.setSize(sf::Vector2f(80.f, 80.f));
	block.setOutlineColor(sf::Color::Green);
	block.setOutlineThickness(-2);
	block.setFillColor(sf::Color::Transparent);

	window->draw(block);
}




