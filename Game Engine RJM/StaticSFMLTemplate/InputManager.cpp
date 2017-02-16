#include "InputManager.h"
#include "Logging.h"
#include <string>
#include <iostream>


// takes in mouse position vector 
void InputManager::mousePosition(sf::Vector2i mPos)
{
	std::cout << "X: " << mPos.x << "  Y: " << mPos.y << std::endl;
}

void InputManager::setMouseState(int clickNum, bool numState)
{
	mouseState[clickNum] = numState;
	std::string clickNumber = std::to_string(clickNum);
	instance.DebugLog(clickNumber);
	
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
	instance.DebugLog(keyNumber);
}

bool InputManager::getKeyState(int keyNum) 
{
	return keyArray[keyNum];
}
