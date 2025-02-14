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

#include <Windows.h>
#include <string.h>
#include <string>
#include <stdlib.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch (msg)
    {

    case WM_DESTROY:
    {
        PostQuitMessage(0);
    }
    break;

    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int random(unsigned int min, unsigned int max)
{
    return rand() % ((max + min) + min);
}

int main()
{
    MSG         message;
    HWND        handleWindow;
    HDC         handleDeviceContext;
    WNDCLASSA   windowClass;
    PAINTSTRUCT paintStruct;
    std::string title = "Hello Habr!";

    memset(&windowClass, 0, sizeof(WNDCLASSA));

    windowClass.style         = CS_HREDRAW | CS_VREDRAW;
    windowClass.cbClsExtra    = 0;
    windowClass.cbWndExtra    = 0;
    windowClass.lpszClassName = "Window";
    windowClass.hInstance     = GetModuleHandle(NULL);
    windowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
    windowClass.lpszMenuName  = NULL;
    windowClass.lpfnWndProc   = WndProc;

    RegisterClass(&windowClass);
    handleWindow = CreateWindow(windowClass.lpszClassName, title.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 800, 600, NULL, NULL, windowClass.hInstance, NULL);

    handleDeviceContext = BeginPaint(handleWindow, &paintStruct);

    for (size_t i = 0; i < 100; i++)
    {
        MoveToEx(handleDeviceContext, 0, 0, NULL);
        LineTo(handleDeviceContext, random(0, 600), random(0, 800));
    }

    for (size_t i = 0; i < 500; i++)
    {
        RECT rect;
        rect.left   = random(0, 800);
        rect.top    = random(0, 600);
        rect.right  = random(25, 50);
        rect.bottom = random(25, 50);

        HBRUSH brush = CreateSolidBrush(RGB(random(0, 255), random(0, 255), random(0, 255)));

        FillRect(handleDeviceContext, &rect, brush);

        DeleteObject(brush);
    }

    EndPaint(handleWindow, &paintStruct);

    ShowWindow(handleWindow, SW_SHOW);
    UpdateWindow(handleWindow);

    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}
