#include <iostream>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "b2GLDraw.h"

#include "Logging.h"
#include "Display.h"
#include "InputManager.h"
#include "Physics.h"
#include "PhysicsCircle.h"

#define _USE_MATH_DEFINES 1

#include <math.h>

int screenX = 800;
int screenY = 600;

//Box2D
int velocityIterations = 8;
int positionIterations = 3;
float32 timeStep = 1.0f / 60.0f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Skeleton Foot Engine");
	Display Draw;
	InputManager instance;
	//-----------
	//Box2D
	b2Vec2 Gravity(0.0f, 10.2f);
	b2World World(Gravity);

	b2GLDraw fooDrawInstance;
	World.SetDebugDraw(&fooDrawInstance);
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_centerOfMassBit;
	fooDrawInstance.SetFlags(flags);

	//Make physics object--------------------------------X-Y-H-W-Colour-Dynamic(true) or static-------------------
	Physics *physicsObject = new Physics(400, 100, 50.f, 50.f, World, sf::Color::Cyan, true);
	Physics *mouseObject = new Physics(10, 10, 70.f, 70.f, World, sf::Color::Magenta, true);
	PhysicsCircle *circle = new PhysicsCircle(100, 100, 25.f, 50.0f, World, sf::Color::Red, true);
	Physics *physicsObject2 = new Physics(400, 100, 450.f, 10.f, World, sf::Color::Cyan, true);
	Physics groundPlatform = Physics(200, 350, 400.f, 25.f,World, sf::Color::Green);
	Physics groundPlatform2 = Physics(300, 600, 1000.f, 25.f, World, sf::Color::Yellow);
	Physics *wallLeft = new Physics(0, 150, 50.f, 900.f, World, sf::Color::Blue);
	Physics *wallRight = new Physics(800, 150, 50.f, 900.f, World, sf::Color::Blue);

	while (window.isOpen()) // main game loop
	{
		//-------------
		//Window clear
		window.clear();
		//-------------
		// Input
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window); //gets the mouse x and y
		instance.mousePosition(mousePosition); // writes x and y to terminal
		mouseObject->SetPosition(mousePosition.x, mousePosition.y, true);

		//physicsObject->ApplyForce(b2Vec2(0, 50), physicsObject->GetWorldCenter());

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				const char*	mouseButtonDown;
				switch (event.mouseButton.button)
				{
				case 0:
					mouseButtonDown = "Left mouse button";
					break;
				case 1:
					mouseButtonDown = "Right mouse button";
					break;
				case 2:
					mouseButtonDown = "Middle mouse button";
					break;
				default:
					mouseButtonDown = "error";
					break;
				}
				printf("%s pressed!\n", mouseButtonDown);
				instance.setMouseState(event.mouseButton.button, true);
				break;
			case sf::Event::MouseButtonReleased:
				const char*	mouseButtonUp;
				switch (event.mouseButton.button)
				{
				case 0:
					mouseButtonUp = "Left mouse button";
					break;
				case 1:
					mouseButtonUp = "Right mouse button";
					break;
				case 2:
					mouseButtonUp = "Middle mouse button";
					break;
				default:
					mouseButtonUp = "error";
					break;
				}
				printf("%s released!\n", mouseButtonUp);
				instance.setMouseState(event.mouseButton.button, false);
				break;
			case sf::Event::KeyPressed:
				printf("Button %d pressed!\n", event.key.code);
				instance.setKeyState(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				printf("Button %d released!\n", event.key.code);
				instance.setKeyState(event.key.code, false);
				break;
			}
		}
		//-------------
		// Physics
		World.Step(timeStep, velocityIterations, positionIterations);
		//World.DrawDebugData();
		//-------------
		// Drawing
		Draw.drawScreenGrid(&window);
		for (auto &object : Physics::PhysicsObjects)
		{
			object->GetShape().setRotation(object->GetPhysicsBody()->GetAngle() / M_PI * 180.f);
			object->GetShape().setPosition(sf::Vector2f((object->GetPhysicsBody()->GetPosition().x * SCALE), (object->GetPhysicsBody()->GetPosition().y*SCALE)));
			window.draw(object->GetShape());
		}	
		//-------------
		// Display
		window.display();
	}
	return 0;
}




