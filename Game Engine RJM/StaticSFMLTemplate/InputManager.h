#pragma once
#include "Logging.h"
#include <SFML/Graphics.hpp>
class InputManager
{
public:

	static InputManager* GetInstance();

	void mousePosition(sf::Vector2i mPos);

	void setMouseState(char clickNum, bool numState);
	void setKeyState(int keyNum, bool keyState);
	
	bool getMouseState(int clickNum);
	bool getKeyState(int keyNum);

	Logging Logger;

private:
	InputManager();
	static InputManager *instance;

	bool mouseState[3];
	bool currentMouseState[3];
	bool prevMouseState[3];

	bool keyArray[200];
	bool currentKeyState[200];
	bool precKeyState[200];
};

