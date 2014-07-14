/**
* This input system is copied and modified from the Glance Engine's input class @https://github.com/DanWatkins/GlanceEngineSDK/tree/master/GlanceEngine/GlanceCore/Src
* The Glance Engine was created by Dan Watkins. 
*/

#include "Main.h"

#ifndef INPUT_H
#define INPUT_H

const int ARRAYSIZE = 512;

namespace GaltE
{
	typedef sf::Mouse::Button BUTTON;

	//mainboard letters
	const int GK_A = sf::Keyboard::A;
	const int GK_B = sf::Keyboard::B;
	const int GK_C = sf::Keyboard::C;
	const int GK_D = sf::Keyboard::D;
	const int GK_E = sf::Keyboard::E;
	const int GK_F = sf::Keyboard::F;
	const int GK_G = sf::Keyboard::G;
	const int GK_H = sf::Keyboard::H;
	const int GK_I = sf::Keyboard::I;
	const int GK_J = sf::Keyboard::J;
	const int GK_K = sf::Keyboard::K;
	const int GK_L = sf::Keyboard::L;
	const int GK_M = sf::Keyboard::M;
	const int GK_N = sf::Keyboard::N;
	const int GK_O = sf::Keyboard::O;
	const int GK_P = sf::Keyboard::P;
	const int GK_Q = sf::Keyboard::Q;
	const int GK_R = sf::Keyboard::R;
	const int GK_S = sf::Keyboard::S;
	const int GK_T = sf::Keyboard::T;
	const int GK_U = sf::Keyboard::U;
	const int GK_V = sf::Keyboard::V;
	const int GK_W = sf::Keyboard::W;
	const int GK_X = sf::Keyboard::X;
	const int GK_Y = sf::Keyboard::Y;
	const int GK_Z = sf::Keyboard::Z;

	//mainboard numbers
	const int GK_Num0 = sf::Keyboard::Num0;
	const int GK_Num1 = sf::Keyboard::Num1;
	const int GK_Num2 = sf::Keyboard::Num2;
	const int GK_Num3 = sf::Keyboard::Num3;
	const int GK_Num4 = sf::Keyboard::Num4;
	const int GK_Num5 = sf::Keyboard::Num5;
	const int GK_Num6 = sf::Keyboard::Num6;
	const int GK_Num7 = sf::Keyboard::Num7;
	const int GK_Num8 = sf::Keyboard::Num8;
	const int GK_Num9 = sf::Keyboard::Num9;

	//keypad  numbers
	const int GK_Numpad0 = sf::Keyboard::Numpad0;
	const int GK_Numpad1 = sf::Keyboard::Numpad1;
	const int GK_Numpad2 = sf::Keyboard::Numpad2;
	const int GK_Numpad3 = sf::Keyboard::Numpad3;
	const int GK_Numpad4 = sf::Keyboard::Numpad4;
	const int GK_Numpad5 = sf::Keyboard::Numpad5;
	const int GK_Numpad6 = sf::Keyboard::Numpad6;
	const int GK_Numpad7 = sf::Keyboard::Numpad7;
	const int GK_Numpad8 = sf::Keyboard::Numpad8;
	const int GK_Numpad9 = sf::Keyboard::Numpad9;

	//mainboard other symbols
	const int GK_Grave = sf::Keyboard::Tilde;
	const int GK_Backspace = sf::Keyboard::BackSpace;
	const int GK_Space = sf::Keyboard::Space;
	const int GK_Add = sf::Keyboard::Add;
	const int GK_Subtract = sf::Keyboard::Subtract;
	const int GK_Multiply = sf::Keyboard::Multiply;
	const int GK_Divide = sf::Keyboard::Divide;
	const int GK_Dash = sf::Keyboard::Dash;
	const int GK_Equals = sf::Keyboard::Equal;
	const int GK_LBracket = sf::Keyboard::LBracket;
	const int GK_RBracket = sf::Keyboard::RBracket;
	const int GK_SemiColon = sf::Keyboard::SemiColon;
	const int GK_Quote = sf::Keyboard::Quote;
	const int GK_Comma = sf::Keyboard::Comma;
	const int GK_Period = sf::Keyboard::Period;
	const int GK_Slash = sf::Keyboard::Slash;
	const int GK_Backslash = sf::Keyboard::BackSlash;

