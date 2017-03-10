#pragma once

#include <vector>

#include "Physics.h"

class Static_Physics : public Physics
{
public:

	static std::vector<Static_Physics*> floors;

	Static_Physics(int xPos, int yPos, int width, int height, b2World & World);
};