//
//#include <SFML\Graphics.hpp>
//#include <Box2D\Box2D.h>
//#include "b2GLDraw.h"
//
///** We need this to easily convert between pixel and real-world coordinates*/
//static const float SCALE = 30.f;
//
///** Create the base for the boxes to land */
//void CreateGround(b2World& World, float X, float Y);
//
///** Create the boxes */
//void CreateBox(b2World& World, int MouseX, int MouseY);
//
//int main() {
//	/** Prepare the window */
//	sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Test");
//	Window.setFramerateLimit(60);
//
//	/** Prepare the world */
//	b2Vec2 Gravity(0.f, 9.8f);
//	b2World World(Gravity);
//	CreateGround(World, 400.f, 500.f);
//
//
//b2GLDraw fooDrawInstance;
//World.SetDebugDraw(&fooDrawInstance);
//uint32 flags = 0;
//flags += b2Draw::e_shapeBit;
//flags += b2Draw::e_jointBit;
//flags += b2Draw::e_aabbBit;
//flags += b2Draw::e_pairBit;
//flags += b2Draw::e_centerOfMassBit;
//fooDrawInstance.SetFlags(flags);
//
//
//	/** Prepare textures */
//	sf::Texture GroundTexture;
//	sf::Texture BoxTexture;
//	GroundTexture.loadFromFile("ground.png");
//	BoxTexture.loadFromFile("Box.png");
//
//	while (Window.isOpen()) {
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//			int MouseX = sf::Mouse::getPosition(Window).x;
//			int MouseY = sf::Mouse::getPosition(Window).y;
//			CreateBox(World, MouseX, MouseY);
//		}
//		World.Step(1 / 60.f, 8, 3);
//
//		Window.clear(sf::Color::Yellow);
//		int BodyCount = 0;
//		for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext()) {
//			if (BodyIterator->GetType() == b2_dynamicBody) {
//				sf::Sprite sprite;
//				sprite.setTexture(BoxTexture);
//				sprite.setOrigin(16.f, 16.f);
//				
//				sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
//				sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
//				Window.draw(sprite);
//				++BodyCount;
//			} 
//			else 
//			{
//				sf::Sprite GroundSprite;
//				GroundSprite.setColor(sf::Color::Yellow);
//				GroundSprite.setTexture(GroundTexture);
//				GroundSprite.setOrigin(400.f, 8.f);
//				GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
//				GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
//				Window.draw(GroundSprite);
//			}
//		}
//		World.DrawDebugData();
//		Window.display();
//	}
//
//	return 0;
//}
//
//void CreateBox(b2World& World, int MouseX, int MouseY) {
//	b2BodyDef BodyDef;
//	BodyDef.position = b2Vec2(MouseX / SCALE, MouseY / SCALE);
//	BodyDef.type = b2_dynamicBody;
//	b2Body* Body = World.CreateBody(&BodyDef);
//
//	b2PolygonShape Shape;
//	Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
//	b2FixtureDef FixtureDef;
//	FixtureDef.density = 1.f;
//	FixtureDef.friction = 0.7f;
//	FixtureDef.shape = &Shape;
//	Body->CreateFixture(&FixtureDef);
//}
//
//void CreateGround(b2World& World, float X, float Y) {
//	b2BodyDef BodyDef;
//	BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
//	BodyDef.type = b2_kinematicBody;
//	b2Body* Body = World.CreateBody(&BodyDef);
//
//	b2PolygonShape Shape;
//	Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
//	b2FixtureDef FixtureDef;
//	b2Color(33.3f, 33.3f, 0.1f);
//	FixtureDef.density = 0.f;
//	FixtureDef.shape = &Shape;
//	Body->CreateFixture(&FixtureDef);
//}