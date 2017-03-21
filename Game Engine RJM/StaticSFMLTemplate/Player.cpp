#include "Player.h"
#include "Physics.h"
#include "PhysicsCircle.h"
#include "Logging.h"

void Player::addJoint(b2World &world, b2Body &shape1, b2Body &shape2)
{
	b2JointDef jointDef;
	//jointDef.bodyA = shape1;
	//jointDef.bodyB = shape2;
	//
}


void Player::movement()
{
	Logging logger;
	if (InputManager::GetInstance()->getKeyState(22) || InputManager::GetInstance()->getKeyState(73))//accelerate
	{
		printf(" Accelerate\n");
		logger.DebugLog("Accelerate Pressed");
		body->ApplyLinearImpulse(b2Vec2(0, -1), body->GetWorldCenter(), true);
		
	}
	if (InputManager::GetInstance()->getKeyState(18) || InputManager::GetInstance()->getKeyState(74)) //Reverse
	{
		printf(" Reverse\n");
		logger.DebugLog("Reverse Pressed");
		body->ApplyLinearImpulse(b2Vec2(0, 1), body->GetWorldCenter(), true);
		
	}
	if (InputManager::GetInstance()->getKeyState(0) || InputManager::GetInstance()->getKeyState(71)) //left
	{
		printf(" Steer Left\n");
		logger.DebugLog("Steer Left Pressed");
		body->ApplyLinearImpulse(b2Vec2(-1, 0), body->GetWorldCenter(), true);
		
	}
	if (InputManager::GetInstance()->getKeyState(3) || InputManager::GetInstance()->getKeyState(72)) //right
	{
		printf(" Steer Right\n");
		logger.DebugLog("Steer Right Pressed");
		body->ApplyLinearImpulse(b2Vec2(1, 0), body->GetWorldCenter(), true);
		
	}
}
