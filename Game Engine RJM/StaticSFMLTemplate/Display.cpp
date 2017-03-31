#include "Display.h"
#include "Physics.h"
#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int loadMap()
{
	ifstream File;
	File.open("map.txt");
	return 0;
}




void Display::drawScreenGrid(sf::RenderWindow * window)
{
	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 40; y++) {

			sf::Vector2f shapeSize = sf::Vector2f(window->getSize().x / 40, window->getSize().y / 40);
			sf::RectangleShape square;
			square.setPosition(sf::Vector2f(x * shapeSize.x, y * shapeSize.y));
			square.setSize(sf::Vector2f(shapeSize.x, shapeSize.y));
			square.setOutlineColor(sf::Color(125, 125, 125, 125));
			square.setOutlineThickness(-1);
			square.setFillColor(sf::Color::White);
			window->draw(square);
		}
	}
}

