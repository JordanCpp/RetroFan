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

#ifndef LDL_Renders_BufTex_hpp
#define LDL_Renders_BufTex_hpp

#include <LDL/Result.hpp>
#include <LDL/Surface.hpp>
#include <LDL/ColorKey.hpp>

namespace LDL
{
	class BufferRender;

	class BufferTexture
	{
	public:
		BufferTexture(Result& result, BufferRender& render, const Vec2i& size, uint8_t bpp, uint8_t* pixels);
		BufferTexture(Result& result, BufferRender& render, const Vec2i& size, uint8_t bpp, uint8_t* pixels, const Color& color);
		BufferTexture(Result& result, BufferRender& render, const Vec2i& size, uint8_t* pixels);
		~BufferTexture();
		const ColorKey& GetColorKey() const;
		const Vec2i& Size();
	private:
		Result&       _result;
		BufferRender& _render;
		Vec2i         _size;
		Surface       _surface;
		ColorKey      _colorKey;
	};
}

#endif
