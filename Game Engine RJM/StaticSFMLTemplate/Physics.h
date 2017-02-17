#pragma once
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

const float SCALE = 30.f;

class Physics
{
public:
	// default constructor, sets height and width to 32.
	Physics() : width(32.0f), height(32.0f) {};

	// constructor with width + height set
	Physics(float w, float h) : width(w), height(h) {};

	Physics(float w, float h, b2World& world) : width(w), height(h) { CreateBox(world); }
	//Physics(float w, float h, b2World& world) : width(w), height(h) { CreateGround(world); }

	void CreateBox(b2World& World);

	void CreateGround(b2World& World);

	void Draw(sf::RenderWindow *window);

	void Initialize(sf::Texture &spriteTex);

private:
	sf::Sprite sprite;
	b2Body *body;

	float width;
	float height;
};

