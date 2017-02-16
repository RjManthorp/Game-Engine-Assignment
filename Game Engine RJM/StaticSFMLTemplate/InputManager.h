#pragma once
#include "Logging.h"
#include <SFML/Graphics.hpp>
class InputManager
{
public:

	void mousePosition(sf::Vector2i mPos);

	void setMouseState(int clickNum, bool numState);
	void setKeyState(int keyNum, bool keyState);
	
	bool getMouseState(int clickNum);
	bool getKeyState(int keyNum);

	Logging instance;

private:
	bool mouseState[3];
	bool currentMouseState[3];
	bool prevMouseState[3];

	bool keyArray[200];
	bool currentKeyState[200];
	bool precKeyState[200];




};

