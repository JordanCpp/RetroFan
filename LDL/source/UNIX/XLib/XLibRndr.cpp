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

#include <LDL/UNIX/XLib/XLibRndr.hpp>

using namespace LDL;

inline uint32_t MakeRgb(uint8_t r, uint8_t g, uint8_t b)
{
    return b + (g <<8 ) + (r << 16);
}

XLibRender::XLibRender(Result& result, XLibWindow& window) :
	_window(window),
	_result(result)
{
	_graphics = XCreateGC(_window.GetXDisplay(), _window.GetXWindow(), GCForeground | GCBackground, &_values);
	_depth    = XDefaultDepth(_window.GetXDisplay(), _window.GetXScreen());
	_visual   = XDefaultVisual(_window.GetXDisplay(), _window.GetXScreen());
}

XLibRender::XLibRender(Result& result, XLibWindow& window, const Palette& palette) :
	_window(window),
	_result(result),
	_palette(palette)
{
	_graphics = XCreateGC(_window.GetXDisplay(), _window.GetXWindow(), GCForeground | GCBackground, &_values);
	_depth    = XDefaultDepth(_window.GetXDisplay(), _window.GetXScreen());
	_visual   = XDefaultVisual(_window.GetXDisplay(), _window.GetXScreen());
}

XLibRender::~XLibRender()
{
	XFreeGC(_window.GetXDisplay(), _graphics);
}

const Color& XLibRender::GetColor()
{
	return _baseRender.GetColor();
}

void XLibRender::SetColor(const Color& color)
{
	_baseRender.SetColor(color);
}

void XLibRender::Begin()
{
}

void XLibRender::End()
{
	XSync(_window.GetXDisplay(), True);
	XFlush(_window.GetXDisplay());
}

void XLibRender::Clear()
{
}

void XLibRender::Line(const Vec2i& first, const Vec2i& last)
{
	uint32_t rgb = MakeRgb(_baseRender.GetColor().r, _baseRender.GetColor().g, _baseRender.GetColor().b);

	XSetForeground(_window.GetXDisplay(), _graphics, rgb);
	XDrawLine(_window.GetXDisplay(), _window.GetXWindow(), _graphics, first.x, first.y, last.x, last.y);
}

void XLibRender::Fill(const Vec2i& pos, const Vec2i& size)
{
	uint32_t rgb = MakeRgb(_baseRender.GetColor().r, _baseRender.GetColor().g, _baseRender.GetColor().b);

	XSetForeground(_window.GetXDisplay(), _graphics, rgb);
	XFillRectangle(_window.GetXDisplay(), _window.GetXWindow(), _graphics, pos.x, pos.y, size.x, size.y);
}

void XLibRender::Draw(XLibTexture* texture, const Vec2i& dstPos, const Vec2i& dstSize, const Vec2i& srcPos, const Vec2i& srcSize)
{
}

void XLibRender::Draw(XLibTexture* texture, const Vec2i& pos)
{
}

void XLibRender::Draw(XLibTexture* texture, const Vec2i& pos, const Vec2i& size)
{
	int error = XPutImage(_window.GetXDisplay(), _window.GetXWindow(), _graphics, texture->GetImage(), 0, 0, 0, 0, size.x, size.y);
}

Display* XLibRender::GetXDisplay()
{
    return _window.GetXDisplay();
}

Visual* XLibRender::GetXVisual()
{
    return _visual;
}

int XLibRender::GetXDepth()
{
    return _depth;
}
