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

#include <LDL/LDL.hpp>

#if (_MSC_VER <= 1200) || (_WIN16)
    #define STBI_NO_THREAD_LOCALS
    #define STBI_NO_SIMD
#endif

#if (_MSC_VER <= 1200) || (_WIN16)
#define STBI_NO_THREAD_LOCALS
#define STBI_NO_SIMD
#endif

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
	LDL::Result result;
	LDL::Window window(result, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600));
	LDL::Render render(result, window);
    LDL::Event  report;

	int width       = 0;
	int height      = 0;
	int channels    = 0;
	uint8_t* pixels = NULL;

	stbi_set_flip_vertically_on_load(true);
	pixels = stbi_load("img24.bmp", &width, &height, &channels, STBI_default);
	LDL::Texture texture(result, render, LDL::Vec2i(width, height), channels, pixels);
	stbi_image_free(pixels);

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

		render.Draw(&texture, LDL::Vec2i(0, 0), window.Size());

		render.End();

		window.Update();
		window.PollEvents();
	}

    return 0;
}
