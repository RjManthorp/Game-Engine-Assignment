#include "Physics.h"



void Physics::CreateBox(b2World& World)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(10/SCALE, 50/SCALE);
	BodyDef.type = b2_dynamicBody;
	body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);

	sprite.setOrigin(width / 2, height / 2);
}

void Physics::CreateGround(b2World & World)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(20 / SCALE, 500 / SCALE);
	BodyDef.type = b2_staticBody;
	body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);

	sprite.setOrigin(width / 2, height / 2);

}

void Physics::Draw(sf::RenderWindow * window)
{
	sprite.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
	sprite.setRotation(body->GetAngle() * 180/b2_pi);
	window->draw(sprite);
}

void Physics::Initialize(sf::Texture & spriteTex)
{
	sprite.setTexture(spriteTex);
}