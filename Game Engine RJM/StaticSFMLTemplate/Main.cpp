//#include <iostream>
//
//#include <SFML/Graphics.hpp>
//#include <Box2D\Box2D.h>
//
//#include "Logging.h"
//#include "Display.h"
//#include "InputManager.h"
//
//int screenX = 800;
//int screenY = 600;
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Skeleton Foot Engine");
//
//	Display Draw;
//
//	InputManager instance;
//
//b2Vec2 Gravity(0.f, 9.8f);
//b2World World(Gravity);
//
//	while (window.isOpen()) // main game loop
//	{
//
//		sf::Vector2i mousePosition = sf::Mouse::getPosition(window); //gets the mouse x and y
//		instance.mousePosition(mousePosition); // writes x and y to terminal
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//
//			case sf::Event::Closed:
//				window.close();
//				break;
//			case sf::Event::MouseButtonPressed:
//				printf("Button %d pressed!\n", event.mouseButton.button);
//				instance.setMouseState(event.mouseButton.button, true);
//				break;
//			case sf::Event::MouseButtonReleased:
//				printf("Button %d released!\n", event.mouseButton.button);
//				instance.setMouseState(event.mouseButton.button, false);
//				break;
//			case sf::Event::KeyPressed:
//				printf("Button %d pressed!\n", event.key.code);
//				instance.setKeyState(event.key.code, true);
//				break;
//			case sf::Event::KeyReleased:
//				printf("Button %d released!\n", event.key.code);
//				instance.setKeyState(event.key.code, false);
//				break;
//			}
//			
//
//		}
//
//		window.clear();
//
//		Draw.drawScreenGrid(&window);
//		Draw.testShape(&window);
//
//		window.display();
//
//	}
//
//	return 0;
//
//}





#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

/** We need this to easily convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;

/** Create the base for the boxes to land */
void CreateGround(b2World& World, float X, float Y);

/** Create the boxes */
void CreateBox(b2World& World, int MouseX, int MouseY);

int main() {
	/** Prepare the window */
	sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Test");
	Window.setFramerateLimit(60);

	/** Prepare the world */
	b2Vec2 Gravity(0.f, 9.8f);
	b2World World(Gravity);
	CreateGround(World, 400.f, 500.f);

	/** Prepare textures */
	sf::Texture GroundTexture;
	sf::Texture BoxTexture;
	GroundTexture.loadFromFile("ground.png");
	BoxTexture.loadFromFile("Box.png");

	while (Window.isOpen()) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			int MouseX = sf::Mouse::getPosition(Window).x;
			int MouseY = sf::Mouse::getPosition(Window).y;
			CreateBox(World, MouseX, MouseY);
		}
		World.Step(1 / 60.f, 8, 3);

		Window.clear(sf::Color::Yellow);
		int BodyCount = 0;
		for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext()) {
			if (BodyIterator->GetType() == b2_dynamicBody) {
				sf::Sprite sprite;
				sprite.setTexture(BoxTexture);
				sprite.setOrigin(16.f, 16.f);
				
				sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
				Window.draw(sprite);
				++BodyCount;
			} 
			else 
			{
				sf::Sprite GroundSprite;
				GroundSprite.setColor(sf::Color::Yellow);
				GroundSprite.setTexture(GroundTexture);
				GroundSprite.setOrigin(400.f, 8.f);
				GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
				GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
				Window.draw(GroundSprite);
			}
		}
		Window.display();
	}

	return 0;
}

void CreateBox(b2World& World, int MouseX, int MouseY) {
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(MouseX / SCALE, MouseY / SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}

void CreateGround(b2World& World, float X, float Y) {
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
	BodyDef.type = b2_kinematicBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	b2Color(33.3f, 33.3f, 0.1f);
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}