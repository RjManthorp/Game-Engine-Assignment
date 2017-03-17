#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include <vector>

class Physics
{
public:
	Physics() {};
	Physics(int xPos, int yPos, float width, float height, b2World & world, sf::Color colour, sf::Color outlineColour, float lineThinkness, bool dynamic = false); //constructor for a new physics object
	~Physics();

	void SetPosition(float x, float y, bool updatePhysics = false);
	sf::Vector2f GetScreenPosition();
	sf::Vector2f GetPhysicsPosition();

	sf::Sprite GetSprite() { return sprite; }
	void SetSprite(sf::Sprite newSprite) { sprite = newSprite; }
	sf::Texture GetTexture() { return texture; }
	void SetTexture(sf::Texture newTex) { texture = newTex; }

	virtual sf::Shape &GetShape() { return shape; }
	b2Body *GetPhysicsBody() const { return body; }

	void ApplyForce(b2Vec2 force);
	void ApplyLinearImpulse(b2Vec2 force);


protected:
	void buildBody(int xPos, int yPos, b2World & world, b2Shape &shape);
	void buildShape(int xPos, int yPos, float width, float height, sf::Color colour, sf::Color outlineColour, float lineThinkness);

	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape box;
	b2FixtureDef fixtureDef;

	sf::RectangleShape shape;

	sf::Texture texture;
	sf::Sprite sprite;

	bool isDynamic;

public:
	static std::vector<Physics*> PhysicsObjects;
};

extern const float SCALE;
