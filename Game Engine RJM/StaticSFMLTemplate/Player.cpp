#include "Player.h"
#include "Physics.h"


Player::Player()
{
	if (InputManager::GetInstance()->getKeyState(22));//accelerate
	{
		//move the player forwards
		printf("accelerate pressed");
	}

	if (InputManager::GetInstance()->getKeyState(18)); //brake
	{
		//move the player backwards
	}

}


Player::~Player()
{}
