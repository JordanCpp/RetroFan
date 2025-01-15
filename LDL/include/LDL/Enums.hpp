/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef LDL_Enums_hpp
#define LDL_Enums_hpp

namespace LDL
{
	class KeyboardKey
	{
	public:
		enum
		{
			Unknown = 1,
			LSystem,
			RSystem,
			Menu,
			Semicolon,
			Slash,
			Equal,
			Hyphen,
			LBracket,
			RBracket,
			Comma,
			Period,
			Quote,
			Backslash,
			Tilde,
			Escape,
			Space,
			Enter,
			Backspace,
			Tab,
			PageUp,
			PageDown,
			End,
			Home,
			Insert,
			Delete,
			Add,
			Subtract,
			Multiply,
			Divide,
			Pause,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F15,
			Left,
			Right,
			Up,
			Down,
			Numpad0,
			Numpad1,
			Numpad2,
			Numpad3,
			Numpad4,
			Numpad5,
			Numpad6,
			Numpad7,
			Numpad8,
			Numpad9,
			A,
			Z,
			E,
			R,
			T,
			Y,
			U,
			I,
			O,
			P,
			Q,
			S,
			D,
			F,
			G,
			H,
			J,
			K,
			L,
			M,
			W,
			X,
			C,
			V,
			B,
			N,
			Num0,
			Num1,
			Num2,
			Num3,
			Num4,
			Num5,
			Num6,
			Num7,
			Num8,
			Num9,
			Leftshift,
			RightShift,
			LeftControl,
			RightControl
		};
	};

	class ButtonState
	{
	public:
		enum
		{
			Pressed = 1,
			Released
		};
	};

	class MouseButton
	{
	public:
		enum
		{
			Left = 1,
			Right,
			Middle
		};
	};

	class MouseScroll
	{
	public:
		enum
		{
			Vertical = 1,
			Horizontal
		};
	};

	class WindowMode
	{
	public:
		enum
		{
			Resized = 1,
			Fixed,
			FullScreen
		};
	};
}

#endif