	//mainboard functionality
	const int GK_Tab = sf::Keyboard::Tab;
	const int GK_LShift = sf::Keyboard::LShift;
	const int GK_RShift = sf::Keyboard::RShift;
	const int GK_LCtrl = sf::Keyboard::LControl;
	const int GK_RCtrl = sf::Keyboard::RControl;
	const int GK_LWindows = sf::Keyboard::LSystem;
	const int GK_RWindows = sf::Keyboard::RSystem;
	const int GK_LAlt = sf::Keyboard::LAlt;
	const int GK_RAlt = sf::Keyboard::RAlt;
	const int GK_Context = sf::Keyboard::Menu;
	const int GK_Enter = sf::Keyboard::Return;
	const int GK_Escape = sf::Keyboard::Escape;
	const int GK_Insert = sf::Keyboard::Insert;
	const int GK_Delete = sf::Keyboard::Delete;
	const int GK_Left = sf::Keyboard::Left;
	const int GK_Up = sf::Keyboard::Up;
	const int GK_Right = sf::Keyboard::Right;
	const int GK_Down = sf::Keyboard::Down;

	//function keys
	const int GK_F1 = sf::Keyboard::F1;
	const int GK_F2 = sf::Keyboard::F2;
	const int GK_F3 = sf::Keyboard::F3;
	const int GK_F4 = sf::Keyboard::F4;
	const int GK_F5 = sf::Keyboard::F5;
	const int GK_F6 = sf::Keyboard::F6;
	const int GK_F7 = sf::Keyboard::F7;
	const int GK_F8 = sf::Keyboard::F8;
	const int GK_F9 = sf::Keyboard::F9;
	const int GK_F10 = sf::Keyboard::F10;
	const int GK_F11 = sf::Keyboard::F11;
	const int GK_F12 = sf::Keyboard::F12;
	const int GK_F13 = sf::Keyboard::F13;
	const int GK_F14 = sf::Keyboard::F14;
	const int GK_F15 = sf::Keyboard::F15;

	//mouse buttons
	const int GMB_Left = sf::Mouse::Left;
	const int GMB_Right = sf::Mouse::Right;
	const int GMB_Middle = sf::Mouse::Middle;
	const int GMB_LeftSide = sf::Mouse::XButton1;
	const int GMB_RightSide = sf::Mouse::XButton2;

	/**
	* Different possible key states
	*/
	enum KeyState
	{
		KEY_DOWN,
		KEY_PRESSED,
		KEY_UP,
		KEY_RELEASED
	};

	/**
	* The class manages keyboard and mouse events by using sfml
	*/
	class Input
	{
	private:
		sf::Event mEvent;
		sf::Window *mWindow;

		bool mKeysReleased[ARRAYSIZE];
		bool mKeysPressed[ARRAYSIZE];
		bool mKeysOld[ARRAYSIZE];
		bool mInitilazied;

		std::string mTextEntered;

	public:
		/**
		* Sets up the different key states 
		*/
		Input();
		~Input();

		/**
		* Initalizes the input class
		*/
		bool init(sf::Window &window);

		/**
		* Gets latest input
		*/
		void update();

		/**
		* Checks if the key meets the quailifactions for the given key state,
		* if so, it returns true, otherwise false
		*/
		bool getKeyState(int key, KeyState state = KEY_RELEASED);
		
		/**
		* Checks if a mouse button was pressed and if so
		* it returns true, otherwise it returns false
		*/
		bool getButtonState(int button);

		/**
		* Returns the position of the mouse in global coordinates (realtive to the desktop)
		*/
		Point<int> getGlobalMousePos();

		/**
		* Returns the x position of the mouse in global coordinates
		*/
		int getGlobalMouseX();

		/**
		* Returns the y position of the mouse in global coordinates
		*/
		int getGlobalMouseY();

		/**
		* Returns the position of the mouse in local coordinates (relative to the window)
		*/
		Point<int> getLocalMousePos();

		/**
		* Returns the x position of the mouse in local coordinates
		*/
		int getLocalMouseX();

		/**
		* Returns the y position of the mouse in local coordinates
		*/
		int getLocalMouseY();

		/**
		* Sets the mouse position in global coordinates
		*/
		void setGlobalMousePos(Point<int> pos);

		/**
		* Sets the mouse position in local coordinates
		*/
		void setLocalMousePos(Point<int> pos);

		/**
		* Returns the text entered in the current frame
		*/
		std::string getEnteredText() { return mTextEntered; }
	};
}

#endif