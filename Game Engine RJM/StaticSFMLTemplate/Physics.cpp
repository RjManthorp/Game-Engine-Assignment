#include "Physics.h"

const float SCALE = 30.0f; //scale is needed as box2D uses meters and sfml uses pixels

std::vector<Physics*> Physics::PhysicsObjects;
//Generic physics class
Physics::Physics(int xPos, int yPos, float width, float height, b2World & world, sf::Color colour, sf::Color outlineColour, float lineThinkness, bool dynamic)//if true the object created will be effected by gravity
{
	if ( dynamic)
		bodyDef.type = b2_dynamicBody; // dynamic is effected by gravity

	box.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE); // divide by 2 to put it in the middle 

	buildBody(xPos, yPos, world, box);
	buildShape(xPos, yPos, width, height, colour, outlineColour, lineThinkness);
	
	if (dynamic)
	body->SetLinearDamping(0.1f);
	body->SetAngularDamping(0.1f);
	PhysicsObjects.push_back(this);
}

void Physics::ApplyForce(b2Vec2 force)
{
	body->ApplyForce(force, body->GetWorldCenter(), true);
}

void Physics::ApplyLinearImpulse(b2Vec2 force)
{
	body->ApplyLinearImpulse(force, body->GetWorldCenter(), true);
}

void Physics::buildBody(int xPos, int yPos, b2World & world, b2Shape &shape)
{
	bodyDef.position.Set(xPos / SCALE, yPos / SCALE); //position of the collider
	//bodyDef.angle = angle * b2_pi;
	body = world.CreateBody(&bodyDef);
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;


	body->CreateFixture(&fixtureDef);
}

void Physics::buildShape(int xPos, int yPos, float width, float height, sf::Color colour, sf::Color outlineColour, float lineThinkness )
{
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setOrigin(sf::Vector2f(width / 2, height / 2));
	shape.setPosition(sf::Vector2f((float)xPos, (float)yPos));
	shape.setFillColor(colour);
	shape.setOutlineColor(outlineColour);
	shape.setOutlineThickness(lineThinkness);
}

Physics::~Physics()
{}

void Physics::SetPosition(float x, float y, bool updatePhysics)
{
	if (updatePhysics)
		body->SetTransform(b2Vec2(x / SCALE, y / SCALE), body->GetAngle());

	shape.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Physics::GetPhysicsPosition()
{
	return sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}

sf::Vector2f Physics::GetScreenPosition()
{
	return shape.getPosition();
}
