#pragma once
#include "Physics.h"
class PhysicsCircle :
	public Physics
{
public:
	PhysicsCircle(int xPos, int yPos, float angle, float radius, b2World & world, sf::Color colour, sf::Color outlineColour, float lineThinkness, bool dynamic);
	~PhysicsCircle();

	void buildShape(int xPos, int yPos, float radius, sf::Color colour, sf::Color outlineColour, float lineThinkness);

	virtual sf::Shape &GetShape() { return shape; }

private:

	b2CircleShape circle;
	sf::CircleShape shape;
};

