#include "Input.h"

using namespace GaltE;

Input::Input()
{
	mWindow = NULL;
	mInitilazied = false;
	std::memset(&mKeysReleased, false, sizeof(mKeysReleased));
	std::memset(&mKeysPressed, false, sizeof(mKeysPressed));
	std::memset(&mKeysOld, false, sizeof(mKeysOld));
}

bool Input::init(sf::Window &window)
{
	mWindow = &window;
	
	//check for valid window
	if (mWindow == NULL)
	{
		return false;
	}
	
	mInitilazied = true;
	return true;
}

void Input::update()
{
	if (!mInitilazied)
	{
		return;
	}

	//update key states
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		mKeysReleased[i] = false;
		mKeysPressed[i] = false;

		//was the key just realsed?
		if (mKeysOld[i])
		{
			if (!getKeyState(i, KEY_DOWN))
			{
				mKeysReleased[i] = true;
			}
		}
		//was the key just pressed?
		else if (!mKeysOld[i])
		{
			if (getKeyState(i, KEY_DOWN))
				mKeysPressed[i] = true;
		}

		//save the current state
		mKeysOld[i] = getKeyState(i, KEY_DOWN);
	}

	//get the text entered this frame
	mTextEntered = "";
	while (mWindow->pollEvent(mEvent))
	{
		if (mEvent.type == sf::Event::TextEntered)
		{
			sf::Uint32 unicode = mEvent.text.unicode;
			char u1 = (char)unicode;
			std::string s1 = "";
			s1.push_back(u1);
			mTextEntered = s1;
		}
	}
}

bool Input::getKeyState(int key, KeyState state)
{
	switch (state)
	{
	case KEY_DOWN:
		return (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key))); 
	
	case KEY_RELEASED:
		return mKeysReleased[key];

	case KEY_UP:
		return !(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)));

	case KEY_PRESSED:
		return mKeysPressed[key];

	default:
		return false;
	}
}

bool Input::getButtonState(int button)
{
	switch (button)
	{
	case GMB_Left:
		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	
	case GMB_Right:
		return sf::Mouse::isButtonPressed(sf::Mouse::Right);

	case GMB_Middle:
		return sf::Mouse::isButtonPressed(sf::Mouse::Middle);

	case GMB_LeftSide:
		return sf::Mouse::isButtonPressed(sf::Mouse::XButton1);

	case GMB_RightSide:
		return sf::Mouse::isButtonPressed(sf::Mouse::XButton2);

	default:
		return false;
	}
}

int Input::getGlobalMouseX()
{
	sf::Vector2i position = sf::Mouse::getPosition();
	return position.x;
}

int Input::getGlobalMouseY()
{
	sf::Vector2i position = sf::Mouse::getPosition();
	return position.y;
}

Point<int> Input::getGlobalMousePos()
{
	sf::Vector2i position = sf::Mouse::getPosition();
	return Point<int>(position.x, position.y);
}

int Input::getLocalMouseX()
{
	sf::Vector2i position = sf::Mouse::getPosition(*mWindow);
	return position.x;
}

int Input::getLocalMouseY()
{
	sf::Vector2i position = sf::Mouse::getPosition(*mWindow);
	return position.y;
}

Point<int> Input::getLocalMousePos()
{
	sf::Vector2i position = sf::Mouse::getPosition(*mWindow);
	return Point<int>(position.x, position.y);
}