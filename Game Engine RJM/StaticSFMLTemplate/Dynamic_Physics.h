#pragma once
#include <Box2D\Box2D.h>
#include "Physics.h"
#include <vector>

class Dynamic_Physics : public Physics
{
public:
	//New constructor - pushes objects into vector
	Dynamic_Physics(int xPos, int yPos, float width, float height, b2World & world);

	static std::vector<Dynamic_Physics*> dynamicObjects;
};

