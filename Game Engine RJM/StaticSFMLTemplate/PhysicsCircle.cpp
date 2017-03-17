#include "PhysicsCircle.h"



PhysicsCircle::PhysicsCircle(int xPos, int yPos, float angle, float radius, b2World & world, sf::Color colour, sf::Color outlineColour, float lineThinkness, bool dynamic)
{
	if (dynamic)
		bodyDef.type = b2_dynamicBody; // dynamic is effected by gravity

	circle.m_radius = radius / SCALE;

	buildBody(xPos, yPos, world, circle);
	buildShape(xPos, yPos, radius, colour, outlineColour, lineThinkness);

	PhysicsObjects.push_back(this);
}

void PhysicsCircle::buildShape(int xPos, int yPos, float radius, sf::Color colour, sf::Color outlineColour, float lineThinkness)
{
	shape = sf::CircleShape(radius);
	shape.setOrigin(sf::Vector2f(radius, radius ));
	shape.setPosition(sf::Vector2f((float)xPos, (float)yPos));
	shape.setFillColor(colour);
	shape.setOutlineColor(outlineColour);
	shape.setOutlineThickness(lineThinkness);
}

PhysicsCircle::~PhysicsCircle()
{}


