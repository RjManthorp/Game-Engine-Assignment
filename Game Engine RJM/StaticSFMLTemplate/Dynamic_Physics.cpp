#include "Dynamic_Physics.h"

std::vector<Dynamic_Physics*> Dynamic_Physics::dynamicObjects;

Dynamic_Physics::Dynamic_Physics(int xPos, int yPos, float width, float height, b2World & world)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(xPos/SCALE, yPos/SCALE);
	body = world.CreateBody(&bodyDef);

	box.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

	fixtureDef.shape = &box;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

	rectShape = sf::RectangleShape(sf::Vector2f(width, height));
	rectShape.setOrigin(sf::Vector2f(width / 2, height / 2));
	//rectShape.setPosition(xPos, yPos);
	rectShape.setPosition(sf::Vector2f((float)xPos, (float)yPos));
	rectShape.setFillColor(sf::Color::Cyan);

	dynamicObjects.push_back(this);
}

