#pragma once
#include "Physics.h"
class PhysicsCircle :
	public Physics
{
public:
	PhysicsCircle(int xPos, int yPos, float angle, float radius, b2World & world, sf::Color colour, bool dynamic);
	~PhysicsCircle();

	void buildShape(int xPos, int yPos, float radius, sf::Color colour);

	virtual sf::Shape &GetShape() { return shape; }

private:

	b2CircleShape circle;
	sf::CircleShape shape;
};

