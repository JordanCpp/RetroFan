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

#include <string.h>
#include <assert.h>
#include <LDL/Win16/GdiPRndr.hpp>
#include <LDL/Win16/GdiUtils.hpp>

using namespace LDL;

GdiPaletteRender::GdiPaletteRender(Result& result, MainWindow& window) :
	_window(window),
	_activePalette(NULL),
	_hdcm(NULL),
	_result(result)
{
}

GdiPaletteRender::GdiPaletteRender(Result& result, MainWindow& window, const Palette& palette) :
	_window(window),
	_palette(palette),
	_hdcm(NULL),
	_result(result)
{
	GdiPalette gdiPalette;
	GdiFill(gdiPalette, _palette);

	_activePalette = CreatePalette(&gdiPalette.logPalette);

	if (_activePalette == NULL)
	{
		_result.Message(_windowError.GetErrorMessage());
	}
}

GdiPaletteRender::~GdiPaletteRender()
{
}

const Palette& GdiPaletteRender::GetPalette()
{
	return _palette;
}

const Color& GdiPaletteRender::GetColor()
{
	return _baseRender.GetColor();
}

void GdiPaletteRender::SetColor(uint8_t index)
{
	return _baseRender.SetColor(index);
}
void GdiPaletteRender::SetColor(const Color& color)
{
	_baseRender.SetColor(color);
}

void GdiPaletteRender::Begin()
{
	InvalidateRect(_window.Hwnd(), NULL, FALSE);
	
	_hdcm = CreateCompatibleDC(_window.Hdc());
	
	if (_hdcm == NULL)
	{
		_result.Message(_windowError.GetErrorMessage());
	}
}

void GdiPaletteRender::End()
{
	if (DeleteDC(_hdcm) == FALSE)
	{
		_result.Message(_windowError.GetErrorMessage());
	}
}

void GdiPaletteRender::Clear()
{
	Fill(Vec2i(0, 0), _window.Size());
}

void GdiPaletteRender::Line(const Vec2i& first, const Vec2i& last)
{
	GdiLine(_result, _windowError, _window.Hdc(), first, last, 0);
}

void GdiPaletteRender::Fill(const Vec2i& pos, const Vec2i& size)
{
	GdiFill(_window.Hdc(), pos, size, _activePalette, _baseRender.GetIndex());
}

void GdiPaletteRender::Draw(GdiPaletteTexture* texture, const Vec2i& dstPos, const Vec2i& dstSize, const Vec2i& srcPos, const Vec2i& srcSize)
{
	assert(texture != NULL);
	assert(dstPos.x >= 0);
	assert(dstPos.y >= 0);
	assert(dstSize.x > 0);
	assert(dstSize.y > 0);
	assert(srcPos.x >= 0);
	assert(srcPos.y >= 0);
	assert(srcSize.x > 0);
	assert(srcSize.y > 0);

	HGDIOBJ object = SelectObject(_hdcm, texture->Bitmap());

	if (object == NULL)
	{
		_result.Message(_windowError.GetErrorMessage());
	}
	else
	{
		if (StretchBlt(_window.Hdc(), dstPos.x, dstPos.y, dstSize.x, dstSize.y, _hdcm, srcPos.x, srcPos.y, srcSize.x, srcSize.y, SRCCOPY) == FALSE)
		{
			_result.Message(_windowError.GetErrorMessage());
		}
	}
}

void GdiPaletteRender::Draw(GdiPaletteTexture* texture, const Vec2i& pos)
{
	Draw(texture, pos, texture->Size(), Vec2i(0, 0), texture->Size());
}

void GdiPaletteRender::Draw(GdiPaletteTexture* texture, const Vec2i& pos, const Vec2i& size)
{
	Draw(texture, pos, size, Vec2i(0, 0), texture->Size());
}

const HDC GdiPaletteRender::Hdc()
{
	return _window.Hdc();
}
