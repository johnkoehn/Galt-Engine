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