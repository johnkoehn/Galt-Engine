#ifndef KEYINPUT_H
#define KEYINPUT_H

#include "Main.h"

namespace GaltE
{
	/**
	* Class tells is a certain key is being pressed 
	* by using SFML's wonderful Keyboard class!
	*/
	class KeyInput
	{
	private:
		sf::Keyboard keyboard;

	public:
		bool A() { return keyboard.isKeyPressed(keyboard.A); }
		bool B() { return keyboard.isKeyPressed(keyboard.B); }
		bool C() { return keyboard.isKeyPressed(keyboard.C); }
		bool D() { return keyboard.isKeyPressed(keyboard.D); }
		bool E() { return keyboard.isKeyPressed(keyboard.E); }
		bool F() { return keyboard.isKeyPressed(keyboard.F); }
		bool G() { return keyboard.isKeyPressed(keyboard.G); }
		bool H() { return keyboard.isKeyPressed(keyboard.H); }
		bool I() { return keyboard.isKeyPressed(keyboard.I); }
		bool J() { return keyboard.isKeyPressed(keyboard.J); }
		bool K() { return keyboard.isKeyPressed(keyboard.K); }
		bool L() { return keyboard.isKeyPressed(keyboard.L); }
		bool M() { return keyboard.isKeyPressed(keyboard.M); }
		bool N() { return keyboard.isKeyPressed(keyboard.N); }
		bool O() { return keyboard.isKeyPressed(keyboard.O); }
		bool P() { return keyboard.isKeyPressed(keyboard.P); }
		bool Q() { return keyboard.isKeyPressed(keyboard.Q); }
		bool R() { return keyboard.isKeyPressed(keyboard.R); }
		bool S() { return keyboard.isKeyPressed(keyboard.S); }
		bool T() { return keyboard.isKeyPressed(keyboard.T); }
		bool U() { return keyboard.isKeyPressed(keyboard.U); }
		bool V() { return keyboard.isKeyPressed(keyboard.V); }
		bool W() { return keyboard.isKeyPressed(keyboard.W); }
		bool X() { return keyboard.isKeyPressed(keyboard.X); }
		bool Y() { return keyboard.isKeyPressed(keyboard.Y); }
		bool Z() { return keyboard.isKeyPressed(keyboard.Z); }
		bool Num0() { return keyboard.isKeyPressed(keyboard.Num0); }
		bool Num1() { return keyboard.isKeyPressed(keyboard.Num1); }
		bool Num2() { return keyboard.isKeyPressed(keyboard.Num2); }
		bool Num3() { return keyboard.isKeyPressed(keyboard.Num3); }
		bool Num4() { return keyboard.isKeyPressed(keyboard.Num4); }
		bool Num5() { return keyboard.isKeyPressed(keyboard.Num5); }
		bool Num6() { return keyboard.isKeyPressed(keyboard.Num6); }
		bool Num7() { return keyboard.isKeyPressed(keyboard.Num7); }
		bool Num8() { return keyboard.isKeyPressed(keyboard.Num8); }
		bool Num9() { return keyboard.isKeyPressed(keyboard.Num9); }
		bool Escape() { return keyboard.isKeyPressed(keyboard.Escape); }
		bool LControl() { return keyboard.isKeyPressed(keyboard.LControl); }
		bool LShift() { return keyboard.isKeyPressed(keyboard.LShift); }
		bool LSystem() { return keyboard.isKeyPressed(keyboard.LSystem); }
		bool LAlt() { return keyboard.isKeyPressed(keyboard.LAlt); }
		bool RControl() { return keyboard.isKeyPressed(keyboard.RControl); }
		bool RShift() { return keyboard.isKeyPressed(keyboard.RShift); }
		bool RAlt() { return keyboard.isKeyPressed(keyboard.RAlt); }
		bool RSystem() { return keyboard.isKeyPressed(keyboard.RSystem); }
		bool Menu() { return keyboard.isKeyPressed(keyboard.Menu); }
		bool LBarcket() { return keyboard.isKeyPressed(keyboard.LBracket); }
		bool RBarcket() { return keyboard.isKeyPressed(keyboard.RBracket); }
		bool SemiColon() { return keyboard.isKeyPressed(keyboard.SemiColon); }
		bool Comma() { return keyboard.isKeyPressed(keyboard.Comma); }
		bool Period() { return keyboard.isKeyPressed(keyboard.Period); }
		bool Quote() { return keyboard.isKeyPressed(keyboard.Quote); }
		bool Slash() { return keyboard.isKeyPressed(keyboard.Slash); }
		bool BackSlash() { return keyboard.isKeyPressed(keyboard.BackSlash); }
		bool Tab() { return keyboard.isKeyPressed(keyboard.Tab); }
		bool PageUp() { return keyboard.isKeyPressed(keyboard.PageUp); }
		bool PageDown() { return keyboard.isKeyPressed(keyboard.PageDown); }
		bool End() { return keyboard.isKeyPressed(keyboard.End); }
		bool Home() { return keyboard.isKeyPressed(keyboard.Home); }
		bool Insert() { return keyboard.isKeyPressed(keyboard.Insert); }
		bool Delete() { return keyboard.isKeyPressed(keyboard.Delete); }
		bool Add() { return keyboard.isKeyPressed(keyboard.Add); }
		bool Subtract() { return keyboard.isKeyPressed(keyboard.Subtract); }
		bool Multiply() { return keyboard.isKeyPressed(keyboard.Multiply); }
		bool Divide() { return keyboard.isKeyPressed(keyboard.Divide); }
		bool Left() { return keyboard.isKeyPressed(keyboard.Left); }
		bool Right() { return keyboard.isKeyPressed(keyboard.Right); }
		bool Up() { return keyboard.isKeyPressed(keyboard.Up); }
		bool Down() { return keyboard.isKeyPressed(keyboard.Down); }
		bool Numpad0() { return keyboard.isKeyPressed(keyboard.Numpad0); }
		bool Numpad1() { return keyboard.isKeyPressed(keyboard.Numpad1); }
		bool Numpad2() { return keyboard.isKeyPressed(keyboard.Numpad2); }
		bool Numpad3() { return keyboard.isKeyPressed(keyboard.Numpad3); }
		bool Numpad4() { return keyboard.isKeyPressed(keyboard.Numpad4); }
		bool Numpad5() { return keyboard.isKeyPressed(keyboard.Numpad5); }
		bool Numpad6() { return keyboard.isKeyPressed(keyboard.Numpad6); }
		bool Numpad7() { return keyboard.isKeyPressed(keyboard.Numpad7); }
		bool Numpad8() { return keyboard.isKeyPressed(keyboard.Numpad8); }
		bool Numpad9() { return keyboard.isKeyPressed(keyboard.Numpad9); }
		bool F1() { return keyboard.isKeyPressed(keyboard.F1); }
		bool F2() { return keyboard.isKeyPressed(keyboard.F2); }
		bool F3() { return keyboard.isKeyPressed(keyboard.F3); }
		bool F4() { return keyboard.isKeyPressed(keyboard.F4); }
		bool F5() { return keyboard.isKeyPressed(keyboard.F5); }
		bool F6() { return keyboard.isKeyPressed(keyboard.F6); }
		bool F7() { return keyboard.isKeyPressed(keyboard.F7); }
		bool F8() { return keyboard.isKeyPressed(keyboard.F8); }
		bool F9() { return keyboard.isKeyPressed(keyboard.F9); }
		bool F10() { return keyboard.isKeyPressed(keyboard.F10); }
		bool F11() { return keyboard.isKeyPressed(keyboard.F11); }
		bool F12() { return keyboard.isKeyPressed(keyboard.F12); }
		bool F13() { return keyboard.isKeyPressed(keyboard.F13); }
		bool F14() { return keyboard.isKeyPressed(keyboard.F14); }
		bool F15() { return keyboard.isKeyPressed(keyboard.F15); }
		bool Pause() { return keyboard.isKeyPressed(keyboard.Pause); }



		
	};
}

#endif