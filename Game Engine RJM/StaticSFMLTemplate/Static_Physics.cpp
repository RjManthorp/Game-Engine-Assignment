#include "Static_Physics.h"

std::vector<Static_Physics*> Static_Physics::floors;

Static_Physics::Static_Physics(int xPos, int yPos, int width, int height, b2World & World)
{

	bodyDef.position.Set(xPos /SCALE, yPos / SCALE);
	body = World.CreateBody(&bodyDef);
	box.SetAsBox((width/2)/SCALE, (height/2) / SCALE); //replace this with width/height parameters
	body->CreateFixture(&box, 0.0f);

	rectShape = sf::RectangleShape(sf::Vector2f(width, height));
	rectShape.setOrigin(sf::Vector2f(width / 2, height / 2));
	rectShape.setPosition(sf::Vector2f(xPos, yPos));
	rectShape.setFillColor(sf::Color::Green);

	floors.push_back(this);
}

