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

#ifndef LDL_Windows_GdiUtils_hpp
#define LDL_Windows_GdiUtils_hpp

#include <stdint.h>
#include <LDL/Windows/Win32.hpp>
#include <LDL/Windows/WinError.hpp>
#include <LDL/Result.hpp>
#include <LDL/Vec2.hpp>
#include <LDL/Palette.hpp>

namespace LDL
{
    struct GdiPalette
    {
        LOGPALETTE   logPalette;
        PALETTEENTRY paletteEntry[Palette::Max];
    };

    struct GdiBitmapPalette
    {
        BITMAPINFOHEADER header;
        RGBQUAD color[Palette::Max];
    };

    HBITMAP CreateDib(HDC hdc, const Vec2i& size, uint8_t bpp, void** pixels);
    HBITMAP CreateDib(HDC hdc, const Vec2i& size, const Palette& palette, void** pixels);

    void DestroyDib(HBITMAP bitmap);
   
    void GdiFill(GdiPalette& dst, const Palette& src);

    void GdiFill(HDC hdc, const Vec2i& pos, const Vec2i& size, const Color& color);
    void GdiFill(HDC hdc, const Vec2i& pos, const Vec2i& size, HPALETTE palette, uint8_t index);
    
    void GdiLine(HDC hdc, const Vec2i& first, const Vec2i& last, const Color& color);
    void GdiLine(HDC hdc, const Vec2i& first, const Vec2i& last, uint8_t index);

    void GdiLine(Result& result, WindowError& winError, HDC hdc, const Vec2i& first, const Vec2i& last, uint8_t index);
}

#endif
