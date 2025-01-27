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

#include <LDL/UNIX/MainWin.hpp>
#include <string.h>

using namespace LDL;

const size_t eventMask =
    PointerMotionMask
  | ButtonMotionMask
  | ButtonPressMask
  | ButtonReleaseMask
  | KeyPressMask
  | KeyReleaseMask;

MainWindow::MainWindow(const Vec2i& pos, const Vec2i& size) :
    _pos(pos),
    _size(size),
	_eventMask(eventMask)
{	
	_display = XOpenDisplay(NULL);
	_screen  = DefaultScreen(_display);
	_root    = RootWindow(_display, _screen);
    _window  = XCreateSimpleWindow(_display, RootWindow(_display, _screen), pos.x, pos.y, size.x, size.y, 1, BlackPixel(_display, _screen), WhitePixel(_display, _screen));

    XMapWindow(_display, _window);
}

MainWindow::~MainWindow()
{
    XCloseDisplay(_display);
}

void MainWindow::Update()
{
	//XClearWindow(_display, _window);
	//XMapRaised(_display, _window);
}

void MainWindow::StopEvent()
{
	_eventer.Stop();
}

bool MainWindow::Running()
{
	return _eventer.Running();
}

void MainWindow::PollEvents()
{
	XEvent event;
	size_t key = 0;

	while (XPending(_display))
	{
		XNextEvent(_display, &event);
	}
}

bool MainWindow::GetEvent(Event& event)
{
	if (!_eventer.Empty())
	{
		_eventer.Pop(event);

		return true;
	}

	return false;
}
