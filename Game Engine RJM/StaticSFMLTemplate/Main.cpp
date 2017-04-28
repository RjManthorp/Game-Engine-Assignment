#include <iostream>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "b2GLDraw.h"

#include "Logging.h"
#include "Display.h"
#include "InputManager.h"
#include "Physics.h"
#include "PhysicsCircle.h"
#include "player.h"

#define _USE_MATH_DEFINES 1

#include <math.h>

int screenX = 780;
int screenY = 600;

//Box2D
int velocityIterations = 8;
int positionIterations = 3;
float32 timeStep = 1.0f / 60.0f;

bool mouseClick;


int main()
{
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Skeleton Foot Engine");
	Display Draw;
	
	sf::Texture ball;
	if (!ball.loadFromFile("ball.png"))
		std::cout << "error laoding image file" << std::endl;
	sf::Sprite ballItem(ball);
	ballItem.setScale(0.41f, 0.41f);
	ballItem.setOrigin(400, 400);
	ballItem.setPosition(390,310);

	sf::Texture bTexture;
	if (!bTexture.loadFromFile("map.png"))
		std::cout << "Error loading image file" << std::endl;
	sf::Sprite background(bTexture);

	

	//-----------
	//Box2D
	b2Vec2 Gravity(0.0f, 0.0f);
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
	PhysicsCircle *circle = new PhysicsCircle(390, 305, 125.f, 160.0f, World, sf::Color::Transparent, sf::Color::White, -2, false);

	Physics floor = Physics(300, 565, 1000.f, 10.f, World, sf::Color::Transparent, sf::Color::White, -1);
	Physics roof = Physics(300, 35, 1000.f, 10.f, World, sf::Color::Transparent, sf::Color::White, -1);
	Physics *wallLeft = new Physics(35, 150, 10.f, 900.f, World, sf::Color::Transparent, sf::Color::White, -1);
	Physics *wallRight = new Physics(745, 150, 10.f, 900.f, World, sf::Color::Transparent, sf::Color::White, -1);

	Physics *item = new Physics(100, 60, 10, 10, World, sf::Color::Red, sf::Color::Black, -2, true);
	Physics *item2 = new Physics(150, 60, 10, 10, World, sf::Color::Red, sf::Color::Black, -2, true);
	Physics *item3 = new Physics(200, 60, 10, 10, World, sf::Color::Red, sf::Color::Black, -2, true);
	Physics *item4 = new Physics(250, 60, 10, 10, World, sf::Color::Red, sf::Color::Black, -2, true);

	Player *player = new Player(50, 50, 24.f, 24.f, World, sf::Color::Black, sf::Color::White, -2, true);

	while (window.isOpen()) // main game loop
	{
		//-------------
		//Window clear
		window.clear();
		//-------------
		// Input
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window); //gets the mouse x and y
		InputManager::GetInstance()->mousePosition(mousePosition); // writes x and y to terminal
		//mouseObject->SetPosition(mousePosition.x, mousePosition.y, true);
		
		//circle->SetTexture(ball);
		if (mouseClick == true)
		{
			Physics *item = new Physics(mousePosition.x, mousePosition.y, 10, 10, World, sf::Color::Red, sf::Color::Black, -2, true);
		}
		

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
					//physicsObject->ApplyLinearImpulse(b2Vec2(-100, 0));
					mouseClick = true;
					
					break;
				case 1:
					mouseButtonDown = "Right mouse button";
					//physicsObject->ApplyLinearImpulse(b2Vec2(100, 0));
					break;
				case 2:
					mouseButtonDown = "Middle mouse button";
					//physicsObject->ApplyLinearImpulse(b2Vec2(0, -70));
					break;
				default:
					mouseButtonDown = "error";
					break;
				}
				printf("%s pressed!\n", mouseButtonDown);
				InputManager::GetInstance()->setMouseState(event.mouseButton.button, true);
				break;
			case sf::Event::MouseButtonReleased:
				const char*	mouseButtonUp;
				switch (event.mouseButton.button)
				{
				case 0:
					mouseButtonUp = "Left mouse button";
					mouseClick = false;
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
				InputManager::GetInstance()->setMouseState(event.mouseButton.button, false);
				break;
			case sf::Event::KeyPressed:
				//printf("Button %d pressed!\n", event.key.code);
				InputManager::GetInstance()->setKeyState(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				//printf("Button %d released!\n", event.key.code);
				InputManager::GetInstance()->setKeyState(event.key.code, false);
				break;
			}
		}
		//-------------
		// Physics
		World.Step(timeStep, velocityIterations, positionIterations);
		//World.DrawDebugData();
		//-------------
		// Drawing
		//Draw.drawScreenGrid(&window);
		window.draw(background);
		//window.draw(ballItem);

		player->movement();
		
		for (auto &object : Physics::PhysicsObjects)
		{
			object->GetTexture();
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




