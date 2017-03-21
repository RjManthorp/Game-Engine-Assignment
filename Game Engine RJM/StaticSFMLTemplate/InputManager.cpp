#include "InputManager.h"
#include "Logging.h"
#include <string>
#include <iostream>

InputManager *InputManager::instance;

InputManager::InputManager()
{
	for (bool &key : keyArray)
	{
		key = false;
	}

	//for (int i = 0; i < 200; i++)
	//{
	//	keyArray[i] = false;
	//}
}

InputManager * InputManager::GetInstance()
{
	if (instance == nullptr)
		instance = new InputManager();

	return instance;
}

// takes in mouse position vector 
void InputManager::mousePosition(sf::Vector2i mPos)
{
	//std::cout << "X: " << mPos.x << "  Y: " << mPos.y << std::endl;
}

void InputManager::setMouseState(char clickNum, bool numState)
{
	mouseState[clickNum] = numState;
	std::string clickNumber = std::to_string(clickNum);
	Logger.DebugLog(clickNumber);

}

bool InputManager::getMouseState(int clickNum)
{
	return mouseState[clickNum];
}


void InputManager::setKeyState(int keyNum, bool keyState)
{
	keyArray[keyNum] = keyState;
	char keyValue = static_cast<char>(keyNum);
	std::string keyNumber(1, keyValue);
	//Logger.DebugLog(keyNumber);
}

bool InputManager::getKeyState(int keyNum) 
{
	return keyArray[keyNum];
}
