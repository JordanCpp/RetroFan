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

#define LDL_RENDER_NATIVE_PALETTE
#include <LDL/LDL.hpp>
#include <stdio.h>

int main()
{
	LDL::Palette palette;

	palette.Set(0, LDL::Color(0, 0, 0));
	palette.Set(1, LDL::Color(255, 255, 255));
	palette.Set(2, LDL::Color(255, 0, 0));
	palette.Set(3, LDL::Color(0, 255, 0));
	palette.Set(4, LDL::Color(0, 0, 255));
	palette.Set(5, LDL::Color(255, 255, 0));
	palette.Set(6, LDL::Color(0, 255, 255));

	LDL::Result result;
	LDL::Window window(result, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600));
	LDL::Render render(result, window, palette);

	LDL::Event report;

	const size_t imgSize = 100 * 100;

	uint8_t* img8 = new uint8_t[imgSize];
	memset(img8, 5, imgSize);

	LDL::Texture img(result, &render, LDL::Vec2i(100, 100), img8);

	while (window.Running())
	{
		while (window.GetEvent(report))
		{
			if (report.Type == LDL::Event::IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.SetColor(4);
		render.Fill(LDL::Vec2i(25, 25), LDL::Vec2i(100, 100));

		render.Draw(&img, LDL::Vec2i(0, 0));
		render.Draw(&img, LDL::Vec2i(150, 150));

		render.End();

		window.Update();
		window.PollEvents();
	}

	return 0;
}
