#pragma once
#include <Box2D\Box2D.h>
#include "InputManager.h"

#include "Physics.h"

class Player : public Physics
{
public:

	//int accelerate;
	//int brake;
	//int steerLeft;
	//int steerRight;

	Player(int xPos, int yPos, float width, float height, b2World & world, sf::Color colour, sf::Color outlineColour, float lineThinkness, bool dynamic = false)
		: Physics(xPos, yPos, width, height, world, colour, outlineColour, lineThinkness, dynamic)
	{

	}
	void movement();

private:

	void addJoint(b2World & world, b2Body &shape, b2Body &shape2);


};

